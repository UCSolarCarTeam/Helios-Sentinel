import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0

Item {
    width: 550
    height: 350

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20
        
        Text {
            text: "Key Motor Packet"
            font.family: "Verdana"
            font.bold: true
        }

        IntSpinBox {
            text: "Control Value"
            value: keyMotor.ControlValue
            onValueChanged: keyMotor.setControlValue(value)
            min: -32768
            max: 32767
        }

        Column {
            spacing: 20

            IntSpinBox {
                text: "Control Mode"
                value: keyMotor.ControlMode
                onValueChanged: keyMotor.setControlMode(value)
                min: 0
                max: 3
            }

            IntSpinBox {
                text: "Motor Mode"
                value: keyMotor.MotorMode
                onValueChanged: keyMotor.setMotorMode(value)
                min: 0
                max: 7
            }

            FlagBox {
                title: "Misc Status"
                flags: [
                    {
                        text: "Software Enable",
                        checked: keyMotor.SoftwareEnable,
                        onClicked: function(checked) { keyMotor.setSoftwareEnable(checked) }
                    },
                    {
                        text: "Debug Mode",
                        checked: keyMotor.DebugMode,
                        onClicked: function(checked) { keyMotor.setDebugMode(checked) }
                    }
                ]
            }
        }
    }
}


