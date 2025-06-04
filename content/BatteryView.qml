import QtQuick 2.15
import QtQuick.Controls 2.15

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

        FlagBox {
            title: "Error Flags"
            flags: [
                {
                    text: "DCL Reduced Low SOC",
                    checked: battery.DclReducedLowSOC,
                    onClicked: function(checked) { battery.setDclReducedLowSOC(checked) }
                },
                {
                    text: "DCL Reduced High Cell Resistance",
                    checked: battery.DclReducedHighCellResistance,
                    onClicked: function(checked) { battery.setDclReducedHighCellResistance(checked) }
                },
                {
                    text: "DCL Reduced Temp",
                    checked: battery.DclReducedTemp,
                    onClicked: function(checked) { battery.setDclReducedTemp(checked) }
                },
                {
                    text: "DCL Reduced Low Cell Voltage",
                    checked: battery.DclReducedLowCellVoltage,
                    onClicked: function(checked) { battery.setDclReducedLowCellVoltage(checked) }
                },
                {
                    text: "DCL Reduced Low Pack Voltage",
                    checked: battery.DclReducedLowPackVoltage,
                    onClicked: function(checked) { battery.setDclReducedLowPackVoltage(checked) }
                },
                {
                    text: "DCL CCL Reduced Voltage Failsafe",
                    checked: battery.DclCclReducedVoltageFailsafe,
                    onClicked: function(checked) { battery.setDclCclReducedVoltageFailsafe(checked) }
                },
                {
                    text: "DCL CCL Reduced Communication Failsafe",
                    checked: battery.DclCclReducedCommunicationFailsafe,
                    onClicked: function(checked) { battery.setDclCclReducedCommunicationFailsafe(checked) }
                },
                {
                    text: "CCL Reduced High SOC",
                    checked: battery.CclReducedHighSoc,
                    onClicked: function(checked) { battery.setCclReducedHighSoc(checked) }
                },
                {
                    text: "CCL Reduced High Cell Resistance",
                    checked: battery.CclReducedHighCellResistance,
                    onClicked: function(checked) { battery.setCclReducedHighCellResistance(checked) }
                },
                {
                    text: "CCL Reduced Temp",
                    checked: battery.CclReducedTemp,
                    onClicked: function(checked) { battery.setCclReducedTemp(checked) }
                },
                {
                    text: "CCL Reduced High Cell Voltage",
                    checked: battery.CclReducedHighCellVoltage,
                    onClicked: function(checked) { battery.setCclReducedHighCellVoltage(checked) }
                },
                {
                    text: "CCL Reduced High Pack Voltage",
                    checked: battery.CclReducedHighPackVoltage,
                    onClicked: function(checked) { battery.setCclReducedHighPackVoltage(checked) }
                },
                {
                    text: "CCL Reduced Charger Latch",
                    checked: battery.CclReducedChargerLatch,
                    onClicked: function(checked) { battery.setCclReducedChargerLatch(checked) }
                },
                {
                    text: "CCL Reduced Alternate Current Limit",
                    checked: battery.CclReducedAlternateCurrrentLimit,
                    onClicked: function(checked) { battery.setCclReducedAlternateCurrrentLimit(checked) }
                },
                {
                    text: "Internal Communication",
                    checked: battery.InternalCommunication,
                    onClicked: function(checked) { battery.setInternalCommunication(checked) }
                },
                {
                    text: "Internal Conversion",
                    checked: battery.InternalConversion,
                    onClicked: function(checked) { battery.setInternalConversion(checked) }
                },
                {
                    text: "Weak Cell",
                    checked: battery.WeakCell,
                    onClicked: function(checked) { battery.setWeakCell(checked) }
                },
                {
                    text: "Low Cell Voltage Fault",
                    checked: battery.LowCellVoltageFault,
                    onClicked: function(checked) { battery.setLowCellVoltageFault(checked) }
                },
                {
                    text: "Open Wiring",
                    checked: battery.OpenWiring,
                    onClicked: function(checked) { battery.setOpenWiring(checked) }
                },
                {
                    text: "Current Sensor",
                    checked: battery.CurrentSensor,
                    onClicked: function(checked) { battery.setCurrentSensor(checked) }
                },
                {
                    text: "Pack Voltage Sensor",
                    checked: battery.PackVoltageSensor,
                    onClicked: function(checked) { battery.setPackVoltageSensor(checked) }
                },
                {
                    text: "Weak Pack",
                    checked: battery.WeakPack,
                    onClicked: function(checked) { battery.setWeakPack(checked) }
                },
                {
                    text: "Voltage Redundancy",
                    checked: battery.VoltageRedundacy,
                    onClicked: function(checked) { battery.setVoltageRedundacy(checked) }
                },
                {
                    text: "Fan Monitor",
                    checked: battery.FanMonitor,
                    onClicked: function(checked) { battery.setFanMonitor(checked) }
                },
                {
                    text: "Thermistor",
                    checked: battery.Thermistor,
                    onClicked: function(checked) { battery.setThermistor(checked) }
                },
                {
                    text: "Canbus Communications",
                    checked: battery.CanbusCommunications,
                    onClicked: function(checked) { battery.setCanbusCommunications(checked) }
                },
                {
                    text: "Always On Supply",
                    checked: battery.AlwaysOnSupply,
                    onClicked: function(checked) { battery.setAlwaysOnSupply(checked) }
                },
                {
                    text: "High Voltage Isolation",
                    checked: battery.HighVoltageIsolation,
                    onClicked: function(checked) { battery.setHighVoltageIsolation(checked) }
                },
                {
                    text: "Power Supply 12V",
                    checked: battery.PowerSupply12V,
                    onClicked: function(checked) { battery.setPowerSupply12V(checked) }
                },
                {
                    text: "Charge Limit Enforcement",
                    checked: battery.ChargeLimitEnforcement,
                    onClicked: function(checked) { battery.setChargeLimitEnforcement(checked) }
                },
                {
                    text: "Discharge Safety Relay",
                    checked: battery.DischargeSafetyRelay,
                    onClicked: function(checked) { battery.setDischargeSafetyRelay(checked) }
                },
                {
                    text: "Charger Safety Relay",
                    checked: battery.ChargerSafetyRelay,
                    onClicked: function(checked) { battery.setChargerSafetyRelay(checked) }
                },
                {
                    text: "Internal Memory",
                    checked: battery.InternalMemory,
                    onClicked: function(checked) { battery.setInternalMemory(checked) }
                },
                {
                    text: "Internal Thermistor",
                    checked: battery.InternalThermistor,
                    onClicked: function(checked) { battery.setInternalThermistor(checked) }
                },
                {
                    text: "Internal Logic",
                    checked: battery.InternalLogic,
                    onClicked: function(checked) { battery.setInternalLogic(checked) }
                }
            ]
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
