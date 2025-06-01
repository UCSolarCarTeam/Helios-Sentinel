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
