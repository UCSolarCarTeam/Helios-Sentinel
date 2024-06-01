import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 800
    height: 600
    opacity: 1
    visible: true

    Rectangle {
        id: mainContainer
        x: 0
        y: 0
        width: 800
        height: 400
        color: "#ffffff"
        radius: 25

        Text {
            id: text1
            x: 65
            y: 289
            width: 698
            height: 14
            text: "#\"Byte Stream: \" + lights.byteStreamStr#"
            font.pixelSize: 16
        }

        Text {
            id: text2
            x: 65
            y: 314
            width: 706
            height: 14
            text: "#\"Encoded Stream: \" + lights.encodedByteStreamStr#"
            font.pixelSize: 16
        }

        Switch {
            id: switch1
            x: 57
            y: 25
            text: qsTr("Lights")
            z: 1
            checked: lights.lightsAlive
            onClicked: lights.setLightsAlive(checked)
        }

        Switch {
            id: switch2
            x: 203
            y: 25
            text: qsTr("Low Beams")
            z: 1
            checked: lights.lowBeams
            onClicked: lights.setLowBeams(checked)
        }

        Switch {
            id: switch3
            x: 380
            y: 25
            width: 147
            height: 32
            text: qsTr("Left Signal")
            z: 1
            checked: lights.leftSignal
            onClicked: lights.setLeftSignal(checked)
        }

        Switch {
            id: switch4
            x: 203
            y: 63
            width: 159
            height: 32
            text: qsTr("High Beams")
            z: 1
            checked: lights.highBeams
            onClicked: lights.setHighBeams(checked)
        }

        Switch {
            id: switch5
            x: 380
            y: 63
            width: 158
            height: 32
            text: qsTr("Right Signal")
            z: 1
            checked: lights.rightSignal
            onClicked: lights.setRightSignal(checked)
        }

        Switch {
            id: switch6
            x: 203
            y: 101
            width: 159
            height: 32
            text: qsTr("Brake Lights")
            z: 1
            checked: lights.brakeLights
            onClicked: lights.setBrakeLights(checked)
        }

        Switch {
            id: switch7
            x: 380
            y: 101
            width: 147
            height: 32
            text: qsTr("BMS Light")
            z: 1
            checked: lights.bmsLight
            onClicked: lights.setBmsLight(checked)
        }
    }
}
