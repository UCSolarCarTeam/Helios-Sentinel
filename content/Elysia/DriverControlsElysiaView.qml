import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."

Item {
    width: 550
    height: 650
    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Driver Controll Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Switch {
            id: switch1
            x: 8
            y: 60
            text: qsTr("Driver Controls")
            checked: driverControlElysia.DriverControlsAlive
            onClicked: driverControlElysia.setDriverControlsAlive(checked)
        }
        Column{
            spacing:20

            FlagBox{
                title:"Lights Input"
                flags:[
                    {
                        text: qsTr("Headlights Off"),
                        checked: driverControlElysia.HeadlightsOff,
                        onClicked: function(checked) {driverControlElysia.setHeadlightsOff(checked)}
                    },
                    {
                        text: qsTr("Headlights Low"),
                        checked: driverControlElysia.HeadlightsLow,
                        onClicked: function(checked) {driverControlElysia.setHeadlightsLow(checked)}
                    },
                    {
                        text: qsTr("Headlights High"),
                        checked: driverControlElysia.HeadlightsHigh,
                        onClicked: function(checked) {driverControlElysia.setHeadlightsHigh(checked)}
                    },
                    {
                        text: qsTr("Signal Right"),
                        checked: driverControlElysia.SignalRight,
                        onClicked: function(checked) {driverControlElysia.setSignalRight(checked)}
                    },
                    {
                        text: qsTr("Signal Left"),
                        checked: driverControlElysia.SignalLeft,
                        onClicked: function(checked) {driverControlElysia.setSignalLeft(checked)}
                    },
                    {
                        text: qsTr("Interior"),
                        checked: driverControlElysia.Interior,
                        onClicked: function(checked) {driverControlElysia.setInterior(checked)}
                    }
                ]
            }

            FlagBox{
                title:"Music Inputs"
                flags:[
                    {
                        text: qsTr("Volume Up"),
                        checked: driverControlElysia.VolumeUp,
                        onClicked: function(checked) {driverControlElysia.setVolumeUp(checked)}
                    },
                    {
                        text: qsTr("Volume Down"),
                        checked: driverControlElysia.VolumeDown,
                        onClicked: function(checked) {driverControlElysia.setVolumeDown(checked)}
                    },
                    {
                        text: qsTr("Next Song"),
                        checked: driverControlElysia.Next,
                        onClicked: function(checked) {driverControlElysia.setNext(checked)}
                    },
                    {
                        text: qsTr("Prev Song"),
                        checked: driverControlElysia.Prev,
                        onClicked: function(checked) {driverControlElysia.setPrev(checked)}
                    }
                ]
            }

            IntSpinBox {
                text:qsTr("Acceleration")
                value: driverControlElysia.Acceleration
                onValueChanged: driverControlElysia.setAcceleration(value)
            }
            IntSpinBox {
                 text: qsTr("Regen Braking")
                 value: driverControlElysia.RegenBraking
                 onValueChanged: driverControlElysia.setRegenBraking(value)
            }

            FlagBox{
                title:"Driver's Input"
                flags:[
                    {
                        text: qsTr("Brakes"),
                        checked: driverControlElysia.Brakes,
                        onClicked: function(checked) {driverControlElysia.setBrakes(checked)}
                    },
                    {
                        text: qsTr("Forward"),
                        checked: driverControlElysia.Forward,
                        onClicked: function(checked) {driverControlElysia.setForward(checked)}
                    },
                    {
                        text: qsTr("Reverse"),
                        checked: driverControlElysia.Reverse,
                        onClicked: function(checked) {driverControlElysia.setReverse(checked)}
                    },
                    {
                        text: qsTr("Push To Talk"),
                        checked: driverControlElysia.PushToTalk,
                        onClicked: function(checked) {driverControlElysia.setPushToTalk(checked)}
                    },
                    {
                        text: qsTr("Horn"),
                        checked: driverControlElysia.Horn,
                        onClicked: function(checked) {driverControlElysia.setHorn(checked)}
                    },
                    {
                        text: qsTr("Reset"),
                        checked: driverControlElysia.Reset,
                        onClicked: function(checked) {driverControlElysia.setReset(checked)}
                    },
                    {
                        text: qsTr("Aux"),
                        checked: driverControlElysia.Aux,
                        onClicked: function(checked) {driverControlElysia.setAux(checked)}
                    },
                    {
                        text: qsTr("Lap"),
                        checked: driverControlElysia.Lap,
                        onClicked: function(checked) {driverControlElysia.setLap(checked)}
                    }
                ]
            }

        }
        BytePreview {
            id: bytePreview
            raw: driverControlElysia.byteStreamStr
            encoded:  driverControlElysia.encodedByteStreamStr
        }
    }
}
