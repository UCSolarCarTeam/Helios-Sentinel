import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0

Item {
    width: 1920
    height: 1080

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1092
        height: 1080
        color: "#f7ee84"
        radius: 25

        Rectangle {
            id: rectangle1
            x: 25
            y: 28
            width: 295
            height: 480
            color: "#4ecab8"
            radius: 25

            Switch {
                id: switch1
                x: 30
                y: 55
                text: qsTr("Motor Over Speed")
            }

            Switch {
                id: switch3
                x: 29
                y: 157
                text: qsTr("DC Bus OVer Voltage")
            }

            Switch {
                id: switch2
                x: 30
                y: 105
                text: qsTr("Software Over Current")
            }

            Switch {
                id: switch4
                x: 29
                y: 207
                text: qsTr("Bad Motor Position HS")
            }

            Switch {
                id: switch5
                x: 29
                y: 256
                text: qsTr("Watchdog Caused Last Reset")
                rotation: 0.105
            }

            Switch {
                id: switch7
                x: 30
                y: 365
                text: qsTr("15V Rail Under Voltage Lock")
            }

            Switch {
                id: switch8
                x: 31
                y: 421
                text: qsTr("Desaturation Fault")
            }

            Switch {
                id: switch6
                x: 30
                y: 311
                text: qsTr("Config Read Error")
            }

            Text {
                id: text1
                x: 87
                y: 25
                text: qsTr("M0 Error Flags")
                font.pixelSize: 20
            }
        }

        GroupItem {
            x: 670
            y: 50

            SpinBox {
                id: spinBox
                x: 0
                y: 0
                width: 135
                height: 47
            }

            Text {
                id: text2
                x: 159
                y: 15
                width: 172
                height: 18
                text: qsTr("M0 CAN RX Error Count ")
                font.pixelSize: 16
            }
        }

        Rectangle {
            id: rectangle2
            x: 332
            y: 28
            width: 295
            height: 480
            color: "#4ecab8"
            radius: 25
            Switch {
                x: 30
                y: 55
                text: qsTr("Motor Over Speed")
            }

            Switch {
                x: 29
                y: 157
                text: qsTr("DC Bus OVer Voltage")
            }

            Switch {
                x: 30
                y: 105
                text: qsTr("Software Over Current")
            }

            Switch {
                x: 29
                y: 207
                text: qsTr("Bad Motor Position HS")
            }

            Switch {
                x: 29
                y: 256
                text: qsTr("Watchdog Caused Last Reset")
                rotation: 0.105
            }

            Switch {
                x: 30
                y: 365
                text: qsTr("15V Rail Under Voltage Lock")
            }

            Switch {
                x: 31
                y: 421
                text: qsTr("Desaturation Fault")
            }

            Switch {
                x: 30
                y: 311
                text: qsTr("Config Read Error")
            }

            Text {
                x: 87
                y: 25
                text: qsTr("M1 Error Flags")
                font.pixelSize: 20
            }
        }

        Rectangle {
            id: rectangle3
            x: 28
            y: 523
            width: 295
            height: 419
            color: "#4e9eca"
            radius: 25
            Switch {
                x: 30
                y: 55
                text: qsTr("Output Voltage PWM")
            }

            Switch {
                x: 29
                y: 157
                text: qsTr("Velocity")
            }

            Switch {
                x: 30
                y: 105
                text: qsTr("Motor Current ")
            }

            Switch {
                x: 29
                y: 207
                text: qsTr("Bus Current")
            }

            Switch {
                x: 29
                y: 256
                text: qsTr("Bus Voltage Upper")
                rotation: 0.105
            }

            Switch {
                x: 30
                y: 365
                text: qsTr("IPM or Motor Temperature")
            }

            Switch {
                x: 30
                y: 311
                text: qsTr("Bus Voltage Lower")
            }

            Text {
                x: 87
                y: 25
                text: qsTr("M0 Limit Flags")
                font.pixelSize: 20
            }
        }

        Rectangle {
            id: rectangle4
            x: 332
            y: 523
            width: 295
            height: 419
            color: "#4e9eca"
            radius: 25
            Switch {
                x: 30
                y: 55
                text: qsTr("Output Voltage PWM")
            }

            Switch {
                x: 29
                y: 157
                text: qsTr("Velocity")
            }

            Switch {
                x: 30
                y: 105
                text: qsTr("Motor Current ")
            }

            Switch {
                x: 29
                y: 207
                text: qsTr("Bus Current")
            }

            Switch {
                x: 29
                y: 256
                text: qsTr("Bus Voltage Upper")
                rotation: 0.105
            }

            Switch {
                x: 30
                y: 365
                text: qsTr("IPM or Motor Temperature")
            }

            Switch {
                x: 30
                y: 311
                text: qsTr("Bus Voltage Lower")
            }

            Text {
                x: 87
                y: 25
                text: qsTr("M1 Limit Flags")
                font.pixelSize: 20
            }
        }

        GroupItem {
            x: 669
            y: 121
            SpinBox {
                x: 0
                y: 0
                width: 135
                height: 47
            }

            Text {
                x: 159
                y: 15
                width: 172
                height: 18
                text: qsTr("M0 CAN TX Error Count ")
                font.pixelSize: 16
            }
        }

        GroupItem {
            x: 669
            y: 205
            SpinBox {
                x: 0
                y: 0
                width: 135
                height: 47
            }

            Text {
                x: 159
                y: 15
                width: 172
                height: 18
                text: qsTr("M1 CAN RX Error Count ")
                font.pixelSize: 16
            }
        }

        GroupItem {
            x: 669
            y: 298
            SpinBox {
                x: 0
                y: 0
                width: 135
                height: 47
            }

            Text {
                x: 159
                y: 15
                width: 172
                height: 18
                text: qsTr("M1 CAN TX Error Count ")
                font.pixelSize: 16
            }
        }
    }
}
