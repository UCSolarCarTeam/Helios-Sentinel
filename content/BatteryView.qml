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
                checked: battery.BmuAlive
                onClicked: battery.setBmuAlive(checked)
            }

            FlagBox {
                title: "BMS Relay Flags"
                flags: [
                    {
                        text: qsTr("Discharge Relay"),
                        checked: battery.DischargeRelay,
                        onClicked: function(checked) { battery.setDischargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charge Relay"),
                        checked: battery.ChargeRelay,
                        onClicked: function(checked) { battery.setChargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charger Safety"),
                        checked: battery.ChargerSafety,
                        onClicked: function(checked) { battery.setChargerSafety(checked) }
                    },
                    {
                        text: qsTr("Malfunction Indicator"),
                        checked: battery.MalfunctionIndicator,
                        onClicked: function(checked) { battery.setMalfunctionIndicator(checked) }
                    },
                    {
                        text: qsTr("Multi-Purpose Input Signal"),
                        checked: battery.MultiPurposeInputSignal,
                        onClicked: function(checked) { battery.setMultiPurposeInputSignal(checked) }
                    },
                    {
                        text: qsTr("Always-on Signal"),
                        checked: battery.AlwaysOnSignal,
                        onClicked: function(checked) { battery.setAlwaysOnSignal(checked) }
                    },
                    {
                        text: qsTr("Is-Ready Signal"),
                        checked: battery.IsReadySignal,
                        onClicked: function(checked) { battery.setIsReadySignal(checked) }
                    },
                    {
                        text: qsTr("Is-Charging Signal"),
                        checked: battery.IsChargingSignal,
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
                        range: { "from": 0, "to": 255 }
                        value: battery.PopulatedCells
                        onValueChanged: battery.setPopulatedCells(value)
                    }

                    FloatSpinBox {
                        text: qsTr("12V Input")
                        inputValue: battery.Input12V
                        onInputValueUpdated: battery.setInput12V(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Fan Voltage")
                        inputValue: battery.FanVoltage
                        onInputValueChanged: battery.setFanVoltage(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack Current")
                        inputValue: battery.PackCurrent
                        onInputValueChanged: battery.setPackCurrent(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack Voltage")
                        inputValue: battery.PackVoltage
                        onInputValueChanged: battery.setPackVoltage(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack SOC")
                        inputValue: battery.PackSoc
                        onInputValueChanged: battery.setPackSoc(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack Amphours")
                        inputValue: battery.PackAmphours
                        onInputValueChanged: battery.setPackAmphours(inputValue)
                    }

                    FloatSpinBox {
                        text: qsTr("Pack DOD")
                        inputValue: battery.PackDod
                        onInputValueChanged: battery.setPackDod(inputValue)
                    }

                    IntSpinBox {
                        text: qsTr("High Temp")
                        range: { "from": 0, "to": 255 }
                        value: battery.HighTemp
                        onValueChanged: battery.setHighTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Thermistor ID")
                        range: { "from": 0, "to": 255 }
                        value: battery.HighThermistorId
                        onValueChanged: battery.setHighThermistorId(value)
                    }
                }

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Low Temp")
                        range: { "from": 0, "to": 255 }
                        value: battery.LowTemp
                        onValueChanged: battery.setLowTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Thermistor ID")
                        range: { "from": 0, "to": 255 }
                        value: battery.LowThermistorId
                        onValueChanged: battery.setLowThermistorId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Temp")
                        range: { "from": 0, "to": 255 }
                        value: battery.AvgTemp
                        onValueChanged: battery.setAvgTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Internal Temp")
                        range: { "from": 0, "to": 255 }
                        value: battery.InternalTemp
                        onValueChanged: battery.setInternalTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Fan Speed")
                        range: { "from": 0, "to": 255 }
                        value: battery.FanSpeed
                        onValueChanged: battery.setFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Req. Fan Speed")
                        range: { "from": 0, "to": 255 }
                        value: battery.ReqFanSpeed
                        onValueChanged: battery.setReqFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage")
                        value: battery.LowCellVoltage
                        onValueChanged: battery.setLowCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage ID")
                        range: { "from": 0, "to": 255 }
                        value: battery.LowCellVoltageId
                        onValueChanged: battery.setLowCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage")
                        value: battery.HighCellVoltage
                        onValueChanged: battery.setHighCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage ID")
                        range: { "from": 0, "to": 255 }
                        value: battery.HighCellVoltageId
                        onValueChanged: battery.setHighCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Cell Voltage")
                        value: battery.AvgCellVoltage
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
