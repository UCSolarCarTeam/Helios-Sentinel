import QtQuick 2.15
import QtQuick.Controls 6.2

Item {
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 650
        height: 480
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
                checked: b3.leftSignalIn
                onClicked: b3.setLeftSignalIn(checked)
            }

            Switch {
                id: switch2
                x: 161
                y: 26
                width: 166
                height: 31
                text: qsTr("Right Signal")
                checked: b3.rightSignalIn
                onClicked: b3.setRightSignalIn(checked)
            }

            Switch {
                id: switch3
                x: 0
                y: 63
                width: 161
                height: 31
                text: "Hazard Lights"
                font.pointSize: 12
                checked: b3.hazardLights
                onClicked: b3.setHazardLights(checked)
            }

            Switch {
                id: switch4
                x: 161
                y: 63
                width: 166
                height: 31
                text: qsTr("Headlights")
                checked: b3.headlightsSwitch
                onClicked: b3.setHeadlightsSwitch(checked)
            }

            Switch {
                id: switch5
                x: 0
                y: 100
                width: 161
                height: 31
                text: "Forward Switch"
                font.pointSize: 11
                checked: b3.forwardSwitch
                onClicked: b3.setForwardSwitch(checked)
            }

            Switch {
                id: switch6
                x: 161
                y: 100
                width: 166
                height: 31
                text: qsTr("Horn Switch")
                checked: b3.hornSwitch
                onClicked: b3.setHornSwitch(checked)
            }

            Switch {
                id: switch7
                x: 83
                y: 137
                width: 161
                height: 31
                text: "Forward"
                font.pointSize: 14
                checked: b3.forward
                onClicked: b3.setForward(checked)
            }
        }

        SpinBox {
            id: spinBox
            x: 366
            y: 212
            from: 0
            to: 255
            value: b3.acceleration
            onValueChanged: b3.setAcceleration(value)
        }

        SpinBox {
            id: spinBox1
            x: 366
            y: 294
            from: 0
            to: 255
            value: b3.regenBraking
            onValueChanged: b3.setRegenBraking(value)
        }

        Text {
            id: text1
            x: 549
            y: 233
            text: qsTr("Acceleration")
            font.pixelSize: 15
            minimumPixelSize: 12
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
                checked: b3.leftSignalOut
                onClicked: b3.setLeftSignalOut(checked)
            }

            Switch {
                x: 161
                y: 26
                width: 166
                height: 31
                text: qsTr("Right Signal")
                checked: b3.rightSignalOut
                onClicked: b3.setRightSignalOut(checked)
            }

            Switch {
                x: 0
                y: 63
                width: 161
                height: 31
                text: "Daytime Light Signal"
                font.pointSize: 7
                checked: b3.daytimeRunningLightSignal
                onClicked: b3.setDaytimeRunningLightSignal(checked)
            }

            Switch {
                x: 161
                y: 63
                width: 166
                height: 31
                text: qsTr("Headlight Signal")
                font.pointSize: 11
                checked: b3.headlightSignal
                onClicked: b3.setHeadlightSignal(checked)
            }

            Switch {
                x: 0
                y: 100
                width: 161
                height: 31
                text: "Brake Light"
                font.pointSize: 14
                checked: b3.brakeLightSignal
                onClicked: b3.setBrakeLightSignal(checked)
            }

            Switch {
                x: 161
                y: 100
                width: 166
                height: 31
                text: qsTr("Horn Signal")
                checked: b3.hornSignal
                onClicked: b3.setHornSignal(checked)
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
                checked: b3.neutral
                onClicked: b3.setNeutral(checked)
            }

            Switch {
                x: 161
                y: 26
                width: 166
                height: 31
                text: qsTr("Reverse")
                checked: b3.reverse
                onClicked: b3.setReverse(checked)
            }

            Switch {
                x: 0
                y: 63
                width: 161
                height: 31
                text: "Brake Switch"
                font.pointSize: 13
                checked: b3.brakeSwitch
                onClicked: b3.setBrakeSwitch(checked)
            }

            Switch {
                x: 161
                y: 63
                width: 166
                height: 31
                text: qsTr("Handbrake Switch")
                font.pointSize: 10
                checked: b3.handbrakeSwitch
                onClicked: b3.setHandbrakeSwitch(checked)
            }

            Switch {
                x: 0
                y: 100
                width: 161
                height: 31
                text: "Motor Reset"
                font.pointSize: 14
                checked: b3.motorReset
                onClicked: b3.setMotorReset(checked)
            }

            Switch {
                x: 161
                y: 100
                width: 166
                height: 31
                text: qsTr("Race Mode")
                checked: b3.raceMode
                onClicked: b3.setRaceMode(checked)
            }

            Switch {
                x: 0
                y: 137
                width: 161
                height: 31
                text: "Lap"
                font.pointSize: 14
                checked: b3.lap
                onClicked: b3.setLap(checked)
            }

            Switch {
                x: 161
                y: 137
                width: 166
                height: 31
                text: qsTr("Zoom Zoom")
                checked: b3.zoomZoom
                onClicked: b3.setZoomZoom(checked)
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

        Text {
            id: text4
            x: 179
            y: 433
            text: qsTr("Encoded Stream: " + b3.encodedByteStreamStr)
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 203
            y: 402
            text: qsTr("Byte Stream: "+ b3.byteStreamStr)
            font.pixelSize: 12
        }
    }
}
