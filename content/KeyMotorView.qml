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

        Column {
            spacing: 20

            Column{
                spacing: 20
                IntSpinBox {
                    id: spinBox
                    text: qsTr("Motor Setpoint")
                    value: keyMotor.MotorSetpoint
                    onValueChanged: keyMotor.setMotorSetpoint(value)
                }
            }
            
            FlagBox {
                title: "Control Flags"
                flags: [
                    {
                        text: qsTr("Control Mode"),
                        checked: keyMotor.ControlMode,
                        onClicked: function(checked) { keyMotor.setControlMode(checked) }
                    },
                    {
                        text: qsTr("Motor Mode"),
                        checked: keyMotor.MotorMode,
                        onClicked: function(checked) { keyMotor.setMotorMode(checked) }
                    },
                    {
                        text: qsTr("Software Enable"),
                        checked: keyMotor.SoftwareEnable,
                        onClicked: function(checked) { keyMotor.setSoftwareEnable(checked) }
                    },
                    {
                        text: qsTr("Debug Mode"),
                        checked: keyMotor.DebugMode,
                        onClicked: function(checked) { keyMotor.setDebugMode(checked) }
                    }
                ]
            }   
        }

        BytePreview {
            id: bytePreview
            raw: keyMotor.byteStreamStr
            encoded: keyMotor.encodedByteStreamStr
        }
    }
}


