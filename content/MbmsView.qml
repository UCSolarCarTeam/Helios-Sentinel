import QtQuick 2.15
import QtQuick.Controls 6.2
import QtQuick.Studio.Components 1.0


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
                title: "Contactor Status"
                flags: [
                    {
                        text: qsTr("Common"),
                        checked: mbms.commonContactorState,
                        onClicked: function(checked) { mbms.setCommonContactorState(checked) }
                    },
                    {
                        text: qsTr("Motor"),
                        checked: mbms.motorContactorState,
                        onClicked: function(checked) { mbms.setMotorContactorState(checked) }
                    },
                    {
                        text: qsTr("Array"),
                        checked: mbms.arrayContactorState,
                        onClicked: function(checked) { mbms.setArrayContactorState(checked) }
                    },
                    {
                        text: qsTr("LV"),
                        checked: mbms.lvContactorState,
                        onClicked: function(checked) { mbms.setLvContactorState(checked) }
                    },
                    {
                        text: qsTr("Charge"),
                        checked: mbms.chargeContactorState,
                        onClicked: function(checked) { mbms.setChargeContactorState(checked) }
                    }
                ]
            }

            FlagBox{
                title: "Contactor Error"
                flags: [
                    {
                        text: qsTr("Common"),
                        checked: mbms.commonContactorError,
                        onClicked: function(checked) { mbms.setCommonContactorError(checked) }
                    },
                    {
                        text: qsTr("Motor"),
                        checked: mbms.motorContactorError,
                        onClicked: function(checked) { mbms.setMotorContactorError(checked) }
                    },
                    {
                        text: qsTr("Array"),
                        checked: mbms.arrayContactorError,
                        onClicked: function(checked) { mbms.setArrayContactorError(checked) }
                    },
                    {
                        text: qsTr("LV"),
                        checked: mbms.lvContactorError,
                        onClicked: function(checked) { mbms.setLvContactorError(checked) }
                    },
                    {
                        text: qsTr("Charge"),
                        checked: mbms.chargeContactorError,
                        onClicked: function(checked) { mbms.setChargeContactorError(checked) }
                    }
                ]
            }

            FlagBox{
                title: "Misc Status"
                flags: [
                    {
                        text: qsTr("Strobe BMS Light"),
                        checked: mbms.strobeBmsLight,
                        onClicked: function(checked) { mbms.setStrobeBmsLight(checked) }
                    },
                    {
                        text: qsTr("Allow Charge"),
                        checked: mbms.allowCharge,
                        onClicked: function(checked) { mbms.setAllowCharge(checked) }
                    },
                    {
                        text: qsTr("High Voltage Enable"),
                        checked: mbms.highVoltageEnableState,
                        onClicked: function(checked) { mbms.setHighVoltageEnableState(checked) }
                    },
                    {
                        text: qsTr("Allow Discharge"),
                        checked: mbms.allowDischarge,
                        onClicked: function(checked) { mbms.setAllowDischarge(checked) }
                    },
                    {
                        text: qsTr("OrionCAN Received Recently"),
                        checked: mbms.orionCanReceivedRecently,
                        onClicked: function(checked) { mbms.setOrionCanReceivedRecently(checked) }
                    },
                    {
                        text: qsTr("Discharge Should Trip"),
                        checked: mbms.dischargeShouldTrip,
                        onClicked: function(checked) { mbms.setDischargeShouldTrip(checked) }
                    },
                    {
                        text: qsTr("Charge Should Trip"),
                        checked: mbms.chargeShouldTrip,
                        onClicked: function(checked) { mbms.setChargeShouldTrip(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Aux Battery Voltage")
                        value: mbms.auxillaryBatteryVoltage
                        onValueChanged: mbms.setAuxillaryBatteryVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Motor Voltage")
                        value: mbms.motorVoltage
                        onValueChanged: mbms.setMotorVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Array Voltage")
                        value: mbms.arrayVoltage
                        onValueChanged: mbms.setArrayVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("LV Voltage")
                        value: mbms.lvVoltage
                        onValueChanged: mbms.setLvVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Charge Voltage")
                        value: mbms.chargeVoltage
                        onValueChanged: mbms.setChargeVoltage(value)
                    }
                }

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Common Current")
                        value: mbms.commonCurrent
                        onValueChanged: mbms.setCommonCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("Motor Current")
                        value: mbms.motorCurrent
                        onValueChanged: mbms.setMotorCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("Array Current")
                        value: mbms.arrayCurrent
                        onValueChanged: mbms.setArrayCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("LV Current")
                        value: mbms.lvCurrent
                        onValueChanged: mbms.setLvCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("Charge Current")
                        value: mbms.chargeCurrent
                        onValueChanged: mbms.setChargeCurrent(value)
                    }
                }
            }

            FlagBox {
                title: "Trip Status"
                flags: [
                    {
                        text: qsTr("High Cell Voltage"),
                        checked: mbms.highCellVoltageTrip,
                        onClicked: function(checked) { mbms.setHighCellVoltageTrip(checked) }
                    },
                    {
                        text: qsTr("Low Cell Voltage"),
                        checked: mbms.lowCellVoltageTrip,
                        onClicked: function(checked) { mbms.setLowCellVoltageTrip(checked) }
                    },
                    {
                        text: qsTr("High Common Current"),
                        checked: mbms.highCommonCurrentTrip,
                        onClicked: function(checked) { mbms.setHighCommonCurrentTrip(checked) }
                    },
                    {
                        text: qsTr("Motor High TC"),
                        checked: mbms.motorTCTrip,
                        onClicked: function(checked) { mbms.setMotorTCTrip(checked) }
                    },
                    {
                        text: qsTr("Array High TC"),
                        checked: mbms.arrayTCTrip,
                        onClicked: function(checked) { mbms.setArrayTCTrip(checked) }
                    },
                    {
                        text: qsTr("LV High TC"),
                        checked: mbms.lvTCTrip,
                        onClicked: function(checked) { mbms.setLvTCTrip(checked) }
                    },
                    {
                        text: qsTr("Charge High/Temp"),
                        checked: mbms.chargeTCTrip,
                        onClicked: function(checked) { mbms.setChargeTCTrip(checked) }
                    },
                    {
                        text: qsTr("Protection"),
                        checked: mbms.protectionTrip,
                        onClicked: function(checked) { mbms.setProtectionTrip(checked) }
                    },
                    {
                        text: qsTr("Orion Message Timeout"),
                        checked: mbms.orionMessageTimeoutTrip,
                        onClicked: function(checked) { mbms.setOrionMessageTimeoutTrip(checked) }
                    },
                    {
                        text: qsTr("Contactor Disconnect"),
                        checked: mbms.contactorDisconnectedTrip,
                        onClicked: function(checked) { mbms.setContactorDisconnectedTrip(checked) }
                    }
                ]
            }
        }

        BytePreview {
            id: bytePreview
            raw: mbms.byteStreamStr
            encoded: mbms.encodedByteStreamStr
        }
    }
}
