import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 880
    height: 400

    Switch {
        id: switch1
        x: 8
        y: 60
        text: qsTr("Driver Controls")
        checked: driverControls.driverControlsAlive
        onClicked: driverControls.setDriverControlsAlive(checked)

    }

    Switch {
        id: switch2
        x: 224
        y: 60
        text: qsTr("Headlights Off")
        checked: driverControls.headlightsOff
        onClicked: driverControls.setHeadlightsOff(checked)
    }

    Switch {
        id: switch3
        x: 224
        y: 98
        text: qsTr("Headlights Low")
        checked: driverControls.headlightsLow
        onClicked: driverControls.setHeadlightsLow(checked)
    }

    Switch {
        id: switch4
        x: 224
        y: 136
        width: 186
        height: 32
        text: qsTr("Headlights High")
        checked: driverControls.headlightsHigh
        onClicked: driverControls.setHeadlightsHigh(checked)
    }

    Switch {
        id: switch5
        x: 224
        y: 174
        width: 186
        height: 32
        text: qsTr("Signal Right")
        checked: driverControls.signalRight
        onClicked: driverControls.setSignalRight(checked)
    }

    Switch {
        id: switch6
        x: 224
        y: 212
        width: 186
        height: 32
        text: qsTr("Signal Left")
        checked: driverControls.signalLeft
        onClicked: driverControls.setSignalLeft(checked)
    }

    Switch {
        id: switch7
        x: 224
        y: 250
        width: 186
        height: 32
        text: qsTr("Hazard")
        checked: driverControls.hazards
        onClicked: driverControls.setHazards(checked);
    }

    Switch {
        id: switch8
        x: 224
        y: 288
        width: 186
        height: 32
        text: qsTr("Interior")
        checked: driverControls.interior
        onClicked: driverControls.setInterior(checked)
    }

    Rectangle {
        id: rectangle
        x: 211
        y: 16
        width: 200
        height: 336
        color: "#ff9595"
        radius: 25
        border.width: 0
        z: -1
    }

    Text {
        id: text1
        x: 229
        y: 33
        text: qsTr("Lights Inputs")
        font.pixelSize: 12
    }

    Switch {
        id: switch9
        x: 446
        y: 60
        text: qsTr("Volume Up")
        checked: driverControls.volumeUp
        onClicked: driverControls.setVolumeUp(checked)
    }

    Switch {
        id: switch10
        x: 446
        y: 98
        text: qsTr("Volume Down")
        checked: driverControls.volumeDown
        onClicked: driverControls.setVolumeDown(checked)
    }

    Switch {
        id: switch11
        x: 446
        y: 136
        width: 186
        height: 32
        text: qsTr("Next Song")
        checked: driverControls.next
        onClicked: driverControls.setNext(checked)
    }

    Switch {
        id: switch12
        x: 446
        y: 174
        width: 186
        height: 32
        text: qsTr("Prev Song")
        checked: driverControls.prev
        onClicked: driverControls.setPrev(checked)
    }

    Rectangle {
        id: rectangle1
        x: 433
        y: 16
        width: 200
        height: 204
        color: "#95beff"
        radius: 25
        border.width: 0
        z: -1
    }

    Text {
        id: text2
        x: 451
        y: 33
        text: qsTr("Music Inputs")
        font.pixelSize: 12
    }

    SpinBox {
        id: spinBox
        x: 446
        y: 244
        width: 140
        height: 38
        to: 4095
        value: driverControls.acceleration
        onValueChanged: driverControls.setAcceleration(value)
    }

    Text {
        id: text3
        x: 446
        y: 224
        text: qsTr("Acceleration")
        font.pixelSize: 12
    }

    SpinBox {
        id: spinBox1
        x: 446
        y: 308
        width: 140
        height: 38
        to: 4095
        value: driverControls.regenBraking
        onValueChanged: driverControls.setRegenBraking(value)
    }

    Text {
        id: text4
        x: 446
        y: 288
        text: qsTr("Regen Braking")
        font.pixelSize: 12
    }

    Switch {
        id: switch13
        x: 666
        y: 51
        text: qsTr("Brakes")
        checked: driverControls.brakes
        onClicked: driverControls.setBrakes(checked)
    }

    Switch {
        id: switch14
        x: 666
        y: 89
        text: qsTr("Forward")
        checked: driverControls.forward
        onClicked: driverControls.setForward(checked)
    }

    Switch {
        id: switch15
        x: 666
        y: 127
        width: 186
        height: 32
        text: qsTr("Reverse")
        checked: driverControls.reverse
        onClicked: driverControls.setReverse(checked)
    }

    Switch {
        id: switch16
        x: 666
        y: 165
        width: 186
        height: 32
        text: qsTr("Push To Talk")
        checked: driverControls.pushToTalk
        onClicked: driverControls.setPushToTalk(checked)
    }

    Switch {
        id: switch17
        x: 666
        y: 203
        width: 186
        height: 32
        text: qsTr("Horn")
        checked: driverControls.horn
        onClicked: driverControls.setHorn(checked)
    }

    Switch {
        id: switch18
        x: 666
        y: 241
        width: 186
        height: 32
        text: qsTr("Reset")
        checked: driverControls.reset
        onClicked: driverControls.setReset(checked)
    }

    Switch {
        id: switch19
        x: 666
        y: 279
        width: 186
        height: 32
        text: qsTr("Aux")
        checked: driverControls.aux
        onClicked: driverControls.setAux(checked)
    }

    Rectangle {
        id: rectangle2
        x: 653
        y: 16
        width: 200
        height: 336
        color: "#a4ff95"
        radius: 25
        border.width: 0
        z: -1
    }

    Text {
        id: text5
        x: 671
        y: 33
        text: qsTr("Driver Inputs")
        font.pixelSize: 12
    }

    Switch {
        id: switch20
        x: 666
        y: 314
        width: 186
        height: 32
        text: qsTr("Lap")
        checked: driverControls.lap
        onClicked: driverControls.setLap(checked)
    }

    Rectangle {
        id: rectangle3
        x: 0
        y: 0
        width: 880
        height: 400
        color: "#fcffc2"
        radius: 25
        z: -2
    }

    Text {
        id: driverControlsStream
        x: 8
        y: 358
        width: 665
        height: 14
        text: "Byte Stream: " + driverControls.byteStreamStr
        font.pixelSize: 16

    }

    Text {
        id: driverControlsStream1
        x: 8
        y: 378
        width: 665
        height: 14
        text: "Encoded Stream: " + driverControls.encodedByteStreamStr
        font.pixelSize: 16
    }
}
