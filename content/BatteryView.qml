import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 550
    height: 850

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20
        
        Text {
            text: "Battery Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Column {
            spacing: 20

            Switch {
                id: switch1
                text: qsTr("BMU Alive")
                checked: battery.alive
                onClicked: battery.setBmuAlive(checked)
            }

            FlagBox {
                title: "BMS Relay Flags"
                flags: [
                    {
                        text: qsTr("Discharge Relay"),
                        checked: battery.dischargeRelay,
                        onClicked: function(checked) { battery.setDischargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charge Relay"),
                        checked: battery.chargeRelay,
                        onClicked: function(checked) { battery.setChargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charger Safety"),
                        checked: battery.chargerSafety,
                        onClicked: function(checked) { battery.setChargerSafety(checked) }
                    },
                    {
                        text: qsTr("Malfunction Indicator"),
                        checked: battery.malfunctionIndicator,
                        onClicked: function(checked) { battery.setMalfunctionIndicator(checked) }
                    },
                    {
                        text: qsTr("Multi-Purpose Input Signal"),
                        checked: battery.multiPurposeInputSignal,
                        onClicked: function(checked) { battery.setMultiPurposeInputSignal(checked) }
                    },
                    {
                        text: qsTr("Always-on Signal"),
                        checked: battery.alwaysOnSignal,
                        onClicked: function(checked) { battery.setAlwaysOnSignal(checked) }
                    },
                    {
                        text: qsTr("Is-Ready Signal"),
                        checked: battery.isReadySignal,
                        onClicked: function(checked) { battery.setIsReadySignal(checked) }
                    },
                    {
                        text: qsTr("Is-Charging Signal"),
                        checked: battery.isChargingSignal,
                        onClicked: function(checked) { battery.setIsChargingSignal(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Populated Cells")
                        value: battery.populatedCells
                        onValueChanged: battery.setPopulatedCells(value)
                    }

                    IntSpinBox {
                        text: qsTr("12V Input")
                        value: battery.input12V
                        onValueChanged: battery.setInput12V(value)
                    }

                    IntSpinBox {
                        text: qsTr("Fan Voltage")
                        value: battery.fanVoltage
                        onValueChanged: battery.setFanVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack Current")
                        value: battery.packCurrent
                        onValueChanged: battery.setPackCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack Voltage")
                        value: battery.packVoltage
                        onValueChanged: battery.setPackVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack SOC")
                        value: battery.packSoc
                        onValueChanged: battery.setPackSoc(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack Amphours")
                        value: battery.packAmphours
                        onValueChanged: battery.setPackAmphours(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack DOD")
                        value: battery.packDod
                        onValueChanged: battery.setPackDod(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Temp")
                        value: battery.highTemp
                        onValueChanged: battery.setHighTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Thermistor ID")
                        value: battery.highThermistorId
                        onValueChanged: battery.setHighThermistorId(value)
                    }
                }

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Low Temp")
                        value: battery.lowTemp
                        onValueChanged: battery.setLowTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Thermistor ID")
                        value: battery.lowThermistorId
                        onValueChanged: battery.setLowThermistorId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Temp")
                        value: battery.avgTemp
                        onValueChanged: battery.setAvgTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Internal Temp")
                        value: battery.internalTemp
                        onValueChanged: battery.setInternalTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Fan Speed")
                        value: battery.fanSpeed
                        onValueChanged: battery.setFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Req. Fan Speed")
                        value: battery.reqFanSpeed
                        onValueChanged: battery.setReqFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage")
                        value: battery.lowCellVoltage
                        onValueChanged: battery.setLowCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage ID")
                        value: battery.lowCellVoltageId
                        onValueChanged: battery.setLowCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage")
                        value: battery.highCellVoltage
                        onValueChanged: battery.setHighCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage ID")
                        value: battery.highCellVoltageId
                        onValueChanged: battery.setHighCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Cell Voltage")
                        value: battery.avgCellVoltage
                        onValueChanged: battery.setAvgCellVoltage(value)
                    }
                }
            }
        }

        BytePreview {
            id: bytePreview
            raw: battery.byteStreamStr
            encoded: battery.encodedByteStreamStr
        }
    }
}
