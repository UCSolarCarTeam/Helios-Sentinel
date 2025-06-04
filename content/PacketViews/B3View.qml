import QtQuick 2.15
import QtQuick.Controls 2.15

import "../Components"

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
                        checked: b3.HazardLightsIn,
                        onClicked: function(checked) { b3.setHazardLightsIn(checked) }
                    },
                    {
                        text: qsTr("Headlights Switch"),
                        checked: b3.HeadlightsIn,
                        onClicked: function(checked) { b3.setHeadlightsIn(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Driver Inputs"
                flags: [
                    {
                        text: qsTr("Forward"),
                        checked: b3.Forward,
                        onClicked: function(checked) { b3.setForward(checked) }
                    },
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
                        text: qsTr("Horn Switch"),
                        checked: b3.Horn,
                        onClicked: function(checked) { b3.setHorn(checked) }
                    },

                    {
                        text: qsTr("Brake Switch"),
                        checked: b3.Brake,
                        onClicked: function(checked) { b3.setBrake(checked) }
                    },
                    {
                        text: qsTr("Handbrake Switch"),
                        checked: b3.Handbrake,
                        onClicked: function(checked) { b3.setHandbrake(checked) }
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
                        min: 0
                        max: 255
                    }
                }
                Column{
                    spacing: 20
                    width: 245

                    IntSpinBox {
                            text: qsTr("Regen Braking")
                            value: b3.RegenBraking
                            onValueChanged: b3.setRegenBraking(value)
                            min: 0
                            max: 255
                        }
                    }
            }
            
            FlagBox {
                title: "Lights Output"
                flags: [
                    {
                        text: qsTr("Right Signal"),
                        checked: b3.RightSignalStatus,
                        onClicked: function(checked) { b3.setRightSignalStatus(checked) }
                    },
                    {
                        text: qsTr("Left Signal"),
                        checked: b3.LeftSignalStatus,
                        onClicked: function(checked) { b3.setLeftSignalStatus(checked) }
                    },
                    {
                        text: qsTr("Daytime Running Light Signal"),
                        checked: b3.DaytimeRunningLightStatus,
                        onClicked: function(checked) { b3.setDaytimeRunningLightStatus(checked) }
                    },
                    {
                        text: qsTr("Headlight Signal"),
                        checked: b3.HeadlightStatus,
                        onClicked: function(checked) { b3.setHeadlightStatus(checked) }
                    },
                    {
                        text: qsTr("Brake Light Signal"),
                        checked: b3.BrakeLightStatus,
                        onClicked: function(checked) { b3.setBrakeLightStatus(checked) }
                    },
                    {
                        text: qsTr("Horn Signal"),
                        checked: b3.HornStatus,
                        onClicked: function(checked) { b3.setHornStatus(checked) }
                    }
                ]
            }
        }
    }
}
