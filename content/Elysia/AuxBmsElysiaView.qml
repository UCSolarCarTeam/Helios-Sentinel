import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."

Item {
    width: 550
    height: 650

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "BMS Packet"
            font.family: "Verdana"
            font.bold: true
        }
        IntSpinBox {
            id: spinBox
            text: qsTr("BMS PrechargeState")
            value: auxBmsElysia.PrechargeState
            onValueChanged: auxBmsElysia.setPrechargeState(value)
        }
        Column{
            spacing:20

            FlagBox {
                title: ""
                flags: [

                    {
                        text: qsTr("Aux BMS Alive"),
                        checked: auxBmsElysia.BmsAlive,
                        onClicked: function(checked) { auxBmsElysia.setBmsAlive(checked) }
                    },
                    {
                        text: qsTr("Strobe BMS Light"),
                        checked: auxBmsElysia.StrobeLight,
                        onClicked:function(checked) { auxBmsElysia.setStrobeLight(checked)}
                    },
                    {
                        text: qsTr("Allow Charge"),
                       checked: auxBmsElysia.AllowCharge,
                       onClicked: function(checked){auxBmsElysia.setAllowCharge(checked)}
                    },
                    {
                        text: qsTr("High Voltage Enable"),
                        checked: auxBmsElysia.HighVoltageEnable,
                        onClicked:function(checked){ auxBmsElysia.setHighVoltageEnable(checked)}
                    },
                    {
                        text: qsTr("Allow Discharge"),
                        checked: auxBmsElysia.AllowDischarge,
                        onClicked: function(checked){ auxBmsElysia.setAllowDischarge(checked)}
                    }
                ]
            }
            FlagBox {
                title:"AUX Contactor Debug Info"
                flags:
                    [
                    {
                        text: qsTr("Charge Contactor"),
                        checked: auxBmsElysia.ChargeContactor,
                        onClicked: function(checked){auxBmsElysia.setChargeContactor(checked)},
                    },
                    {
                        text: qsTr("Discharge Contactor"),
                        checked: auxBmsElysia.DischargeContactor,
                        onClicked: function(checked) {auxBmsElysia.setDischargeContactor(checked)},
                    },
                    {
                        text: qsTr("Common Contactor"),
                        checked: auxBmsElysia.CommonContactor,
                        onClicked: function(checked) {auxBmsElysia.setCommonContactor(checked)},
                    },
                    {
                        text: qsTr("Discharge Should"),
                        checked: auxBmsElysia.DischargeShould,
                        onClicked: function(checked) {auxBmsElysia.setDischargeShould(checked)},
                    },
                    {
                        text: qsTr("Charge Should"),
                        checked: auxBmsElysia.ChargeShould,
                        onClicked: function(checked) {auxBmsElysia.setChargeShould(checked)},
                    },
                    {
                        text: qsTr("Charge Open But Should Be Closed"),
                        checked: auxBmsElysia.ChargeOpen,
                        onClicked: function(checked) {auxBmsElysia.setChargeOpen(checked)},
                    },
                    {
                        text: qsTr("Discharge Open But Should Be Closed"),
                        checked: auxBmsElysia.DischargeOpen,
                        onClicked:function(checked) { auxBmsElysia.setDischargeOpen(checked)},
                    },
                ]
            }
            FlagBox {
                title: "Aux Trip"
                flags:[
                    {
                       text: qsTr("CT High Cell Voltage"),
                       checked: auxBmsElysia.CtHighCellVoltage,
                       onClicked:function(checked){ auxBmsElysia.setCtHighCellVoltage(checked)}
                    },
                    {
                       text: qsTr("CT High Temp/Current"),
                       checked: auxBmsElysia.CtHighTempCurrent,
                       onClicked: function(checked){auxBmsElysia.setCtHighTempCurrent(checked)},
                    },
                    {
                       text: qsTr("CT Pack Current"),
                       checked: auxBmsElysia.CtPackCurrent,
                       onClicked:function(checked){auxBmsElysia.setCtPackCurrent(checked)},
                    },
                    {
                       text: qsTr("DT Low Cell Voltage"),
                       checked: auxBmsElysia.DtLowCellVoltage,
                       onClicked: function(checked) {auxBmsElysia.setDtLowCellVoltage(checked)},
                    },
                    {
                       text: qsTr("DT High Temp/Current"),
                       checked: auxBmsElysia.DtHighTempCurrent,
                       onClicked: function(checked) {auxBmsElysia.setDtHighTempCurrent(checked)}
                    },
                    {
                       text: qsTr("DT Pack Current"),
                       checked: auxBmsElysia.DtPackCurrent,
                       onClicked: function(checked) {auxBmsElysia.setDtPackCurrent(checked)}
                    },
                    {
                       text: qsTr("Protection"),
                       checked: auxBmsElysia.Protection,
                       onClicked: function(checked) {auxBmsElysia.setProtection(checked)},
                    },
                    {
                       text: qsTr("Orion Timeout"),
                       checked: auxBmsElysia.OrionTimeout,
                       onClicked: function(checked) {auxBmsElysia.setOrionTimeout(checked)},
                    },
                    {
                       text: qsTr("CNC High Current"),
                       checked: auxBmsElysia.CncHighCurrent,
                       onClicked: function(checked) {auxBmsElysia.setCncHighCurrent(checked)},
                    },
                    {
                       text: qsTr("DNC High Current"),
                       checked: auxBmsElysia.DncHighCurrent,
                       onClicked: function(checked) {auxBmsElysia.setDncHighCurrent(checked)},
                    },
                    {
                       text: qsTr("Contactor Disconnected"),
                       checked: auxBmsElysia.ContactorDisconnected,
                       onClicked: function(checked){auxBmsElysia.setContactorDisconnected(checked)}
                    }
                ]
            }

        }
        BytePreview{
            id:bytePreview
            raw:auxBmsElysia.byteStreamStr
            encoded:auxBmsElysia.encodedByteStreamStr
        }
    }

}
