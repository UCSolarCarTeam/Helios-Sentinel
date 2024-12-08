import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0

Item {
    width: 820
    height: 450

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 820
        height: 450
        color: "#89f0a7"
        radius: 25

        Rectangle {
            id: rectangle1
            x: 90
            y: 28
            width: 279
            height: 298
            color: "#74a2e3"
            radius: 25

            Switch {
                id: switch1
                x: 72
                y: 26
                width: 135
                height: 37
                text: qsTr("Control Mode")
                checked: keyMotor.controlMode
                onClicked: keyMotor.setControlMode(checked)
            }

            GroupItem {
                x: 51
                y: 83

                SpinBox {
                    id: spinBox
                    x: 0
                    y: 0
                    width: 87
                    height: 28
                    to: 65535
                    editable: true
                    value: keyMotor.motorSetpoint
                    onValueChanged: keyMotor.setMotorSetpoint(value)
                }

                Text {
                    id: text1
                    x: 112
                    y: 6
                    text: qsTr("Set Motor Setpoint")
                    font.pixelSize: 12
                }
            }

            Switch {
                id:switch2
                x: 51
                y: 123
                width: 135
                height: 37
                text: qsTr("Motor Mode")
                checked: keyMotor.motorMode
                onClicked: keyMotor.setMotorMode(checked)
            }
            Switch {
                id:switch3
                x: 51
                y: 163
                width: 135
                height: 37
                text: qsTr("Software Enable")
                checked: keyMotor.softwareEnable
                onClicked: keyMotor.setSoftwareEnable(checked)
            }
            Switch {
                id:switch4
                x: 51
                y: 203
                width: 135
                height: 37
                text: qsTr("Debug Mode")
                checked: keyMotor.debugMode()
                onClicked: keyMotor.setDebugMode(checked)
            }
        }
    }

    Text {
        id: text3
        x: 8
        y: 344
        width: 442
        height: 14
        text: "Byte Stream: " + keyMotor.byteStreamStr
        font.pixelSize: 16
    }

    Text {
        id: text2
        x: 8
        y: 380
        width: 442
        height: 14
        text: "Encoded Stream: " + keyMotor.encodedByteStreamStr
        font.pixelSize: 16
    }
}


