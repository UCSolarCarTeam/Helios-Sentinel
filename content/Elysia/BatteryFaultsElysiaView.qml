import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."
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
                        checked: batteryFaultsElysia.InternalCommunication,
                        onClicked: function(checked) { batteryFaultsElysia.setInternalCommunication(checked) }
                    },
                    {
                        text: qsTr("Internal Conversion"),
                        checked: batteryFaultsElysia.InternalConversion,
                        onClicked: function(checked) { batteryFaultsElysia.setInternalConversion(checked) }
                    },
                    {
                        text: qsTr("Weak Cell"),
                        checked: batteryFaultsElysia.WeakCell,
                        onClicked: function(checked) { batteryFaultsElysia.setWeakCell(checked) }
                    },
                    {
                        text: qsTr("Low Cell Voltage"),
                        checked: batteryFaultsElysia.LowCellVoltage,
                        onClicked: function(checked) { batteryFaultsElysia.setLowCellVoltage(checked) }
                    },
                    {
                        text: qsTr("Open Wiring"),
                        checked: batteryFaultsElysia.OpenWiring,
                        onClicked: function(checked) { batteryFaultsElysia.setOpenWiring(checked) }
                    },
                    {
                        text: qsTr("Current Sensor"),
                        checked: batteryFaultsElysia.CurrentSensor,
                        onClicked: function(checked) { batteryFaultsElysia.setCurrentSensor(checked) }
                    },
                    {
                        text: qsTr("Pack Voltage Sensor"),
                        checked: batteryFaultsElysia.PackVoltageSensor,
                        onClicked: function(checked) { batteryFaultsElysia.setPackVoltageSensor(checked) }
                    },
                    {
                        text: qsTr("Weak Pack"),
                        checked: batteryFaultsElysia.WeakPack,
                        onClicked: function(checked) { batteryFaultsElysia.setWeakPack(checked) }
                    },
                    {
                        text: qsTr("Voltage Redundancy"),
                        checked: batteryFaultsElysia.VoltageRedundancy,
                        onClicked: function(checked) { batteryFaultsElysia.setVoltageRedundancy(checked) }
                    },
                    {
                        text: qsTr("Fan Monitor"),
                        checked: batteryFaultsElysia.FanMonitor,
                        onClicked: function(checked) { batteryFaultsElysia.setFanMonitor(checked) }
                    },
                    {
                        text: qsTr("Thermistor"),
                        checked: batteryFaultsElysia.Thermistor,
                        onClicked: function(checked) { batteryFaultsElysia.setThermistor(checked) }
                    },
                    {
                        text: qsTr("CANBUS Communications"),
                        checked: batteryFaultsElysia.CanbusCommunications,
                        onClicked: function(checked) { batteryFaultsElysia.setCanbusCommunications(checked) }
                    },
                    {
                        text: qsTr("Always-On Supply"),
                        checked: batteryFaultsElysia.AlwaysOnSupply,
                        onClicked: function(checked) { batteryFaultsElysia.setAlwaysOnSupply(checked) }
                    },
                    {
                        text: qsTr("High Voltage Isolation"),
                        checked: batteryFaultsElysia.HighVoltageIsolation,
                        onClicked: function(checked) { batteryFaultsElysia.setHighVoltageIsolation(checked) }
                    },
                    {
                        text: qsTr("12V Power Supply"),
                        checked: batteryFaultsElysia.PowerSupply12V,
                        onClicked: function(checked) { batteryFaultsElysia.setPowerSupply12V(checked) }
                    },
                    {
                        text: qsTr("Charge Limit Enforcement"),
                        checked: batteryFaultsElysia.ChargeLimitEnforcement,
                        onClicked: function(checked) { batteryFaultsElysia.setChargeLimitEnforcement(checked) }
                    },
                    {
                        text: qsTr("Discharge Limit Enforcement"),
                        checked: batteryFaultsElysia.DischargeLimitEnforcement,
                        onClicked: function(checked) { batteryFaultsElysia.setDischargeLimitEnforcement(checked) }
                    },
                    {
                        text: qsTr("Charger Safety Relay"),
                        checked: batteryFaultsElysia.ChargerSafetyRelay,
                        onClicked: function(checked) { batteryFaultsElysia.setChargerSafetyRelay(checked) }
                    },
                    {
                        text: qsTr("Internal Memory"),
                        checked: batteryFaultsElysia.InternalMemory,
                        onClicked: function(checked) { batteryFaultsElysia.setInternalMemory(checked) }
                    },
                    {
                        text: qsTr("Internal Thermistor"),
                        checked: batteryFaultsElysia.InternalThermistor,
                        onClicked: function(checked) { batteryFaultsElysia.setInternalThermistor(checked) }
                    },
                    {
                        text: qsTr("Internal Logic"),
                        checked: batteryFaultsElysia.InternalLogic,
                        onClicked: function(checked) { batteryFaultsElysia.setInternalLogic(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Limit Flags"
                flags: [
                    {
                        text: qsTr("DCL Reduced Due To Low SOC"),
                        checked: batteryFaultsElysia.DclSoc,
                        onClicked: function(checked) { batteryFaultsElysia.setDclSoc(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To High Cell Resistance"),
                        checked: batteryFaultsElysia.DclCellResistance,
                        onClicked: function(checked) { batteryFaultsElysia.setDclCellResistance(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Temperature"),
                        checked: batteryFaultsElysia.DclTemperature,
                        onClicked: function(checked) { batteryFaultsElysia.setDclTemperature(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Low Cell Voltage"),
                        checked: batteryFaultsElysia.DclCellVoltage,
                        onClicked: function(checked) { batteryFaultsElysia.setDclCellVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Low Pack Voltage"),
                        checked: batteryFaultsElysia.DclPackVoltage,
                        onClicked: function(checked) { batteryFaultsElysia.setDclPackVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL and CCL Reduced Due to Voltage Failsafe"),
                        checked: batteryFaultsElysia.DclCclVoltage,
                        onClicked: function(checked) { batteryFaultsElysia.setDclCclVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL and CCL Reduced Due to Communication Failsafe"),
                        checked: batteryFaultsElysia.DclCclCommunication,
                        onClicked: function(checked) { batteryFaultsElysia.setDclCclCommunication(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High SOC"),
                        checked: batteryFaultsElysia.CclSoc,
                        onClicked: function(checked) { batteryFaultsElysia.setCclSoc(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due to High Cell Resistance"),
                        checked: batteryFaultsElysia.CclCellResistance,
                        onClicked: function(checked) { batteryFaultsElysia.setCclCellResistance(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Temperature"),
                        checked: batteryFaultsElysia.CclTemperature,
                        onClicked: function(checked) { batteryFaultsElysia.setCclTemperature(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High Cell Voltage"),
                        checked: batteryFaultsElysia.CclCellVoltage,
                        onClicked: function(checked) { batteryFaultsElysia.setCclCellVoltage(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High Pack Voltage"),
                        checked: batteryFaultsElysia.CclPackVoltage,
                        onClicked: function(checked) { batteryFaultsElysia.setCclPackVoltage(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Charger Latch"),
                        checked: batteryFaultsElysia.CclChargerLatch,
                        onClicked: function(checked) { batteryFaultsElysia.setCclChargerLatch(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Alternate Current Limit [MPI]"),
                        checked: batteryFaultsElysia.CclCurrent,
                        onClicked: function(checked) { batteryFaultsElysia.setCclCurrent(checked) }
                    }
                ]
            }
        }

        BytePreview {
            id: bytePreview
            raw: batteryFaultsElysia.byteStreamStr
            encoded: batteryFaultsElysia.encodedByteStreamStr
        }
    }
}
