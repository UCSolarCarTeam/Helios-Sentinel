import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 550
    height: 450

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Battery Faults Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Column {
            spacing: 20

            FlagBox {
                title: "Battery Faults"
                flags: [
                    {
                        text: qsTr("Internal Communication"),
                        checked: batteryFaults.InternalCommunication,
                        onClicked: function(checked) { batteryFaults.setInternalCommunication(checked) }
                    },
                    {
                        text: qsTr("Internal Conversion"),
                        checked: batteryFaults.InternalConversion,
                        onClicked: function(checked) { batteryFaults.setInternalConversion(checked) }
                    },
                    {
                        text: qsTr("Weak Cell"),
                        checked: batteryFaults.WeakCell,
                        onClicked: function(checked) { batteryFaults.setWeakCell(checked) }
                    },
                    {
                        text: qsTr("Low Cell Voltage"),
                        checked: batteryFaults.LowCellVoltage,
                        onClicked: function(checked) { batteryFaults.setLowCellVoltage(checked) }
                    },
                    {
                        text: qsTr("Open Wiring"),
                        checked: batteryFaults.OpenWiring,
                        onClicked: function(checked) { batteryFaults.setOpenWiring(checked) }
                    },
                    {
                        text: qsTr("Current Sensor"),
                        checked: batteryFaults.CurrentSensor,
                        onClicked: function(checked) { batteryFaults.setCurrentSensor(checked) }
                    },
                    {
                        text: qsTr("Pack Voltage Sensor"),
                        checked: batteryFaults.PackVoltageSensor,
                        onClicked: function(checked) { batteryFaults.setPackVoltageSensor(checked) }
                    },
                    {
                        text: qsTr("Weak Pack"),
                        checked: batteryFaults.WeakPack,
                        onClicked: function(checked) { batteryFaults.setWeakPack(checked) }
                    },
                    {
                        text: qsTr("Voltage Redundancy"),
                        checked: batteryFaults.VoltageRedundancy,
                        onClicked: function(checked) { batteryFaults.setVoltageRedundancy(checked) }
                    },
                    {
                        text: qsTr("Fan Monitor"),
                        checked: batteryFaults.FanMonitor,
                        onClicked: function(checked) { batteryFaults.setFanMonitor(checked) }
                    },
                    {
                        text: qsTr("Thermistor"),
                        checked: batteryFaults.Thermistor,
                        onClicked: function(checked) { batteryFaults.setThermistor(checked) }
                    },
                    {
                        text: qsTr("CANBUS Communications"),
                        checked: batteryFaults.CanbusCommunications,
                        onClicked: function(checked) { batteryFaults.setCanbusCommunications(checked) }
                    },
                    {
                        text: qsTr("Always-On Supply"),
                        checked: batteryFaults.AlwaysOnSupply,
                        onClicked: function(checked) { batteryFaults.setAlwaysOnSupply(checked) }
                    },
                    {
                        text: qsTr("High Voltage Isolation"),
                        checked: batteryFaults.HighVoltageIsolation,
                        onClicked: function(checked) { batteryFaults.setHighVoltageIsolation(checked) }
                    },
                    {
                        text: qsTr("12V Power Supply"),
                        checked: batteryFaults.PowerSupply12V,
                        onClicked: function(checked) { batteryFaults.setPowerSupply12V(checked) }
                    },
                    {
                        text: qsTr("Charge Limit Enforcement"),
                        checked: batteryFaults.ChargeLimitEnforcement,
                        onClicked: function(checked) { batteryFaults.setChargeLimitEnforcement(checked) }
                    },
                    {
                        text: qsTr("Discharge Limit Enforcement"),
                        checked: batteryFaults.DischargeLimitEnforcement,
                        onClicked: function(checked) { batteryFaults.setDischargeLimitEnforcement(checked) }
                    },
                    {
                        text: qsTr("Charger Safety Relay"),
                        checked: batteryFaults.ChargerSafetyRelay,
                        onClicked: function(checked) { batteryFaults.setChargerSafetyRelay(checked) }
                    },
                    {
                        text: qsTr("Internal Memory"),
                        checked: batteryFaults.InternalMemory,
                        onClicked: function(checked) { batteryFaults.setInternalMemory(checked) }
                    },
                    {
                        text: qsTr("Internal Thermistor"),
                        checked: batteryFaults.InternalThermistor,
                        onClicked: function(checked) { batteryFaults.setInternalThermistor(checked) }
                    },
                    {
                        text: qsTr("Internal Logic"),
                        checked: batteryFaults.InternalLogic,
                        onClicked: function(checked) { batteryFaults.setInternalLogic(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Limit Flags"
                flags: [
                    {
                        text: qsTr("DCL Reduced Due To Low SOC"),
                        checked: batteryFaults.DclSoc,
                        onClicked: function(checked) { batteryFaults.setDclSoc(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To High Cell Resistance"),
                        checked: batteryFaults.DclCellResistance,
                        onClicked: function(checked) { batteryFaults.setDclCellResistance(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Temperature"),
                        checked: batteryFaults.DclTemperature,
                        onClicked: function(checked) { batteryFaults.setDclTemperature(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Low Cell Voltage"),
                        checked: batteryFaults.DclCellVoltage,
                        onClicked: function(checked) { batteryFaults.setDclCellVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Low Pack Voltage"),
                        checked: batteryFaults.DclPackVoltage,
                        onClicked: function(checked) { batteryFaults.setDclPackVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL and CCL Reduced Due to Voltage Failsafe"),
                        checked: batteryFaults.DclCclVoltage,
                        onClicked: function(checked) { batteryFaults.setDclCclVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL and CCL Reduced Due to Communication Failsafe"),
                        checked: batteryFaults.DclCclCommunication,
                        onClicked: function(checked) { batteryFaults.setDclCclCommunication(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High SOC"),
                        checked: batteryFaults.CclSoc,
                        onClicked: function(checked) { batteryFaults.setCclSoc(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due to High Cell Resistance"),
                        checked: batteryFaults.CclCellResistance,
                        onClicked: function(checked) { batteryFaults.setCclCellResistance(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Temperature"),
                        checked: batteryFaults.CclTemperature,
                        onClicked: function(checked) { batteryFaults.setCclTemperature(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High Cell Voltage"),
                        checked: batteryFaults.CclCellVoltage,
                        onClicked: function(checked) { batteryFaults.setCclCellVoltage(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High Pack Voltage"),
                        checked: batteryFaults.CclPackVoltage,
                        onClicked: function(checked) { batteryFaults.setCclPackVoltage(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Charger Latch"),
                        checked: batteryFaults.CclChargerLatch,
                        onClicked: function(checked) { batteryFaults.setCclChargerLatch(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Alternate Current Limit [MPI]"),
                        checked: batteryFaults.CclCurrent,
                        onClicked: function(checked) { batteryFaults.setCclCurrent(checked) }
                    }
                ]
            }
        }

        BytePreview {
            id: bytePreview
            raw: batteryFaults.byteStreamStr
            encoded: batteryFaults.encodedByteStreamStr
        }
    }
}
