import QtQuick 2.15
import QtQuick.Controls 2.15
import '..'
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
                checked: batteryElysia.BmuAlive
                onClicked: batteryElysia.setBmuAlive(checked)
            }

            FlagBox {
                title: "BMS Relay Flags"
                flags: [
                    {
                        text: qsTr("Discharge Relay"),
                        checked: batteryElysia.DischargeRelay,
                        onClicked: function(checked) { batteryElysia.setDischargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charge Relay"),
                        checked: batteryElysia.ChargeRelay,
                        onClicked: function(checked) { batteryElysia.setChargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charger Safety"),
                        checked: batteryElysia.ChargerSafety,
                        onClicked: function(checked) { batteryElysia.setChargerSafety(checked) }
                    },
                    {
                        text: qsTr("Malfunction Indicator"),
                        checked: batteryElysia.MalfunctionIndicator,
                        onClicked: function(checked) { batteryElysia.setMalfunctionIndicator(checked) }
                    },
                    {
                        text: qsTr("Multi-Purpose Input Signal"),
                        checked: batteryElysia.MultiPurposeInputSignal,
                        onClicked: function(checked) { batteryElysia.setMultiPurposeInputSignal(checked) }
                    },
                    {
                        text: qsTr("Always-on Signal"),
                        checked: batteryElysia.AlwaysOnSignal,
                        onClicked: function(checked) { batteryElysia.setAlwaysOnSignal(checked) }
                    },
                    {
                        text: qsTr("Is-Ready Signal"),
                        checked: batteryElysia.IsReadySignal,
                        onClicked: function(checked) { batteryElysia.setIsReadySignal(checked) }
                    },
                    {
                        text: qsTr("Is-Charging Signal"),
                        checked: batteryElysia.IsChargingSignal,
                        onClicked: function(checked) { batteryElysia.setIsChargingSignal(checked) }
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
                        value: batteryElysia.PopulatedCells
                        onValueChanged: batteryElysia.setPopulatedCells(value)
                    }

                    FloatSpinBox {
                        text: qsTr("12V Input")
                        inputValue: batteryElysia.Input12V
                        onInputValueUpdated: batteryElysia.setInput12V(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Fan Voltage")
                        inputValue: batteryElysia.FanVoltage
                        onInputValueChanged: batteryElysia.setFanVoltage(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack Current")
                        inputValue: batteryElysia.PackCurrent
                        onInputValueChanged: batteryElysia.setPackCurrent(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack Voltage")
                        inputValue: batteryElysia.PackVoltage
                        onInputValueChanged: batteryElysia.setPackVoltage(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack SOC")
                        inputValue: batteryElysia.PackSoc
                        onInputValueChanged: batteryElysia.setPackSoc(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack Amphours")
                        inputValue: batteryElysia.PackAmphours
                        onInputValueChanged: batteryElysia.setPackAmphours(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack DOD")
                        inputValue: batteryElysia.PackDod
                        onInputValueChanged: batteryElysia.setPackDod(inputValue)
                    }

                    IntSpinBox {
                        text: qsTr("High Temp")
                        value: batteryElysia.HighTemp
                        onValueChanged: batteryElysia.setHighTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Thermistor ID")
                        value: batteryElysia.HighThermistorId
                        onValueChanged: batteryElysia.setHighThermistorId(value)
                    }
                }

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Low Temp")
                        value: batteryElysia.LowTemp
                        onValueChanged: batteryElysia.setLowTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Thermistor ID")
                        value: batteryElysia.LowThermistorId
                        onValueChanged: batteryElysia.setLowThermistorId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Temp")
                        value: batteryElysia.AvgTemp
                        onValueChanged: batteryElysia.setAvgTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Internal Temp")
                        value: batteryElysia.InternalTemp
                        onValueChanged: batteryElysia.setInternalTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Fan Speed")
                        value: batteryElysia.FanSpeed
                        onValueChanged: batteryElysia.setFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Req. Fan Speed")
                        value: batteryElysia.ReqFanSpeed
                        onValueChanged: battery.setReqFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage")
                        value: batteryElysia.LowCellVoltage
                        onValueChanged: batteryElysia.setLowCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage ID")
                        value: batteryElysia.LowCellVoltageId
                        onValueChanged: batteryElysia.setLowCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage")
                        value: batteryElysia.HighCellVoltage
                        onValueChanged: batteryElysia.setHighCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage ID")
                        value: batteryElysia.HighCellVoltageId
                        onValueChanged: batteryElysia.setHighCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Cell Voltage")
                        value: batteryElysia.AvgCellVoltage
                        onValueChanged: batteryElysia.setAvgCellVoltage(value)
                    }
                }
            }
        }

        BytePreview {
            id: bytePreview
            raw: batteryElysia.byteStreamStr
            encoded: batteryElysia.encodedByteStreamStr
        }
    }
}
