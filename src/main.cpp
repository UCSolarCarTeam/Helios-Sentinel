// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>

#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"

#include "./SerialPortForwarder.h"
#include "lights.h"
#include "DriverControls.h"
#include "BatteryFaults.h"
#include "MotorDetails.h"
#include "KeyMotor.h"
#include "Mppt.h"
#include "Battery.h"
#include "AuxBms.h"

int main(int argc, char *argv[])
{

    /*************************************************
        SET PORT HERE
    */
    SerialPortForwarder forwarder("/dev/pts/3");

    /*************************************************/

    set_qt_environment();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Lights lights;
    engine.rootContext()->setContextProperty("lights", &lights);

    DriverControls driverControls;
    engine.rootContext()->setContextProperty("driverControls", &driverControls);

    BatteryFaults batteryFaults;
    engine.rootContext()->setContextProperty("batteryFaults", &batteryFaults);

    MotorDetails m0(0);
    MotorDetails m1(1);
    engine.rootContext()->setContextProperty("motor0", &m0);
    engine.rootContext()->setContextProperty("motor1", &m1);

    KeyMotor keyMotor;
    engine.rootContext()->setContextProperty("keyMotor", &keyMotor);

    Mppt mppt0(0);
    Mppt mppt1(1);
    Mppt mppt2(2);
    Mppt mppt3(3);
    engine.rootContext()->setContextProperty("mppt0", &mppt0);
    engine.rootContext()->setContextProperty("mppt1", &mppt1);
    engine.rootContext()->setContextProperty("mppt2", &mppt2);
    engine.rootContext()->setContextProperty("mppt3", &mppt3);

    Battery battery;
    engine.rootContext()->setContextProperty("battery", &battery);

    AuxBms auxBms;
    engine.rootContext()->setContextProperty("bms", &auxBms);

    // const QUrl url(u"qrc:/qt/Serialqml/Main/main.qml"_qs);

    const QUrl url(QStringLiteral("qml/Main/main.qml"));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    QTimer timer;
    bool firstRun = true;
    int count = 0;

    QObject::connect(&timer, &QTimer::timeout, [&count, &forwarder, &lights, &driverControls, &batteryFaults, &keyMotor, &m0, &m1, &mppt0, &mppt1, &mppt2, &mppt3, &battery, &auxBms]() {
        forwarder.forwardData(keyMotor.encodedByteStream());
        forwarder.forwardData(lights.encodedByteStream());
        //TODO: MOTOR FAULTS HERE
        forwarder.forwardData(batteryFaults.encodedByteStream());
        forwarder.forwardData(driverControls.encodedByteStream());

        if(count % 2 == 0){
            forwarder.forwardData(battery.encodedByteStream());
            forwarder.forwardData(auxBms.encodedByteStream());
            forwarder.forwardData(m1.encodedByteStream());
            forwarder.forwardData(mppt2.encodedByteStream());
            forwarder.forwardData(mppt3.encodedByteStream());
            qDebug() << "Forwardered Package 2";
        } else{
            forwarder.forwardData(m0.encodedByteStream());
            forwarder.forwardData(mppt0.encodedByteStream());
            forwarder.forwardData(mppt1.encodedByteStream());
            qDebug() << "Forwardered Package 1";
        }

        count++;
    });
    timer.start(500);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
