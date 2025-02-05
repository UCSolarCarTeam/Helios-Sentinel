import QtQuick.Studio.Components
import QtQuick 2.15
import QtQuick.Controls 6.2
import "Elysia"
Item {
    id: toolWin
    width: 575
    height: 1065
    z: -2

    property int selectedButton: 9

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
            visible:!settings.isElysia
        }
        TabBtn {
            id:auxButton
            buttonText: qsTr("Aux Bms")
            isSelected: selectedButton == 0
            onClicked: selectedButton = 0
            visible:settings.isElysia
        }

        TabBtn {
            id: button1
            buttonText: qsTr("Motor Details")
            isSelected: selectedButton === 1
            onClicked: selectedButton = 1
            visible:!settings.isElysia
        }

        TabBtn {
            id:driverControlElysiaButton
            buttonText: qsTr("Driver Controls")
            isSelected: selectedButton == 1
            onClicked: selectedButton = 1
            visible:settings.isElysia
        }

        TabBtn {
            id: button2
            buttonText: qsTr("B^3")
            isSelected: selectedButton === 2
            onClicked: selectedButton = 2
            visible:!settings.isElysia
        }
        TabBtn {
            id: keyMotorElysiaButton
            buttonText: qsTr("Key Motor")
            isSelected: selectedButton === 2
            onClicked: selectedButton = 2
            visible:settings.isElysia
        }

        TabBtn {
            id: button3
            buttonText: qsTr("Telemetry")
            isSelected: selectedButton === 3
            onClicked: selectedButton = 3
            visible:!settings.isElysia
        }
        TabBtn {
            id:lightsElysiaButton
            buttonText: qsTr("Lights")
            isSelected: selectedButton === 3
            onClicked: selectedButton = 3
            visible:settings.isElysia
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
            visible:!settings.isElysia
        }

        TabBtn {
            id: motorDetailElysiaButton
            buttonText: qsTr("Motor Details")
            isSelected: selectedButton === 6
            onClicked: selectedButton = 6
            visible:settings.isElysia
        }

        TabBtn {
            id: button7
            buttonText: qsTr("MBMS")
            isSelected: selectedButton === 7
            onClicked: selectedButton = 7
            visible:!settings.isElysia
        }
        TabBtn {
            id: motorFaultElysiaButton
            buttonText: qsTr("Motor Faults")
            isSelected: selectedButton === 7
            onClicked: selectedButton = 7
            visible:settings.isElysia
        }

        TabBtn {
            id: button8
            buttonText: qsTr("Proximity Sensors")
            isSelected: selectedButton === 8
            onClicked: selectedButton = 8
            visible:!settings.isElysia
        }
        TabBtn {
            id: button9
            buttonText: qsTr("Settings")
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
            sourceComponent: selectedButton === 0 && !settings.getIsElysia ? keyMotorView :
                                selectedButton === 1 && !settings.getIsElysia ? motorDetailsView :
                                selectedButton === 2 && !settings.getIsElysia ? b3View :
                                selectedButton === 3 && !settings.getIsElysia ? telemetryView :
                                selectedButton === 4 ? batteryFaultsView :
                                selectedButton === 5 ? batteryView :
                                selectedButton === 6 && !settings.getIsElysia ? mpptView :
                                selectedButton === 7 && !settings.getIsElysia ? mbmsView :
                                selectedButton === 8 && !settings.getIsElysia ? proximitySensorsView :
                                selectedButton === 9 ? settingsView :

                                selectedButton === 0 && settings.getIsElysia ? auxBmsElysiaView:
                                selectedButton === 1 && settings.getIsElysia ? driverControlElysiaView:
                                selectedButton === 2 && settings.getIsElysia ? keyMotorElysiaView:
                                selectedButton === 3 && settings.getIsElysia ? lightElysiaView:
                                selectedButton === 6 && settings.getIsElysia ? motorDetailsElysiaView:
                                selectedButton === 7 && settings.getIsElysia ? motorFaultsElysiaView:null


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

        Component {
            id: settingsView
            Setting{}
        }
        Component {
            id:auxBmsElysiaView
            AuxBmsElysiaView{}
        }
        Component {
            id:driverControlElysiaView
            DriverControlsElysiaView{}
        }
        Component {
            id:keyMotorElysiaView
            KeyMotorElysiaView{}
        }
        Component {
            id:lightElysiaView
            LightsElysiaView{}
        }
        Component{
            id:motorDetailsElysiaView
            MotorDetailsElysia{}
        }
        Component{
            id:motorFaultsElysiaView
            MotorFaultsElysia{}
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
