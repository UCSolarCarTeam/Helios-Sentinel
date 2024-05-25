// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import QtQuick
import QtQuick.Controls 6.2
import ViscommTester
import QtQuick.Studio.Components 1.0
import QtQuick.Layouts
Window {
    width: Screen.width
    height: Screen.height

    visible: true
    title: "ViscommTester"

    ColumnLayout{
        TabBar {
            id: bar
            width: parent.width
            TabButton {
                text: qsTr("Battery Fault View")
                width: implicitWidth
            }
            TabButton {
                text: qsTr("Driver Control View")
                width: implicitWidth
            }
            TabButton {
                text: qsTr("Lights View")
                width: implicitWidth
            }
        }
        StackLayout {
            width: parent.width
            currentIndex: bar.currentIndex

            Item {
                Loader {
                              anchors.fill: parent
                              source: "BatteryFaultsView.qml"
                          }
            }
            Item {
                Loader {
                              anchors.fill: parent
                              source: "DriverControlsView.qml"
                          }
            }
            Item {
                Loader {
                              anchors.fill: parent
                              source: "LightsView.qml"
                          }
            }
        }
    }

    // Screen01 {
    //     id: mainScreen
    //     Text{
    //         text: mainScreen.width
    //     }
    // }

}

