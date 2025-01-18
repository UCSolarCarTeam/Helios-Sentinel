import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."
Item {
    width: 880
    height: 400

    Switch {
        id: switch1
        x: 8
        y: 60
        text: qsTr("Driver Controls")
        checked: driverControls.DriverControlsAlive
        onClicked: driverControls.setDriverControlsAlive(checked)

    }
    FlagBox{
        title:"Lights Input"
        flags:[
            {
                text: qsTr("Headlights Off"),
                checked: driverControls.HeadlightsOff,
                onClicked: function(checked) {driverControls.setHeadlightsOff(checked)}
            },
            {
                text: qsTr("Headlights Low"),
                checked: driverControls.HeadlightsLow,
                onClicked: function(checked) {driverControls.setHeadlightsLow(checked)}
            },
            {
                text: qsTr("Headlights High"),
                checked: driverControls.HeadlightsHigh,
                onClicked: function(checked) {driverControls.setHeadlightsHigh(checked)}
            },
            {
                text: qsTr("Signal Right"),
                checked: driverControls.SignalRight,
                onClicked: function(checked) {driverControls.setSignalRight(checked)}
            },
            {
                text: qsTr("Signal Left"),
                checked: driverControls.SignalLeft,
                onClicked: function(checked) {driverControls.setSignalLeft(checked)}
            },
            {
                text: qsTr("Interior"),
                checked: driverControls.Interior,
                onClicked: function(checked) {driverControls.setInterior(checked)}
            }
        ]
    }

    FlagBox{
        title:"Music Inputs"
        flags:[
            {
                text: qsTr("Volume Up"),
                checked: driverControls.VolumeUp,
                onClicked: function(checked) {driverControls.setVolumeUp(checked)}
            },
            {
                text: qsTr("Volume Down"),
                checked: driverControls.VolumeDown,
                onClicked: function(checked) {driverControls.setVolumeDown(checked)}
            },
            {
                text: qsTr("Next Song"),
                checked: driverControls.Next,
                onClicked: function(checked) {driverControls.setNext(checked)}
            },
            {
                text: qsTr("Prev Song"),
                checked: driverControls.Prev,
                onClicked: function(checked) {driverControls.setPrev(checked)}
            }
        ]
    }

    IntSpinBox {
        text:qsTr("Acceleration")
        value: driverControls.Acceleration
        onValueChanged: driverControls.setAcceleration(value)
    }
    IntSpinBox {
         text: qsTr("Regen Braking")
         value: driverControls.RegenBraking
         onValueChanged: driverControls.setRegenBraking(value)
    }

    FlagBox{
        title:"Driver's Input"
        flags:[
            {
                text: qsTr("Brakes"),
                checked: driverControls.Brakes,
                onClicked: function(checked) {driverControls.setBrakes(checked)}
            },
            {
                text: qsTr("Forward"),
                checked: driverControls.Forward,
                onClicked: function(checked) {driverControls.setForward(checked)}
            },
            {
                text: qsTr("Reverse"),
                checked: driverControls.Reverse,
                onClicked: function(checked) {driverControls.setReverse(checked)}
            },
            {
                text: qsTr("Push To Talk"),
                checked: driverControls.PushToTalk,
                onClicked: function(checked) {driverControls.setPushToTalk(checked)}
            },
            {
                text: qsTr("Horn"),
                checked: driverControls.Horn,
                onClicked: function(checked) {driverControls.setHorn(checked)}
            },
            {
                text: qsTr("Reset"),
                checked: driverControls.Reset,
                onClicked: function(checked) {driverControls.setReset(checked)}
            },
            {
                text: qsTr("Aux"),
                checked: driverControls.Aux,
                onClicked: function(checked) {driverControls.setAux(checked)}
            },
            {
                text: qsTr("Lap"),
                checked: driverControls.Lap,
                onClicked: function(checked) {driverControls.setLap(checked)}
            }
        ]
    }

    BytePreview {
        id: bytePreview
        raw: driverControls.byteStreamStr
        encoded:  driverControls.encodedByteStreamStr
    }
}
