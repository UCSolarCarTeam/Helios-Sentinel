import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0
import ".."

Item {
    width: 550
    height: 650

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Key Motor Packet"
            font.family: "Verdana"
            font.bold: true
        }
        FlagBox {
            title:"M0"
            flags:[
                {
                    text: qsTr("M0 Alive"),
                    checked: keyMotorElysia.M0Alive,
                    onClicked: function(checked) {keyMotorElysia.setM0Alive(checked)}
                }
            ]
        }

        FloatSpinBox{
            text: qsTr("M0 Set Current")
            inputValue: keyMotorElysia.M0SetCurrent
            onInputValueChanged: keyMotorElysia.setM0SetCurrent(inputValue)
        }
        FloatSpinBox {
            text: qsTr("M0 Set Velocity")
            inputValue: keyMotorElysia.M0SetVelocity
            onInputValueChanged: keyMotorElysia.setM0SetVelocity(inputValue)
        }
        FloatSpinBox {
            text: qsTr("M0 Bus Current")
            inputValue: keyMotorElysia.M0BusCurrent
            onInputValueChanged: keyMotorElysia.setM0BusCurrent(inputValue)
        }
        FloatSpinBox{
            text:qsTr("M0 Bus Voltage")
            inputValue: keyMotorElysia.M0BusVoltage
            onInputValueChanged: keyMotorElysia.setM0BusVoltage(inputValue)
        }
        FloatSpinBox{
            text: qsTr("M0 Vehicle Velocity")
            inputValue:keyMotorElysia.M0VehicleVelocity
            onInputValueChanged: keyMotorElysia.setM0VehicleVelocity(inputValue)
        }

        FlagBox {
            title:"M1"
            flags:[
                {
                    text: qsTr("M1 Alive"),
                    checked: keyMotorElysia.M1Alive,
                    onClicked: function(checked) {keyMotorElysia.setM1Alive(checked)}
                }
            ]
        }

        FloatSpinBox{
            text: qsTr("M1 Set Current")
            inputValue: keyMotorElysia.M1SetCurrent
            onInputValueChanged: keyMotorElysia.setM1SetCurrent(inputValue)
        }
        FloatSpinBox {
            text: qsTr("M1 Set Velocity")
            inputValue: keyMotorElysia.M1SetVelocity
            onInputValueChanged: keyMotorElysia.setM1SetVelocity(inputValue)
        }
        FloatSpinBox {
            text: qsTr("M1 Bus Current")
            inputValue: keyMotorElysia.M1BusCurrent
            onInputValueChanged: keyMotorElysia.setM1BusCurrent(inputValue)
        }
        FloatSpinBox{
            text:qsTr("M1 Bus Voltage")
            inputValue: keyMotorElysia.M1BusVoltage
            onInputValueChanged: keyMotorElysia.setM1BusVoltage(inputValue)
        }
        FloatSpinBox{
            text: qsTr("M1 Vehicle Velocity")
            inputValue:keyMotorElysia.M1VehicleVelocity
            onInputValueChanged: keyMotorElysia.setM1VehicleVelocity(inputValue)

        }

    }

}
