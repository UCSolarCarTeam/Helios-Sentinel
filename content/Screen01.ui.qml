

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

    color: "#000000"

    z: -2

    TabBar {
        id: tabBar
        x: 0
        y: 0
        width: 379
        height: 48
        currentIndex: 0

        TabButton {
            id: lightsTab
            text: qsTr("Lights ")
        }

        TabButton {
            id: driverTab
            x: 0
            y: 0
            text: qsTr("Driver Controls")
        }

        TabButton {
            id: batteryTab
            text: qsTr("Battery Faults")
        }
    }

    StackLayout {
        id: stackLayout
        x: 8
        y: 54
        width: 1000
        height: 500
        rotation: 0
        currentIndex: tabBar.currentIndex

        LightsView {
            id: lightsView
        }

        DriverControlsView {
            id: driverControlsView
        }

        BatteryFaultsView {
            id: batteryFaultsView
        }
    }
    states: [
        State {
            name: "clicked"
            when: button.checked
        }
    ]
}
