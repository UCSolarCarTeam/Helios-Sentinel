import QtQuick 2.15
import QtQuick.Controls 2.15

import "../Components"

Item {
    width: 550
    height: 1250

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20
        
        Text {
            text: "Battery Packet"
            font.family: "Verdana"
            font.bold: true
        }

        FlagBox {
            title: "BMS Relay Flags"
            flags: [
                {
                    text: "Discharge Relay Enabled",
                    checked: battery.DischargeRelayEnabled,
                    onClicked: function(checked) { battery.setDischargeRelayEnabled(checked) }
                },
                {
                    text: "Charge Relay Enabled",
                    checked: battery.ChargeRelayEnabled,
                    onClicked: function(checked) { battery.setChargeRelayEnabled(checked) }
                },
                {
                    text: "Charger Safety Enabled",
                    checked: battery.ChargerSafetyEnabled,
                    onClicked: function(checked) { battery.setChargerSafetyEnabled(checked) }
                },
                {
                    text: "Malfunction Indicator Enabled",
                    checked: battery.MalfunctionIndicatorEnabled,
                    onClicked: function(checked) { battery.setMalfunctionIndicatorEnabled(checked) }
                },
                {
                    text: "Multi-Purpose Input Signal",
                    checked: battery.MultiPurposeInputSignal,
                    onClicked: function(checked) { battery.setMultiPurposeInputSignal(checked) }
                },
                {
                    text: "Always On Signal",
                    checked: battery.AlwaysOnSignal,
                    onClicked: function(checked) { battery.setAlwaysOnSignal(checked) }
                },
                {
                    text: "Is Ready Signal",
                    checked: battery.IsReadySignal,
                    onClicked: function(checked) { battery.setIsReadySignal(checked) }
                },
                {
                    text: "Is Charging Signal",
                    checked: battery.IsChargingSignal,
                    onClicked: function(checked) { battery.setIsChargingSignal(checked) }
                }
            ]
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Populated Cells"
                    value: battery.PopulatedCells
                    onValueChanged: battery.setPopulatedCells(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Input 12V"
                    value: battery.Input12V
                    onValueChanged: battery.setInput12V(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Fan Voltage"
                    value: battery.FanVoltage
                    onValueChanged: battery.setFanVoltage(value)
                }
            }
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Pack Current"
                    value: battery.PackCurrent
                    onValueChanged: battery.setPackCurrent(value)
                }

                IntSpinBox {
                    text: "Pack Voltage"
                    value: battery.PackVoltage
                    onValueChanged: battery.setPackVoltage(value)
                }

                IntSpinBox {
                    text: "State of Charge"
                    value: battery.PackStateOfCharge
                    onValueChanged: battery.setPackStateOfCharge(value)
                    max: 255
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Pack Amphours"
                    value: battery.PackAmphours
                    onValueChanged: battery.setPackAmphours(value)
                }

                IntSpinBox {
                    text: "Pack Depth of Discharge"
                    value: battery.PackDepthOfDischarge
                    onValueChanged: battery.setPackDepthOfDischarge(value)
                    max: 255
                }
            }
        }
        
        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "High Temperature"
                    value: battery.HighTemperature
                    onValueChanged: battery.setHighTemperature(value)
                    max: 255
                }

                IntSpinBox {
                    text: "High Thermistor ID"
                    value: battery.HighThermistorId
                    onValueChanged: battery.setHighThermistorId(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Low Temperature"
                    value: battery.LowTemperature
                    onValueChanged: battery.setLowTemperature(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Low Thermistor ID"
                    value: battery.LowThermistorId
                    onValueChanged: battery.setLowThermistorId(value)
                    max: 255
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Average Temperature"
                    value: battery.AverageTemperature
                    onValueChanged: battery.setAverageTemperature(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Internal Temperature"
                    value: battery.InternalTemperature
                    onValueChanged: battery.setInternalTemperature(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Fan Speed"
                    value: battery.FanSpeed
                    onValueChanged: battery.setFanSpeed(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Requested Fan Speed"
                    value: battery.RequestedFanSpeed
                    onValueChanged: battery.setRequestedFanSpeed(value)
                    max: 255
                }
            }            
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Low Cell Voltage"
                    value: battery.LowCellVoltage
                    onValueChanged: battery.setLowCellVoltage(value)
                }

                IntSpinBox {
                    text: "Low Cell Voltage ID"
                    value: battery.LowCellVoltageId
                    onValueChanged: battery.setLowCellVoltageId(value)
                    max: 255
                }

                IntSpinBox {
                    text: "High Cell Voltage"
                    value: battery.HighCellVoltage
                    onValueChanged: battery.setHighCellVoltage(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "High Cell Voltage ID"
                    value: battery.HighCellVoltageId
                    onValueChanged: battery.setHighCellVoltageId(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Average Cell Voltage"
                    value: battery.AverageCellVoltage
                    onValueChanged: battery.setAverageCellVoltage(value)
                }
            }
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Max Cell Voltage"
                    value: battery.MaxCellVoltage
                    onValueChanged: battery.setMaxCellVoltage(value)
                }

                IntSpinBox {
                    text: "Min Cell Voltage"
                    value: battery.MinCellVoltage
                    onValueChanged: battery.setMinCellVoltage(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Max Pack Voltage"
                    value: battery.MaxPackVoltage
                    onValueChanged: battery.setMaxPackVoltage(value)
                }

                IntSpinBox {
                    text: "Min Pack Voltage"
                    value: battery.MinPackVoltage
                    onValueChanged: battery.setMinPackVoltage(value)
                }
            }            
        }
    }
}
