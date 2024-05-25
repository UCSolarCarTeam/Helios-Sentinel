

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.2
import QtQuick.Controls 6.2
import ViscommTester
import QtQuick.Studio.Components 1.0
import QtQuick.Layouts

Rectangle {
    id: rectangle
    width: Screen.width
    height: Screen.height

    color: Constants.backgroundColor
    z: -2
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
                id: discoverTab
            }
            Item {
                id: ddd
            }
        }
    }



    // LightsView {
    //     id: lightsView
    //     x: 0
    //     y: 0
    // }

    // DriverControlsView {
    //     id: driverControlsView
    //     x: 0
    //     y: 200
    // }

    // BatteryFaultsView {
    //     id: batteryFaultsView
    //     x: 886
    //     y: 0
    // }

    states: [
        State {
            name: "clicked"
            when: button.checked
        }
    ]
}
