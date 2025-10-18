import QtQuick 2.15
import QtQuick.Controls 6.2

import "../Components"

Item {
    width: 550
    height: 975

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "MBMS Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Column {
            spacing: 20

            FlagBox{
                title: "Contactor Command"
                flags: [
                    {
                        text: "Common",
                        checked: mbms.CommonContactorCommand,
                        onClicked: function(checked) { mbms.setCommonContactorCommand(checked) }
                    },
                    {
                        text: "Motor",
                        checked: mbms.MotorContactorCommand,
                        onClicked: function(checked) { mbms.setMotorContactorCommand(checked) }
                    },
                    {
                        text: "Array",
                        checked: mbms.ArrayContactorCommand,
                        onClicked: function(checked) { mbms.setArrayContactorCommand(checked) }
                    },
                    {
                        text: "LV",
                        checked: mbms.LvContactorCommand,
                        onClicked: function(checked) { mbms.setLvContactorCommand(checked) }
                    },
                    {
                        text: "Charge",
                        checked: mbms.ChargeContactorCommand,
                        onClicked: function(checked) { mbms.setChargeContactorCommand(checked) }
                    }
                ]
            }

            FlagBox{
                title: "Status"
                flags: [
                    {
                        text: "Strobe BMS Light",
                        checked: mbms.StrobeBmsLight,
                        onClicked: function(checked) { mbms.setStrobeBmsLight(checked) }
                    },
                    {
                        text: "Charge Enable",
                        checked: mbms.ChargeEnable,
                        onClicked: function(checked) { mbms.setChargeEnable(checked) }
                    },
                    {
                        text: "NCharge Safety",
                        checked: mbms.NChargeSafety,
                        onClicked: function(checked) { mbms.setNChargeSafety(checked) }
                    },
                    {
                        text: "Discharge Enable",
                        checked: mbms.DischargeEnable,
                        onClicked: function(checked) { mbms.setDischargeEnable(checked) }
                    },
                    {
                        text: "Orion CAN Received Recently",
                        checked: mbms.OrionCanReceivedRecently,
                        onClicked: function(checked) { mbms.setOrionCanReceivedRecently(checked) }
                    },
                    {
                        text: "Discharge Should Trip",
                        checked: mbms.DischargeShouldTrip,
                        onClicked: function(checked) { mbms.setDischargeShouldTrip(checked) }
                    },
                    {
                        text: "Charge Should Trip",
                        checked: mbms.ChargeShouldTrip,
                        onClicked: function(checked) { mbms.setChargeShouldTrip(checked) }
                    }
                ]
            }

            IntSpinBox {
                text: "Aux Battery Voltage"
                value: mbms.AuxillaryBatteryVoltage
                onValueChanged: mbms.setAuxillaryBatteryVoltage(value)
                min: 0
                max: 31
            }

            IntSpinBox {
                text: "Startup State"
                value: mbms.StartupState
                onValueChanged: mbms.setStartupState(value)
                min: 0
                max: 15
            }

            IntSpinBox {
                text: "System State"
                value: mbms.SystemState
                onValueChanged: mbms.setSystemState(value)
                min: 0
                max: 7
            }

            FlagBox{
                title: "Power Selection Status"
                flags: [
                    {
                        text: "NMain Power Switch",
                        checked: mbms.NMainPowerSwitch,
                        onClicked: function(checked) { mbms.setNMainPowerSwitch(checked) }
                    },
                    {
                        text: "External Shutdown",
                        checked: mbms.ExternalShutdown,
                        onClicked: function(checked) { mbms.setExternalShutdown(checked) }
                    },
                    {
                        text: "En1",
                        checked: mbms.En1,
                        onClicked: function(checked) { mbms.setEn1(checked) }
                    },
                    {
                        text: "NDcdc Fault",
                        checked: mbms.NDcdcFault,
                        onClicked: function(checked) { mbms.setNDcdcFault(checked) }
                    },
                    {
                        text: "N3 Aoc",
                        checked: mbms.N3Aoc,
                        onClicked: function(checked) { mbms.setN3Aoc(checked) }
                    },
                    {
                        text: "NDcdc On",
                        checked: mbms.NDcdcOn,
                        onClicked: function(checked) { mbms.setNDcdcOn(checked) }
                    },
                    {
                        text: "NChg Fault",
                        checked: mbms.NChgFault,
                        onClicked: function(checked) { mbms.setNChgFault(checked) }
                    },
                    {
                        text: "NChg On",
                        checked: mbms.NChgOn,
                        onClicked: function(checked) { mbms.setNChgOn(checked) }
                    },
                    {
                        text: "NChg Lv En",
                        checked: mbms.NChgLvEn,
                        onClicked: function(checked) { mbms.setNChgLvEn(checked) }
                    },
                    {
                        text: "Abatt Disable",
                        checked: mbms.AbattDisable,
                        onClicked: function(checked) { mbms.setAbattDisable(checked) }
                    },
                    {
                        text: "Key",
                        checked: mbms.Key,
                        onClicked: function(checked) { mbms.setKey(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Trip"
                flags: [
                    {
                        text: "High Cell Voltage Trip",
                        checked: mbms.HighCellVoltageTrip,
                        onClicked: function(checked) { mbms.setHighCellVoltageTrip(checked) }
                    },
                    {
                        text: "Low Cell Voltage Trip",
                        checked: mbms.LowCellVoltageTrip,
                        onClicked: function(checked) { mbms.setLowCellVoltageTrip(checked) }
                    },
                    {
                        text: "Common High Current Trip",
                        checked: mbms.CommonHighCurrentTrip,
                        onClicked: function(checked) { mbms.setCommonHighCurrentTrip(checked) }
                    },
                    {
                        text: "Motor High Current Trip",
                        checked: mbms.MotorHighCurrentTrip,
                        onClicked: function(checked) { mbms.setMotorHighCurrentTrip(checked) }
                    },
                    {
                        text: "Array High Current Trip",
                        checked: mbms.ArrayHighCurrentTrip,
                        onClicked: function(checked) { mbms.setArrayHighCurrentTrip(checked) }
                    },
                    {
                        text: "Lv High Current Trip",
                        checked: mbms.LvHighCurrentTrip,
                        onClicked: function(checked) { mbms.setLvHighCurrentTrip(checked) }
                    },
                    {
                        text: "Charge High Current Trip",
                        checked: mbms.ChargeHighCurrentTrip,
                        onClicked: function(checked) { mbms.setChargeHighCurrentTrip(checked) }
                    },
                    {
                        text: "Protection Trip",
                        checked: mbms.ProtectionTrip,
                        onClicked: function(checked) { mbms.setProtectionTrip(checked) }
                    },
                    {
                        text: "Orion Message Timeout Trip",
                        checked: mbms.OrionMessageTimeoutTrip,
                        onClicked: function(checked) { mbms.setOrionMessageTimeoutTrip(checked) }
                    },
                    {
                        text: "Contactor Disconnected Unexpectedly Trip",
                        checked: mbms.ContactorDisconnectedUnexpectedlyTrip,
                        onClicked: function(checked) { mbms.setContactorDisconnectedUnexpectedlyTrip(checked) }
                    },
                    {
                        text: "Contactor Connected Unexpectely Trip",
                        checked: mbms.ContactorConnectedUnexpectelyTrip,
                        onClicked: function(checked) { mbms.setContactorConnectedUnexpectelyTrip(checked) }
                    },
                    {
                        text: "Common Heartbeat Dead Trip",
                        checked: mbms.CommonHeartbeatDeadTrip,
                        onClicked: function(checked) { mbms.setCommonHeartbeatDeadTrip(checked) }
                    },
                    {
                        text: "Motor Heartbeat Dead Trip",
                        checked: mbms.MotorHeartbeatDeadTrip,
                        onClicked: function(checked) { mbms.setMotorHeartbeatDeadTrip(checked) }
                    },
                    {
                        text: "Array Heartbeat Dead Trip",
                        checked: mbms.ArrayHeartbeatDeadTrip,
                        onClicked: function(checked) { mbms.setArrayHeartbeatDeadTrip(checked) }
                    },
                    {
                        text: "Lv Heartbeat Dead Trip",
                        checked: mbms.LvHeartbeatDeadTrip,
                        onClicked: function(checked) { mbms.setLvHeartbeatDeadTrip(checked) }
                    },
                    {
                        text: "Charge Heartbeat Dead Trip",
                        checked: mbms.ChargeHeartbeatDeadTrip,
                        onClicked: function(checked) { mbms.setChargeHeartbeatDeadTrip(checked) }
                    },
                    {
                        text: "Mps Disabled Trip",
                        checked: mbms.MpsDisabledTrip,
                        onClicked: function(checked) { mbms.setMpsDisabledTrip(checked) }
                    },
                    {
                        text: "Esd Enabled Trip",
                        checked: mbms.EsdEnabledTrip,
                        onClicked: function(checked) { mbms.setEsdEnabledTrip(checked) }
                    },
                    {
                        text: "High Temperature Trip",
                        checked: mbms.HighTemperatureTrip,
                        onClicked: function(checked) { mbms.setHighTemperatureTrip(checked) }
                    },
                    {
                        text: "Low Temperature Trip",
                        checked: mbms.LowTemperatureTrip,
                        onClicked: function(checked) { mbms.setLowTemperatureTrip(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Soft Battery Limit Warning"
                flags: [
                    {
                        text: "High Cell Voltage Warning",
                        checked: mbms.HighCellVoltageWarning,
                        onClicked: function(checked) { mbms.setHighCellVoltageWarning(checked) }
                    },
                    {
                        text: "Low Cell Voltage Warning",
                        checked: mbms.LowCellVoltageWarning,
                        onClicked: function(checked) { mbms.setLowCellVoltageWarning(checked) }
                    },
                    {
                        text: "Common High Current Warning",
                        checked: mbms.CommonHighCurrentWarning,
                        onClicked: function(checked) { mbms.setCommonHighCurrentWarning(checked) }
                    },
                    {
                        text: "Motor High Current Warning",
                        checked: mbms.MotorHighCurrentWarning,
                        onClicked: function(checked) { mbms.setMotorHighCurrentWarning(checked) }
                    },
                    {
                        text: "Array High Current Warning",
                        checked: mbms.ArrayHighCurrentWarning,
                        onClicked: function(checked) { mbms.setArrayHighCurrentWarning(checked) }
                    },
                    {
                        text: "Lv High Current Warning",
                        checked: mbms.LvHighCurrentWarning,
                        onClicked: function(checked) { mbms.setLvHighCurrentWarning(checked) }
                    },
                    {
                        text: "Charge High Current Warning",
                        checked: mbms.ChargeHighCurrentWarning,
                        onClicked: function(checked) { mbms.setChargeHighCurrentWarning(checked) }
                    },
                    {
                        text: "High Temperature Warning",
                        checked: mbms.HighTemperatureWarning,
                        onClicked: function(checked) { mbms.setHighTemperatureWarning(checked) }
                    },
                    {
                        text: "Low Temperature Warning",
                        checked: mbms.LowTemperatureWarning,
                        onClicked: function(checked) { mbms.setLowTemperatureWarning(checked) }
                    },
                    {
                        text: "Can Oc 12 V Warning",
                        checked: mbms.CanOc12VWarning,
                        onClicked: function(checked) { mbms.setCanOc12VWarning(checked) }
                    }
                ]
            }
        }
    }
}
