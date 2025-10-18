// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCanBus>
#include <QCanBusDevice>

#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"

#include "Packets/ProximitySensors.h"
#include "Packets/Telemetry.h"
#include "Packets/B3.h"
#include "Packets/MotorDetails.h"
#include "Packets/Contactors.h"
#include "Packets/Battery.h"
#include "Packets/KeyMotor.h"
#include "Packets/Mppt.h"
#include "Packets/Mbms.h"
#include "Packets/BatteryFaults.h"

int main(int argc, char *argv[]){
    set_qt_environment();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QCanBus *canBus = QCanBus::instance();
    if (!canBus) {
        qWarning() << "QCanBus instance not found!";
        return -1;
    }

    QString interface = "vcan0";
    QCanBusDevice *canDevice = canBus->createDevice("socketcan", interface);
    if (!canDevice) {
        qWarning() << "Failed to create CAN device for interface" << interface;
        return -1;
    }

    if (!canDevice->connectDevice()) {
        qWarning() << "Failed to connect to CAN device on interface" << interface;
        delete canDevice;
        return -1;
    }

    qDebug() << "Connected to CAN device on interface" << interface;


    ProximitySensors proximitySensors(canDevice);
    engine.rootContext()->setContextProperty("proximitySensors", &proximitySensors);

    Telemetry telemetry(canDevice);
    engine.rootContext()->setContextProperty("telemetry", &telemetry);

    B3 b3(canDevice);
    engine.rootContext()->setContextProperty("b3", &b3);

    Contactors contactors(canDevice);
    engine.rootContext()->setContextProperty("contactors", &contactors);

    MotorDetails motorDetails0(canDevice, 0x00);
    MotorDetails motorDetails1(canDevice, 0x20);
    engine.rootContext()->setContextProperty("motorDetails0", &motorDetails0);
    engine.rootContext()->setContextProperty("motorDetails1", &motorDetails1);

    Battery battery(canDevice);
    engine.rootContext()->setContextProperty("battery", &battery);

    KeyMotor keyMotor(canDevice);
    engine.rootContext()->setContextProperty("keyMotor", &keyMotor);

    Mppt mppt0C0(canDevice, 0x00);
    Mppt mppt0C1(canDevice, 0x01);
    Mppt mppt1C0(canDevice, 0x02);
    Mppt mppt1C1(canDevice, 0x03);
    Mppt mppt2C0(canDevice, 0x04);
    Mppt mppt2C1(canDevice, 0x05);
    Mppt mppt3C0(canDevice, 0x06);
    Mppt mppt3C1(canDevice, 0x07);
    engine.rootContext()->setContextProperty("mppt0C0", &mppt0C0);
    engine.rootContext()->setContextProperty("mppt0C1", &mppt0C1);
    engine.rootContext()->setContextProperty("mppt1C0", &mppt1C0);
    engine.rootContext()->setContextProperty("mppt1C1", &mppt1C1);
    engine.rootContext()->setContextProperty("mppt2C0", &mppt2C0);
    engine.rootContext()->setContextProperty("mppt2C1", &mppt2C1);
    engine.rootContext()->setContextProperty("mppt3C0", &mppt3C0);
    engine.rootContext()->setContextProperty("mppt3C1", &mppt3C1);

    Mbms mbms(canDevice);
    engine.rootContext()->setContextProperty("mbms", &mbms);

    BatteryFaults batteryFaults(canDevice);
    engine.rootContext()->setContextProperty("batteryFaults", &batteryFaults);

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

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }


    return app.exec();
}
