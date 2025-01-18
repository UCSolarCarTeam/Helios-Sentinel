import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."

Item {
    width: 750
    height: 650

    IntSpinBox {
        id: spinBox
        text: qsTr("BMS PrechargeState")
        value: bms.PrechargeState
        onValueChanged: bms.setPrechargeState(value)
    }
    FlagBox {
        title: ""
        flags:[
            {
                text: qsTr("Aux BMS Alive"),
                checked: bms.BmsAlive,
                onClicked: function(checked) { bms.setBmsAlive(checked) }
            },
            {
               text: qsTr("Strobe BMS Light"),
               checked: bms.StrobeLight,
               onClicked:function(checked) { bms.setStrobeLight(checked)},
            },
            {   text: qsTr("Allow Charge"),
               checked: bms.AllowCharge,
               onClicked: function(checked){bms.setAllowCharge(checked)},
            },
            {
               text: qsTr("High Voltage Enable"),
               checked: bms.HighVoltageEnable,
               onClicked:function(checked){ bms.setHighVoltageEnable(checked)},
            },
            {
               text: qsTr("Allow Discharge"),
               checked: bms.AllowDischarge,
               onClicked: function(checked){ bms.setAllowDischarge(checked)},
            },
        ]
    }
    FlagBox {
        title:"AUX Contactor Debug Info"
        flags:
            [
            {
                text: qsTr("Charge Contactor"),
                checked: bms.ChargeContactor,
                onClicked: function(checked){bms.setChargeContactor(checked)},
            },
            {
                text: qsTr("Discharge Contactor"),
                checked: bms.DischargeContactor,
                onClicked: function(checked) {bms.setDischargeContactor(checked)},
            },
            {
                text: qsTr("Common Contactor"),
                checked: bms.CommonContactor,
                onClicked: function(checked) {bms.setCommonContactor(checked)},
            },
            {
                text: qsTr("Discharge Should"),
                checked: bms.DischargeShould,
                onClicked: function(checked) {bms.setDischargeShould(checked)},
            },
            {
                text: qsTr("Charge Should"),
                checked: bms.ChargeShould,
                onClicked: function(checked) {bms.setChargeShould(checked)},
            },
            {
                text: qsTr("Charge Open But Should Be Closed"),
                checked: bms.ChargeOpen,
                onClicked: function(checked) {bms.setChargeOpen(checked)},
            },
            {
                text: qsTr("Discharge Open But Should Be Closed"),
                checked: bms.DischargeOpen,
                onClicked:function(checked) { bms.setDischargeOpen(checked)},
            },
        ]
    }
    FlagBox {
        title: "Aux Trip"
        flags:[
            {
               text: qsTr("CT High Cell Voltage"),
               checked: bms.CtHighCellVoltage,
               onClicked:function(checked){ bms.setCtHighCellVoltage(checked)}
            },
            {
               text: qsTr("CT High Temp/Current"),
               checked: bms.CtHighTempCurrent,
               onClicked: function(checked){bms.setCtHighTempCurrent(checked)},
            },
            {
               text: qsTr("CT Pack Current"),
               checked: bms.CtPackCurrent,
               onClicked:function(checked){bms.setCtPackCurrent(checked)},
            },
            {
               text: qsTr("DT Low Cell Voltage"),
               checked: bms.DtLowCellVoltage,
               onClicked: function(checked) {bms.setDtLowCellVoltage(checked)},
            },
            {
               text: qsTr("DT High Temp/Current"),
               checked: bms.DtHighTempCurrent,
               onClicked: function(checked) {bms.setDtHighTempCurrent(checked)}
            },
            {
               text: qsTr("DT Pack Current"),
               checked: bms.DtPackCurrent,
               onClicked: bms.setDtPackCurrent(checked),
            },
            {
               text: qsTr("Protection"),
               checked: bms.Protection,
               onClicked: function(checked) {bms.setProtection(checked)},
            },
            {
               text: qsTr("Orion Timeout"),
               checked: bms.OrionTimeout,
               onClicked: function(checked) {bms.setOrionTimeout(checked)},
            },
            {
               text: qsTr("CNC High Current"),
               checked: bms.CncHighCurrent,
               onClicked: function(checked) {bms.setCncHighCurrent(checked)},
            },
            {
               text: qsTr("DNC High Current"),
               checked: bms.DncHighCurrent,
               onClicked: function(checked) {bms.setDncHighCurrent(checked)},
            },
            {
               text: qsTr("Contactor Disconnected"),
               checked: bms.ContactorDisconnected,
               onClicked: function(checked){bms.setContactorDisconnected(checked)}
            }
        ]
    }

    Rectangle {
        id: rectangle
        x: 172
        y: 26
        width: 218
        height: 262
        color: "#dddddd"
        radius: 25
        z: -1
    }

    Rectangle {
        id: rectangle1
        x: 409
        y: 26
        width: 327
        height: 288
        color: "#dddddd"
        radius: 25
        z: -1
    }

    Rectangle {
        id: rectangle2
        x: 172
        y: 320
        width: 470
        height: 246
        color: "#dddddd"
        radius: 25
        z: -1
    }

    Rectangle {
        id: rectangle3
        x: 0
        y: 0
        width: 750
        height: 650
        color: "#8b8b8b"
        radius: 25
        z: -2
    }

    BytePreview{
        id:bytePreview
        raw:bms.byteStreamStr
        encoded:bms.encodedByteStreamStr
    }
}
