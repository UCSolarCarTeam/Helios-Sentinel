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
                        checked: batteryFaults.internalCommunications,
                        onClicked: function(checked) { batteryFaults.setInternalCommunication(checked) }
                    },
                    {
                        text: qsTr("Internal Conversion"),
                        checked: batteryFaults.internalConversion,
                        onClicked: function(checked) { batteryFaults.setInternalConversion(checked) }
                    },
                    {
                        text: qsTr("Weak Cell"),
                        checked: batteryFaults.weakCell,
                        onClicked: function(checked) { batteryFaults.setWeakCell(checked) }
                    },
                    {
                        text: qsTr("Low Cell Voltage"),
                        checked: batteryFaults.lowCellVoltage,
                        onClicked: function(checked) { batteryFaults.setLowCellVoltage(checked) }
                    },
                    {
                        text: qsTr("Open Wiring"),
                        checked: batteryFaults.openWiring,
                        onClicked: function(checked) { batteryFaults.setOpenWiring(checked) }
                    },
                    {
                        text: qsTr("Current Sensor"),
                        checked: batteryFaults.currentSensor,
                        onClicked: function(checked) { batteryFaults.setCurrentSensor(checked) }
                    },
                    {
                        text: qsTr("Pack Voltage Sensor"),
                        checked: batteryFaults.packVoltageSensor,
                        onClicked: function(checked) { batteryFaults.setPackVoltageSensor(checked) }
                    },
                    {
                        text: qsTr("Weak Pack"),
                        checked: batteryFaults.weakPack,
                        onClicked: function(checked) { batteryFaults.setWeakPack(checked) }
                    },
                    {
                        text: qsTr("Voltage Redundancy"),
                        checked: batteryFaults.voltageRedundancy,
                        onClicked: function(checked) { batteryFaults.setVoltageRedundancy(checked) }
                    },
                    {
                        text: qsTr("Fan Monitor"),
                        checked: batteryFaults.fanMonitor,
                        onClicked: function(checked) { batteryFaults.setFanMonitor(checked) }
                    },
                    {
                        text: qsTr("Thermistor"),
                        checked: batteryFaults.thermistor,
                        onClicked: function(checked) { batteryFaults.setThermistor(checked) }
                    },
                    {
                        text: qsTr("CANBUS Communications"),
                        checked: batteryFaults.canbusCommunications,
                        onClicked: function(checked) { batteryFaults.setCanbusCommunications(checked) }
                    },
                    {
                        text: qsTr("Always-On Supply"),
                        checked: batteryFaults.alwaysOnSupply,
                        onClicked: function(checked) { batteryFaults.setAlwaysOnSupply(checked) }
                    },
                    {
                        text: qsTr("High Voltage Isolation"),
                        checked: batteryFaults.highVoltageIsolation,
                        onClicked: function(checked) { batteryFaults.setHighVoltageIsolation(checked) }
                    },
                    {
                        text: qsTr("12V Power Supply"),
                        checked: batteryFaults.powerSupply12V,
                        onClicked: function(checked) { batteryFaults.setPowerSupply12V(checked) }
                    },
                    {
                        text: qsTr("Charge Limit Enforcement"),
                        checked: batteryFaults.chargeLimitEnforcement,
                        onClicked: function(checked) { batteryFaults.setChargeLimitEnforcement(checked) }
                    },
                    {
                        text: qsTr("Discharge Limit Enforcement"),
                        checked: batteryFaults.dischargeLimitEnforcement,
                        onClicked: function(checked) { batteryFaults.setDischargeLimitEnforcement(checked) }
                    },
                    {
                        text: qsTr("Charger Safety Relay"),
                        checked: batteryFaults.chargerSafetyRelay,
                        onClicked: function(checked) { batteryFaults.setChargerSafetyRelay(checked) }
                    },
                    {
                        text: qsTr("Internal Memory"),
                        checked: batteryFaults.internalMemory,
                        onClicked: function(checked) { batteryFaults.setInternalMemory(checked) }
                    },
                    {
                        text: qsTr("Internal Thermistor"),
                        checked: batteryFaults.internalThermistor,
                        onClicked: function(checked) { batteryFaults.setInternalThermistor(checked) }
                    },
                    {
                        text: qsTr("Internal Logic"),
                        checked: batteryFaults.internalLogic,
                        onClicked: function(checked) { batteryFaults.setInternalLogic(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Limit Flags"
                flags: [
                    {
                        text: qsTr("DCL Reduced Due To Low SOC"),
                        checked: batteryFaults.dclSoc,
                        onClicked: function(checked) { batteryFaults.setDclSoc(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To High Cell Resistance"),
                        checked: batteryFaults.dclCellResistance,
                        onClicked: function(checked) { batteryFaults.setDclCellResistance(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Temperature"),
                        checked: batteryFaults.dclTemperature,
                        onClicked: function(checked) { batteryFaults.setDclTemperature(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Low Cell Voltage"),
                        checked: batteryFaults.dclCellVoltage,
                        onClicked: function(checked) { batteryFaults.setDclCellVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL Reduced Due To Low Pack Voltage"),
                        checked: batteryFaults.dclPackVoltage,
                        onClicked: function(checked) { batteryFaults.setDclPackVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL and CCL Reduced Due to Voltage Failsafe"),
                        checked: batteryFaults.dclCclVoltage,
                        onClicked: function(checked) { batteryFaults.setDclCclVoltage(checked) }
                    },
                    {
                        text: qsTr("DCL and CCL Reduced Due to Communication Failsafe"),
                        checked: batteryFaults.dclCclCommunication,
                        onClicked: function(checked) { batteryFaults.setDclCclCommunication(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High SOC"),
                        checked: batteryFaults.cclSoc,
                        onClicked: function(checked) { batteryFaults.setCclSoc(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due to High Cell Resistance"),
                        checked: batteryFaults.cclCellResistance,
                        onClicked: function(checked) { batteryFaults.setCclCellResistance(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Temperature"),
                        checked: batteryFaults.cclTemperature,
                        onClicked: function(checked) { batteryFaults.setCclTemperature(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High Cell Voltage"),
                        checked: batteryFaults.cclCellVoltage,
                        onClicked: function(checked) { batteryFaults.setCclCellVoltage(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To High Pack Voltage"),
                        checked: batteryFaults.cclPackVoltage,
                        onClicked: function(checked) { batteryFaults.setCclPackVoltage(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Charger Latch"),
                        checked: batteryFaults.cclChargerLatch,
                        onClicked: function(checked) { batteryFaults.setCclChargerLatch(checked) }
                    },
                    {
                        text: qsTr("CCL Reduced Due To Alternate Current Limit [MPI]"),
                        checked: batteryFaults.cclCurrent,
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
