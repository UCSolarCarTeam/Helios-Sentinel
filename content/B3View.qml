import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 550
    height: 650
    
    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "B^3 Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Column {
            spacing: 20

            FlagBox {
                title: "Lights Input"
                flags: [
                    
                    {
                        text: qsTr("Right Signal"),
                        checked: b3.RightSignalIn,
                        onClicked: function(checked) { b3.setRightSignalIn(checked) }
                    },
                    {
                        text: qsTr("Left Signal"),
                        checked: b3.LeftSignalIn,
                        onClicked: function(checked) { b3.setLeftSignalIn(checked) }
                    },
                    {
                        text: qsTr("Hazard Lights"),
                        checked: b3.HazardLights,
                        onClicked: function(checked) { b3.setHazardLights(checked) }
                    },
                    {
                        text: qsTr("Headlights Switch"),
                        checked: b3.HeadlightsSwitch,
                        onClicked: function(checked) { b3.setHeadlightsSwitch(checked) }
                    },
                    {
                        text: qsTr("Forward Switch"),
                        checked: b3.ForwardSwitch,
                        onClicked: function(checked) { b3.setForwardSwitch(checked) }
                    },
                    {
                        text: qsTr("Horn Switch"),
                        checked: b3.HornSwitch,
                        onClicked: function(checked) { b3.setHornSwitch(checked) }
                    },
                    {
                        text: qsTr("Forward"),
                        checked: b3.Forward,
                        onClicked: function(checked) { b3.setForward(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Driver Inputs"
                flags: [
                    {
                        text: qsTr("Neutral"),
                        checked: b3.Neutral,
                        onClicked: function(checked) { b3.setNeutral(checked) }
                    },
                    {
                        text: qsTr("Reverse"),
                        checked: b3.Reverse,
                        onClicked: function(checked) { b3.setReverse(checked) }
                    },
                    {
                        text: qsTr("Brake Switch"),
                        checked: b3.BrakeSwitch,
                        onClicked: function(checked) { b3.setBrakeSwitch(checked) }
                    },
                    {
                        text: qsTr("Handbrake Switch"),
                        checked: b3.HandbrakeSwitch,
                        onClicked: function(checked) { b3.setHandbrakeSwitch(checked) }
                    },
                    {
                        text: qsTr("Motor Reset"),
                        checked: b3.MotorReset,
                        onClicked: function(checked) { b3.setMotorReset(checked) }
                    },
                    {
                        text: qsTr("Race Mode"),
                        checked: b3.RaceMode,
                        onClicked: function(checked) { b3.setRaceMode(checked) }
                    },
                    {
                        text: qsTr("Lap"),
                        checked: b3.Lap,
                        onClicked: function(checked) { b3.setLap(checked) }
                    },
                    {
                        text: qsTr("Zoom Zoom"),
                        checked: b3.ZoomZoom,
                        onClicked: function(checked) { b3.setZoomZoom(checked) }
                    }
                ]
            }


            Row {
                spacing: 20
                Column{
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Acceleration")
                        value: b3.Acceleration
                        onValueChanged: b3.setAcceleration(value)
                    }
                }
                Column{
                    spacing: 20
                    width: 245

                    IntSpinBox {
                            text: qsTr("Regen Braking")
                            value: b3.RegenBraking
                            onValueChanged: b3.setRegenBraking(value)
                        }
                    }
            }
            
            

            FlagBox {
                title: "Lights Output"
                flags: [
                    {
                        text: qsTr("Right Signal"),
                        checked: b3.RightSignalOut,
                        onClicked: function(checked) { b3.setRightSignalOut(checked) }
                    },
                    {
                        text: qsTr("Left Signal"),
                        checked: b3.LeftSignalOut,
                        onClicked: function(checked) { b3.setLeftSignalOut(checked) }
                    },
                    {
                        text: qsTr("Daytime Running Light Signal"),
                        checked: b3.DaytimeRunningLightSignal,
                        onClicked: function(checked) { b3.setDaytimeRunningLightSignal(checked) }
                    },
                    {
                        text: qsTr("Headlight Signal"),
                        checked: b3.HeadlightSignal,
                        onClicked: function(checked) { b3.setHeadlightSignal(checked) }
                    },
                    {
                        text: qsTr("Brake Light Signal"),
                        checked: b3.BrakeLightSignal,
                        onClicked: function(checked) { b3.setBrakeLightSignal(checked) }
                    },
                    {
                        text: qsTr("Horn Signal"),
                        checked: b3.HornSignal,
                        onClicked: function(checked) { b3.setHornSignal(checked) }
                    }
                ]
            }
        }

        BytePreview {
            id: bytePreview
            raw: b3.byteStreamStr
            encoded: b3.encodedByteStreamStr
        }
    }
}
