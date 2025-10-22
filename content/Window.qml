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
    property var menuModel: [
        { title: "Key Motor", icon: "../images/KeyMotorIcon.png"},
        { title: "Motor Details", icon: "../images/MotorIcon.png"},
        { title: "B^3", icon: "../images/B3Icon.png"},
        { title: "Telemetry", icon: "../images/TelemetryIcon.png"},
        { title: "Battery Faults", icon: "../images/BatteryFaultsIcon.png"},
        { title: "Battery", icon: "../images/BatteryIcon.png"},
        { title: "MPPT", icon: "../images/MpptIcon.png"},
        { title: "MBMS", icon: "../images/MbmsIcon.png"},
        {
            title: "Proximity Sensors",
            icon: "../images/ProximityIcon.png",
            fields: [
                {
                    name: "Sensor 1",
                    units: "cm",
                    getter: function() { return proximitySensors.ProximitySensor1 },
                    setter: function(v) { proximitySensors.setProximitySensor1(v) }
                }
            ]
        },
        { title: "Contactors", icon: "../images/ContactorsIcon.png" }
    ]

    SideMenu {
        id: menu
        menuModel: win.menuModel
        activeMenuItem: win.activeMenuItem
        onActiveMenuItemChanged: win.activeMenuItem = activeMenuItem
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
    }

    Header {
        activePacket: win.activeMenuItem
        anchors {
            left: menu.right
            right: win.right
        }
    }

    Repeater {
        model: win.menuModel[8].fields
        Column {
            Text{
                text: modelData.name + ": " + modelData.getter()
                color: "red"
            }

            Button {
                text: "Increase"
                onClicked: {
                    modelData.setter(modelData.getter() + 1)
                }
            }
        }
    }
}
