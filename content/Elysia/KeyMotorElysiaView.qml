import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0

Item {
    id: keyMotor
    width: 820
    height: 370

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 820
        height: 370
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
                text: qsTr("M0 Alive")
                checked: keyMotorElysia.m0Alive
                onClicked: keyMotorElysia.setM0Alive(checked)
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
                    value: keyMotorElysia.m0SetCurrent
                    onValueChanged: keyMotorElysia.setM0SetCurrent(value)
                }

                Text {
                    id: text1
                    x: 112
                    y: 6
                    text: qsTr("Set Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 51
                y: 123
                SpinBox {
                    x: 0
                    y: 0
                    width: 87
                    height: 28
                    value: keyMotorElysia.m0SetVelocity
                    onValueChanged: keyMotorElysia.setM0SetVelocity(value)
                }

                Text {
                    x: 112
                    y: 6
                    text: qsTr("Set Velocity")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 51
                y: 163
                SpinBox {
                    x: 0
                    y: 0
                    width: 87
                    height: 28
                    value: keyMotorElysia.m0BusCurrent
                    onValueChanged: keyMotorElysia.setM0BusCurrent(value)
                }

                Text {
                    x: 112
                    y: 6
                    text: qsTr("Bus Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 51
                y: 203
                SpinBox {
                    x: 0
                    y: 0
                    width: 87
                    height: 28
                    value: keyMotorElysia.m0BusVoltage
                    onValueChanged: keyMotorElysia.setM0BusVoltage(value)
                }

                Text {
                    x: 112
                    y: 6
                    text: qsTr("Bus Voltage")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 51
                y: 244
                SpinBox {
                    x: 0
                    y: 0
                    width: 87
                    height: 28
                    value: keyMotorElysia.m0VehicleVelocity
                    onValueChanged: keyMotorElysia.setM0VehicleVelocity(value)
                }

                Text {
                    x: 112
                    y: 6
                    text: qsTr("Vehicle Velocity")
                    font.pixelSize: 12
                }
            }
        }
    }

    Rectangle {
        id: rectangle2
        x: 450
        y: 28
        width: 279
        height: 298
        color: "#74a2e3"
        radius: 25
        Switch {
            x: 72
            y: 26
            width: 135
            height: 37
            text: qsTr("M1 Alive")
            checked: keyMotorElysia.m1Alive
            onClicked: keyMotorElysia.setM1Alive(checked)
        }

        GroupItem {
            x: 51
            y: 83
            SpinBox {
                x: 0
                y: 0
                width: 87
                height: 28
                value: keyMotorElysia.m1SetCurrent
                onValueChanged: keyMotorElysia.setM1SetCurrent(value)
            }

            Text {
                x: 112
                y: 6
                text: qsTr("Set Current")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 51
            y: 123
            SpinBox {
                x: 0
                y: 0
                width: 87
                height: 28
                value: keyMotorElysia.m1SetVelocity
                onValueChanged: keyMotorElysia.setM1SetVelocity(value)
            }

            Text {
                x: 112
                y: 6
                text: qsTr("Set Velocity")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 51
            y: 163
            SpinBox {
                x: 0
                y: 0
                width: 87
                height: 28
                value: keyMotorElysia.m1BusCurrent
                onValueChanged: keyMotorElysia.setM1BusCurrent(value)
            }

            Text {
                x: 112
                y: 6
                text: qsTr("Bus Current")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 51
            y: 203
            SpinBox {
                x: 0
                y: 0
                width: 87
                height: 28
                value: keyMotorElysia.m1BusVoltage
                onValueChanged: keyMotorElysia.setM1BusVoltage(value)
            }

            Text {
                x: 112
                y: 6
                text: qsTr("Bus Voltage")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 51
            y: 244
            SpinBox {
                x: 0
                y: 0
                width: 87
                height: 28
                value: keyMotorElysia.m1VehicleVelocity
                onValueChanged: keyMotorElysia.setM1VehicleVelocity(value)
            }

            Text {
                x: 112
                y: 6
                text: qsTr("Vehicle Velocity")
                font.pixelSize: 12
            }
        }
    }
}
