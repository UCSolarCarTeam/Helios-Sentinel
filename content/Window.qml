import QtQuick.Studio.Components
import QtQuick 2.15
import QtQuick.Controls 6.2

import "Components" 1.0
import "Components/MenuModel.js" as MenuModel

Rectangle {
    id: win
    width: 900
    height: 900
    z: -20
    color: "#f6f9fb"

    property var menuModel: MenuModel.menuModel
    property string activeMenuItem: menuModel[0].title
    property var fields: menuModel[0].fields
    property var activePacket

    onActiveMenuItemChanged: {
        switch (activeMenuItem) {
            case "Key Motor":
                activePacket = keyMotor; break;
            case "Motor 0":
                activePacket = motorDetails0; break;
            case "Motor 1":
                activePacket = motorDetails1; break;
            case "B^3":
                activePacket = b3; break;
            case "Telemetry":
                activePacket = telemetry; break;
            case "Battery Faults":
                activePacket = batteryFaults; break;
            case "Battery":
                activePacket = battery; break;
            case "MPPT 0 Channel 0":
                activePacket = mppt0C0; break;
            case "MPPT 0 Channel 1":
                activePacket = mppt0C1; break;
            case "MPPT 1 Channel 0":
                activePacket = mppt1C0; break;
            case "MPPT 1 Channel 1":
                activePacket = mppt1C1; break;
            case "MPPT 2 Channel 0":
                activePacket = mppt2C0; break;
            case "MPPT 2 Channel 1":
                activePacket = mppt2C1; break;
            case "MPPT 3 Channel 0":
                activePacket = mppt3C0; break;
            case "MPPT 3 Channel 1":
                activePacket = mppt3C1; break;
            case "Proximity Sensors":
                activePacket = proximitySensors; break;
            case "Contactors":
                activePacket = contactors; break;
            case "MBMS":
                activePacket = mbms; break;
        }
        var item = menuModel.find(function(obj) { return obj.title === activeMenuItem })
        fields = item ? item.fields : []
    }

    SideMenu {
        id: menu
        z:3
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
        id: header
        z:2
        activePacket: win.activeMenuItem
        anchors {
            left: menu.right
            right: win.right
        }
    }

    ScrollView {
        anchors {
            left: menu.right
            top: header.bottom
            right: win.right
            bottom: win.bottom
            leftMargin: 24
            rightMargin: 24
            topMargin: 24
        }

        ScrollBar.vertical.policy: ScrollBar.AlwaysOff

        Flickable {
            id: flick
            contentWidth: width
            contentHeight: pageContent.height
            clip: true

            PageContent {
                z: 1
                id: pageContent
                fields: win.fields
                packet: win.activePacket
            }
        }
    }


}
