import QtQuick 2.15

import "../Components"

Item {
    width: 550
    height: 550

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Battery Faults Packet"
            font.family: "Verdana"
            font.bold: true
        }

        FlagBox {
            title: "Current Limit Status"
            flags: [
                {
                    text: "DCL Reduced Due To Low SOC",
                    checked: batteryFaults.DclReducedDueToLowSoc,
                    onClicked: function(checked) { batteryFaults.setDclReducedDueToLowSoc(checked) }
                },
                {
                    text: "DCL Reduced Due To High Cell Resistance",
                    checked: batteryFaults.DclReducedDueToHighCellResistance,
                    onClicked: function(checked) { batteryFaults.setDclReducedDueToHighCellResistance(checked) }
                },
                {
                    text: "DCL Reduced Due To Temperature",
                    checked: batteryFaults.DclReducedDueToTemperature,
                    onClicked: function(checked) { batteryFaults.setDclReducedDueToTemperature(checked) }
                },
                {
                    text: "DCL Reduced Due To Low Cell Voltage",
                    checked: batteryFaults.DclReducedDueToLowCellVoltage,
                    onClicked: function(checked) { batteryFaults.setDclReducedDueToLowCellVoltage(checked) }
                },
                {
                    text: "DCL Reduced Due To Low Pack Voltage",
                    checked: batteryFaults.DclReducedDueToLowPackVoltage,
                    onClicked: function(checked) { batteryFaults.setDclReducedDueToLowPackVoltage(checked) }
                },
                {
                    text: "DCL And CCL Reduced Due To Voltage Failsafe",
                    checked: batteryFaults.DclAndCclReducedDueToVoltageFailsafe,
                    onClicked: function(checked) { batteryFaults.setDclAndCclReducedDueToVoltageFailsafe(checked) }
                },
                {
                    text: "DCL And CCL Reduced Due To Communication Failsafe",
                    checked: batteryFaults.DclAndCclReducedDueToCommunicationFailsafe,
                    onClicked: function(checked) { batteryFaults.setDclAndCclReducedDueToCommunicationFailsafe(checked) }
                },
                {
                    text: "CCL Reduced Due To High SOC",
                    checked: batteryFaults.CclReducedDueToHighSoc,
                    onClicked: function(checked) { batteryFaults.setCclReducedDueToHighSoc(checked) }
                },
                {
                    text: "CCL Reduced Due To High Cell Resistance",
                    checked: batteryFaults.CclReducedDueToHighCellResistance,
                    onClicked: function(checked) { batteryFaults.setCclReducedDueToHighCellResistance(checked) }
                },
                {
                    text: "CCL Reduced Due To Temperature",
                    checked: batteryFaults.CclReducedDueToTemperature,
                    onClicked: function(checked) { batteryFaults.setCclReducedDueToTemperature(checked) }
                },
                {
                    text: "CCL Reduced Due To High Cell Voltage",
                    checked: batteryFaults.CclReducedDueToHighCellVoltage,
                    onClicked: function(checked) { batteryFaults.setCclReducedDueToHighCellVoltage(checked) }
                },
                {
                    text: "CCL Reduced Due To High Pack Voltage",
                    checked: batteryFaults.CclReducedDueToHighPackVoltage,
                    onClicked: function(checked) { batteryFaults.setCclReducedDueToHighPackVoltage(checked) }
                },
                {
                    text: "CCL Reduced Due To Charger Latch",
                    checked: batteryFaults.CclReducedDueToChargerLatch,
                    onClicked: function(checked) { batteryFaults.setCclReducedDueToChargerLatch(checked) }
                },
                {
                    text: "CCL Reduced Due To Alternate Current Limit",
                    checked: batteryFaults.CclReducedDueToAlternateCurrentLimit,
                    onClicked: function(checked) { batteryFaults.setCclReducedDueToAlternateCurrentLimit(checked) }
                }
            ]
        }

        FlagBox {
            title: "DTCs"
            flags: [
                {
                    text: "Internal Communication Fault",
                    checked: batteryFaults.InternalCommunicationFault,
                    onClicked: function(checked) { batteryFaults.setInternalCommunicationFault(checked) }
                },
                {
                    text: "Internal Conversion Fault",
                    checked: batteryFaults.InternalConversionFault,
                    onClicked: function(checked) { batteryFaults.setInternalConversionFault(checked) }
                },
                {
                    text: "Weak Cell Fault",
                    checked: batteryFaults.WeakCellFault,
                    onClicked: function(checked) { batteryFaults.setWeakCellFault(checked) }
                },
                {
                    text: "Low Cell Voltage Fault",
                    checked: batteryFaults.LowCellVoltageFault,
                    onClicked: function(checked) { batteryFaults.setLowCellVoltageFault(checked) }
                },
                {
                    text: "Open Wiring Fault",
                    checked: batteryFaults.OpenWiringFault,
                    onClicked: function(checked) { batteryFaults.setOpenWiringFault(checked) }
                },
                {
                    text: "Current Sensor Fault",
                    checked: batteryFaults.CurrentSensorFault,
                    onClicked: function(checked) { batteryFaults.setCurrentSensorFault(checked) }
                },
                {
                    text: "Pack Voltage Sensor Fault",
                    checked: batteryFaults.PackVoltageSensorFault,
                    onClicked: function(checked) { batteryFaults.setPackVoltageSensorFault(checked) }
                },
                {
                    text: "Weak Pack Fault",
                    checked: batteryFaults.WeakPackFault,
                    onClicked: function(checked) { batteryFaults.setWeakPackFault(checked) }
                },
                {
                    text: "Voltage Redundancy Fault",
                    checked: batteryFaults.VoltageRedundancyFault,
                    onClicked: function(checked) { batteryFaults.setVoltageRedundancyFault(checked) }
                },
                {
                    text: "Fan Monitor Fault",
                    checked: batteryFaults.FanMonitorFault,
                    onClicked: function(checked) { batteryFaults.setFanMonitorFault(checked) }
                },
                {
                    text: "Thermistor Fault",
                    checked: batteryFaults.ThermistorFault,
                    onClicked: function(checked) { batteryFaults.setThermistorFault(checked) }
                },
                {
                    text: "Canbus Communications Fault",
                    checked: batteryFaults.CanbusCommunicationsFault,
                    onClicked: function(checked) { batteryFaults.setCanbusCommunicationsFault(checked) }
                },
                {
                    text: "Always On Supply Fault",
                    checked: batteryFaults.AlwaysOnSupplyFault,
                    onClicked: function(checked) { batteryFaults.setAlwaysOnSupplyFault(checked) }
                },
                {
                    text: "High Voltage Isolation Fault",
                    checked: batteryFaults.HighVoltageIsolationFault,
                    onClicked: function(checked) { batteryFaults.setHighVoltageIsolationFault(checked) }
                },
                {
                    text: "Power Supply Fault",
                    checked: batteryFaults.PowerSupplyFault,
                    onClicked: function(checked) { batteryFaults.setPowerSupplyFault(checked) }
                },
                {
                    text: "Charge Limit Enforcement Fault",
                    checked: batteryFaults.ChargeLimitEnforcementFault,
                    onClicked: function(checked) { batteryFaults.setChargeLimitEnforcementFault(checked) }
                },
                {
                    text: "Discharge Limit Enforcement Fault",
                    checked: batteryFaults.DischargeLimitEnforcementFault,
                    onClicked: function(checked) { batteryFaults.setDischargeLimitEnforcementFault(checked) }
                },
                {
                    text: "Charger Safety Relay Fault",
                    checked: batteryFaults.ChargerSafetyRelayFault,
                    onClicked: function(checked) { batteryFaults.setChargerSafetyRelayFault(checked) }
                },
                {
                    text: "Internal Memory Fault",
                    checked: batteryFaults.InternalMemoryFault,
                    onClicked: function(checked) { batteryFaults.setInternalMemoryFault(checked) }
                },
                {
                    text: "Internal Thermistor Fault",
                    checked: batteryFaults.InternalThermistorFault,
                    onClicked: function(checked) { batteryFaults.setInternalThermistorFault(checked) }
                },
                {
                    text: "Internal Logic Fault",
                    checked: batteryFaults.InternalLogicFault,
                    onClicked: function(checked) { batteryFaults.setInternalLogicFault(checked) }
                }
            ]
        }
    }
}
