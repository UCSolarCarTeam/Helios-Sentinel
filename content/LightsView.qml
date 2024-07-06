import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 800
    height: 200

    Switch {
        id: switch1
        x: 20
        y: 10
        text: qsTr("Lights Alive")
        z: 1
        checked: lights.lightsAlive
        onClicked: lights.setLightsAlive(checked)
    }

    Switch {
        id: switch2
        x: 175
        y: 10
        text: qsTr("Low Beams")
        z: 1
        checked: lights.lowBeams
        onClicked: lights.setLowBeams(checked)
    }

    Switch {
        id: switch3
        x: 330
        y: 10
        text: qsTr("Left Signal")
        z: 1
        checked: lights.leftSignal
        onClicked: lights.setLeftSignal(checked)
    }

    Switch {
        id: switch4
        x: 175
        y: 50
        text: qsTr("High Beams")
        z: 1
        checked: lights.highBeams
        onClicked: lights.setHighBeams(checked)
    }

    Switch {
        id: switch5
        x: 330
        y: 50
        text: qsTr("Right Signal")
        z: 1
        checked: lights.rightSignal
        onClicked: lights.setRightSignal(checked)
    }

    Switch {
        id: switch6
        x: 175
        y: 90
        text: qsTr("Brake Lights")
        z: 1
        checked: lights.brakeLights
        onClicked: lights.setBrakeLights(checked)
    }

    Switch {
        id: switch7
        x: 330
        y: 90
        text: qsTr("BMS Strobe Light")
        z: 1
        checked: lights.bmsLight
        onClicked: lights.setBmsLight(checked)
    }

    Rectangle {
        id: rectangle
        x: 8
        y: 0
        width: 643
        height: 200
        color: "#ce83f1"
        radius: 25

        Text {
            id: text1
            x: 60
            y: 140
            width: 450
            height: 15
            text: "Byte Stream: " + lightsView.byteStream_
            font.pixelSize: 16
        }

        Text {
            id: text2
            x: 60
            y: 170
            width: 450
            height: 15
            text: "Encoded Stream: " + lightsView.encodedByteStream_
            font.pixelSize: 16
        }
    }
}
