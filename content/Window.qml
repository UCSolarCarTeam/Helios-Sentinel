import QtQuick.Studio.Components
import QtQuick 2.15
import QtQuick.Controls 6.2

import "Components" 1.0
import "PacketViews" 1.0

Rectangle {
    id: win
    width: 900
    height: 900
    z: -20
    color: "#f6f9fb"

    property string activeMenuItem: "Key Motor"

    SideMenu {
        id: menu
        itemList: menuModel
        activeMenuItem: win.activeMenuItem
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
    }

    Header {
        anchors {
            left: menu.right
            right: win.right
        }
    }

    ListModel {
        id: menuModel
        ListElement {icon: "../images/KeyMotorIcon.png"; title: "Key Motor" }
        ListElement {icon: "../images/MotorIcon.png"; title: "Motor Details" }
        ListElement {icon: "../images/B3Icon.png"; title: "B^3" }
        ListElement {icon: "../images/TelemetryIcon.png"; title: "Telemetry" }
        ListElement {icon: "../images/BatteryFaultsIcon.png"; title: "Battery Faults" }
        ListElement {icon: "../images/BatteryIcon.png"; title: "Battery" }
        ListElement {icon: "../images/MpptIcon.png"; title: "MPPT" }
        ListElement {icon: "../images/MbmsIcon.png"; title: "MBMS" }
        ListElement {icon: "../images/ProximityIcon.png"; title: "Proximity Sensors" }
        ListElement {icon: "../images/ContactorsIcon.png"; title: "Contactors" }
    }
}
