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
#include "KeyMotor.h"
#include "MotorDetails.h"
#include "B3.h"
#include "Telemetry.h"
#include "BatteryFaults.h"
#include "Battery.h"
#include "Mppt.h"
#include "Mbms.h"
#include "ProximitySensors.h"

int main(int argc, char *argv[])
{

    /*************************************************
        SET PORT HERE
    */
    SerialPortForwarder forwarder("/dev/pts/1");

    /*************************************************/

    set_qt_environment();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    KeyMotor keyMotor;
    engine.rootContext()->setContextProperty("keyMotor", &keyMotor);

    MotorDetails m0(0);
    MotorDetails m1(1);
    engine.rootContext()->setContextProperty("motorDetails0", &m0);
    engine.rootContext()->setContextProperty("motorDetails1", &m1);

    B3 b3;
    engine.rootContext()->setContextProperty("b3", &b3);

    Telemetry telemetry;
    engine.rootContext()->setContextProperty("telemetry", &telemetry);

    BatteryFaults batteryFaults;
    engine.rootContext()->setContextProperty("batteryFaults", &batteryFaults);

    Battery battery;
    engine.rootContext()->setContextProperty("battery", &battery);

    Mppt mppt0(0);
    Mppt mppt1(1);
    Mppt mppt2(2);
    Mppt mppt3(3);
    engine.rootContext()->setContextProperty("mppt0", &mppt0);
    engine.rootContext()->setContextProperty("mppt1", &mppt1);
    engine.rootContext()->setContextProperty("mppt2", &mppt2);
    engine.rootContext()->setContextProperty("mppt3", &mppt3);

    Mbms mbms;
    engine.rootContext()->setContextProperty("mbms", &mbms);

    ProximitySensors proximitySensors;
    engine.rootContext()->setContextProperty("proximitySensors", &proximitySensors);

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

    QObject::connect(&timer, &QTimer::timeout, [&forwarder, &keyMotor, &m0, &m1, &b3, &telemetry, &batteryFaults, &battery, &mppt0, &mppt1, &mppt2, &mppt3, &mbms, &proximitySensors]() {
        // Packet rotation subject to change
        forwarder.forwardData(keyMotor.encodedByteStream());
        forwarder.forwardData(b3.encodedByteStream());
        forwarder.forwardData(telemetry.encodedByteStream());
        forwarder.forwardData(batteryFaults.encodedByteStream());
        forwarder.forwardData(mbms.encodedByteStream());
        forwarder.forwardData(proximitySensors.encodedByteStream());
        forwarder.forwardData(battery.encodedByteStream());
        forwarder.forwardData(m1.encodedByteStream());
        forwarder.forwardData(mppt2.encodedByteStream());
        forwarder.forwardData(mppt3.encodedByteStream());
        forwarder.forwardData(m0.encodedByteStream());
        forwarder.forwardData(mppt0.encodedByteStream());
        forwarder.forwardData(mppt1.encodedByteStream());
    });
    timer.start(500);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
