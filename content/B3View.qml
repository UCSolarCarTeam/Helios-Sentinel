import QtQuick 2.15
import QtQuick.Controls 6.2

Item {
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 650
        height: 421
        color: "#9bb4e5"

        Rectangle {
            id: rectangle1
            x: 0
            y: 0
            width: 327
            height: 186
            color: "#a0d7a0"

            TextInput {
                id: textInput
                x: 8
                y: 8
                width: 80
                height: 20
                text: qsTr("Lights Input")
                font.pixelSize: 12
            }

            Switch {
                id: switch1
                x: 0
                y: 26
                width: 161
                height: 31
                text: "Left Signal"
                font.pointSize: 14
                checked: keyMotor.m0Alive
                onClicked: keyMotor.setM0Alive(checked)

            }

            Switch {
                id: switch2
                x: 161
                y: 26
                width: 166
                height: 31
                text: qsTr("Right Signal")
            }

            Switch {
                id: switch3
                x: 0
                y: 63
                width: 161
                height: 31
                text: "Hazard Lights"
                font.pointSize: 12
            }

            Switch {
                id: switch4
                x: 161
                y: 63
                width: 166
                height: 31
                text: qsTr("Headlights")
            }

            Switch {
                id: switch5
                x: 0
                y: 100
                width: 161
                height: 31
                text: "Forward Switch"
                font.pointSize: 11
            }

            Switch {
                id: switch6
                x: 161
                y: 100
                width: 166
                height: 31
                text: qsTr("Horn Switch")
            }

            Switch {
                id: switch7
                x: 83
                y: 137
                width: 161
                height: 31
                text: "Forward"
                font.pointSize: 14
            }
        }

        SpinBox {
            id: spinBox
            x: 366
            y: 212
        }

        SpinBox {
            id: spinBox1
            x: 366
            y: 294
        }

        Text {
            id: text1
            x: 549
            y: 233
            text: qsTr("Acceleration")
            font.pixelSize: 15
            minimumPixelSize: 12
        }
    }

    Rectangle {
        id: rectangle2
        x: 323
        y: 0
        width: 327
        height: 186
        color: "#a0d7a0"
        TextInput {
            x: 8
            y: 8
            width: 80
            height: 20
            text: qsTr("Lights Output")
            font.pixelSize: 12
        }

        Switch {
            x: 0
            y: 26
            width: 161
            height: 31
            text: "Left Signal"
            font.pointSize: 14
        }

        Switch {
            x: 161
            y: 26
            width: 166
            height: 31
            text: qsTr("Right Signal")
        }

        Switch {
            x: 0
            y: 63
            width: 161
            height: 31
            text: "Daytime Light Signal"
            font.pointSize: 7
        }

        Switch {
            x: 161
            y: 63
            width: 166
            height: 31
            text: qsTr("Headlight Signal")
            font.pointSize: 11
        }

        Switch {
            x: 0
            y: 100
            width: 161
            height: 31
            text: "Brake Light"
            font.pointSize: 14
        }

        Switch {
            x: 161
            y: 100
            width: 166
            height: 31
            text: qsTr("Horn Signal")
        }
    }

    Rectangle {
        id: rectangle3
        x: 0
        y: 208
        width: 327
        height: 186
        color: "#a0d7a0"
        TextInput {
            x: 8
            y: 8
            width: 80
            height: 20
            text: qsTr("Driver Inputs")
            font.pixelSize: 12
        }

        Switch {
            x: 0
            y: 26
            width: 161
            height: 31
            text: "Neutral"
            font.pointSize: 14
        }

        Switch {
            x: 161
            y: 26
            width: 166
            height: 31
            text: qsTr("Reverse")
        }

        Switch {
            x: 0
            y: 63
            width: 161
            height: 31
            text: "Brake Switch"
            font.pointSize: 13
        }

        Switch {
            x: 161
            y: 63
            width: 166
            height: 31
            text: qsTr("Handbrake Switch")
            font.pointSize: 10
        }

        Switch {
            x: 0
            y: 100
            width: 161
            height: 31
            text: "Motor Reset"
            font.pointSize: 14
        }

        Switch {
            x: 161
            y: 100
            width: 166
            height: 31
            text: qsTr("Race Mode")
        }

        Switch {
            x: 0
            y: 137
            width: 161
            height: 31
            text: "Lap"
            font.pointSize: 14
        }

        Switch {
            x: 161
            y: 137
            width: 166
            height: 31
            text: qsTr("Zoom Zoom")
        }
    }

    Text {
        id: text2
        x: 544
        y: 309
        text: qsTr("Regen Braking")
        font.pixelSize: 15
        minimumPixelSize: 12
    }
}
