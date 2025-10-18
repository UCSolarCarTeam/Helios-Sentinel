import QtQuick.Studio.Components
import QtQuick 2.15
import QtQuick.Controls 6.2

import "Components" 1.0
import "PacketViews" 1.0

Item {
    id: toolWin
    width: 575
    height: 700
    z: -2

    property int selectedButton: 8

    Row {
        id: row
        x: 0
        y: selectedButton <= 4 ? 35 : 0
        height: 35
        z:20
        TabBtn {
            id: button
            buttonText: qsTr("Key Motor")
            isSelected: selectedButton === 0
            onClicked: selectedButton = 0
        }

        TabBtn {
            id: button1
            buttonText: qsTr("Motor Details")
            isSelected: selectedButton === 1
            onClicked: selectedButton = 1
        }

        TabBtn {
            id: button2
            buttonText: qsTr("B^3")
            isSelected: selectedButton === 2
            onClicked: selectedButton = 2
        }

        TabBtn {
            id: button3
            buttonText: qsTr("Telemetry")
            isSelected: selectedButton === 3
            onClicked: selectedButton = 3
        }

        TabBtn {
            id: button4
            buttonText: qsTr("Battery Faults")
            isSelected: selectedButton === 4
            onClicked: selectedButton = 4
        }
    }

    Row {
        id: row1
        x: 0
        y: selectedButton > 4 ? 35 : 0
        height: 35
        z: 20
        TabBtn {
            id: button5
            buttonText: qsTr("Battery")
            isSelected: selectedButton === 5
            onClicked: selectedButton = 5
        }

        TabBtn {
            id: button6
            buttonText: qsTr("MPPT")
            isSelected: selectedButton === 6
            onClicked: selectedButton = 6
        }

        TabBtn {
            id: button7
            buttonText: qsTr("MBMS")
            isSelected: selectedButton === 7
            onClicked: selectedButton = 7
        }

        TabBtn {
            id: button8
            buttonText: qsTr("Proximity Sensors")
            isSelected: selectedButton === 8
            onClicked: selectedButton = 8
        }
        TabBtn {
            id: button9
            buttonText: qsTr("Contactors")
            isSelected: selectedButton === 9
            onClicked: selectedButton = 9
        }
        Rectangle{
            width: 2
            height: 33
            color: "transparent"
        }

        Rectangle {
            width: 36
            height: 34
            color: "black"
            radius: 10
            Image {
                source: "images/solarCarLogo.png"
                anchors.verticalCenterOffset: 1
                anchors.centerIn: parent
                width: 21
                height: 25
            }
        }
    }

    ScrollView{
        width: parent.width
        height: 600
        z:100
        y: 75

        Loader {
            id: contentLoader
            x: 10
            z:100
            width: parent.width - 20
            sourceComponent: selectedButton === 0 ? keyMotorView : 
                                selectedButton === 1 ? motorDetailsView : 
                                selectedButton === 2 ? b3View :
                                selectedButton === 3 ? telemetryView :
                                selectedButton === 4 ? batteryFaultsView :
                                selectedButton === 5 ? batteryView :
                                selectedButton === 6 ? mpptView :
                                selectedButton === 7 ? mbmsView :
                                selectedButton === 8 ? proximitySensorsView :
                                selectedButton === 9 ? contactorsView : null
        }

        Component {
            id: keyMotorView
            KeyMotorView{}
        }

        Component {
            id: motorDetailsView
            MotorDetailsView{}
        }

        Component {
            id: b3View
            B3View{}
        }

        Component {
            id: telemetryView
            TelemetryView{}
        }

        Component {
            id: contactorsView
            ContactorsView{}
        }

        Component {
            id: batteryFaultsView
            BatteryFaultsView{}
        }

        Component {
            id: batteryView
            BatteryView{}
        }

        Component {
            id: mpptView
            MpptView{}
        }

        Component {
            id: mbmsView
            MbmsView{}
        }

        Component {
            id: proximitySensorsView
            ProximitySensorsView{}
        }
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 68
        width: 575
        height: 1000
        color: "#A9A9A9"
        border.color: "black"
        border.width: 2
    }
}
