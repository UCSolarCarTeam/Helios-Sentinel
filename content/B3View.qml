import QtQuick 2.15
import QtQuick.Controls 6.2

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
                        checked: b3.rightSignalIn,
                        onClicked: function(checked) { b3.setRightSignalIn(checked) }
                    },
                    {
                        text: qsTr("Left Signal"),
                        checked: b3.leftSignalIn,
                        onClicked: function(checked) { b3.setLeftSignalIn(checked) }
                    },
                    {
                        text: qsTr("Hazard Lights"),
                        checked: b3.hazardLights,
                        onClicked: function(checked) { b3.setHazardLights(checked) }
                    },
                    {
                        text: qsTr("Headlights Switch"),
                        checked: b3.headlightsSwitch,
                        onClicked: function(checked) { b3.setHeadlightsSwitch(checked) }
                    },
                    {
                        text: qsTr("Forward Switch"),
                        checked: b3.forwardSwitch,
                        onClicked: function(checked) { b3.setForwardSwitch(checked) }
                    },
                    {
                        text: qsTr("Horn Switch"),
                        checked: b3.hornSwitch,
                        onClicked: function(checked) { b3.setHornSwitch(checked) }
                    },
                    {
                        text: qsTr("Forward"),
                        checked: b3.forward,
                        onClicked: function(checked) { b3.setForward(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Driver Inputs"
                flags: [
                    {
                        text: qsTr("Neutral"),
                        checked: b3.neutral,
                        onClicked: function(checked) { b3.setNeutral(checked) }
                    },
                    {
                        text: qsTr("Reverse"),
                        checked: b3.reverse,
                        onClicked: function(checked) { b3.setReverse(checked) }
                    },
                    {
                        text: qsTr("Brake Switch"),
                        checked: b3.brakeSwitch,
                        onClicked: function(checked) { b3.setBrakeSwitch(checked) }
                    },
                    {
                        text: qsTr("Handbrake Switch"),
                        checked: b3.handbrakeSwitch,
                        onClicked: function(checked) { b3.setHandbrakeSwitch(checked) }
                    },
                    {
                        text: qsTr("Motor Reset"),
                        checked: b3.motorReset,
                        onClicked: function(checked) { b3.setMotorReset(checked) }
                    },
                    {
                        text: qsTr("Race Mode"),
                        checked: b3.raceMode,
                        onClicked: function(checked) { b3.setRaceMode(checked) }
                    },
                    {
                        text: qsTr("Lap"),
                        checked: b3.lap,
                        onClicked: function(checked) { b3.setLap(checked) }
                    },
                    {
                        text: qsTr("Zoom Zoom"),
                        checked: b3.zoomZoom,
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
                        value: b3.acceleration
                        onValueChanged: b3.setAcceleration(value)
                    }
                }
                Column{
                    spacing: 20
                    width: 245

                    IntSpinBox {
                            text: qsTr("Regen Braking")
                            value: b3.regenBraking
                            onValueChanged: b3.setRegenBraking(value)
                        }
                    }
            }
            
            

            FlagBox {
                title: "Lights Output"
                flags: [
                    {
                        text: qsTr("Right Signal"),
                        checked: b3.rightSignalOut,
                        onClicked: function(checked) { b3.setRightSignalOut(checked) }
                    },
                    {
                        text: qsTr("Left Signal"),
                        checked: b3.leftSignalOut,
                        onClicked: function(checked) { b3.setLeftSignalOut(checked) }
                    },
                    {
                        text: qsTr("Daytime Running Light Signal"),
                        checked: b3.daytimeRunningLightSignal,
                        onClicked: function(checked) { b3.setDaytimeRunningLightSignal(checked) }
                    },
                    {
                        text: qsTr("Headlight Signal"),
                        checked: b3.headlightSignal,
                        onClicked: function(checked) { b3.setHeadlightSignal(checked) }
                    },
                    {
                        text: qsTr("Brake Light Signal"),
                        checked: b3.brakeLightSignal,
                        onClicked: function(checked) { b3.setBrakeLightSignal(checked) }
                    },
                    {
                        text: qsTr("Horn Signal"),
                        checked: b3.hornSignal,
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
