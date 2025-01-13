import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.0

Item {
    width: 750
    height: 650

    SpinBox {
        id: spinBox
        x: 22
        y: 39
        width: 119
        height: 37
        to: 255
        editable: true
        value: bms.PrechargeState
        onValueChanged: bms.setPrechargeState(value)
    }

    Text {
        id: text1
        x: 38
        y: 19
        text: qsTr("Precharge State")
        font.pixelSize: 12
    }

    SpinBox {
        id: spinBox1
        x: 22
        y: 102
        width: 119
        height: 37
        to: 255
        editable: true
        value: bms.AuxVoltage
        onValueChanged: bms.setAuxVoltage(value)
    }

    Text {
        id: text2
        x: 49
        y: 82
        text: qsTr("Aux Voltage")
        font.pixelSize: 12
    }

    Switch {
        id: switch1
        x: 181
        y: 42
        text: qsTr("Aux BMS Alive")
        checked: bms.BmsAlive
        onClicked: bms.setBmsAlive(checked)
    }

    Switch {
        id: switch2
        x: 181
        y: 80
        width: 188
        height: 32
        text: qsTr("Strobe BMS Light")
        checked: bms.StrobeLight
        onClicked: bms.setStrobeLight(checked)
    }

    Switch {
        id: switch3
        x: 181
        y: 118
        text: qsTr("Allow Charge")
        checked: bms.AllowCharge
        onClicked: bms.setAllowCharge(checked)
    }

    Switch {
        id: switch4
        x: 181
        y: 156
        width: 214
        height: 32
        text: qsTr("High Voltage Enable")
        checked: bms.HighVoltageEnable
        onClicked: bms.setHighVoltageEnable(checked)
    }

    Switch {
        id: switch5
        x: 181
        y: 194
        width: 197
        height: 32
        text: qsTr("Allow Discharge")
        checked: bms.AllowDischarge
        onClicked: bms.setAllowDischarge(checked)
    }

    Switch {
        id: switch6
        x: 181
        y: 232
        width: 205
        height: 32
        text: qsTr("Orion Can Recieved")
        checked: bms.OrionRecieved
        onClicked: bms.setOrionRecieved(checked)
    }

    Switch {
        id: switch7
        x: 409
        y: 42
        width: 188
        height: 32
        text: qsTr("Charge Contactor")
        checked: bms.ChargeContactor
        onClicked: bms.setChargeContactor(checked)
    }

    Switch {
        id: switch8
        x: 409
        y: 80
        width: 188
        height: 32
        text: qsTr("Discharge Contactor")
        checked: bms.DischargeContactor
        onClicked: bms.setDischargeContactor(checked)
    }

    Switch {
        id: switch9
        x: 409
        y: 118
        text: qsTr("Common Contactor")
        checked: bms.CommonContactor
        onClicked: bms.setCommonContactor(checked)
    }

    Switch {
        id: switch10
        x: 409
        y: 156
        width: 214
        height: 32
        text: qsTr("Discharge Should")
        checked: bms.DischargeShould
        onClicked: bms.setDischargeShould(checked)
    }

    Switch {
        id: switch11
        x: 409
        y: 194
        width: 197
        height: 32
        text: qsTr("Charge Should")
        checked: bms.ChargeShould
        onClicked: bms.setChargeShould(checked)
    }

    Switch {
        id: switch12
        x: 409
        y: 232
        width: 305
        height: 32
        text: qsTr("Charge Open But Should Be Closed")
        checked: bms.ChargeOpen
        onClicked: bms.setChargeOpen(checked)
    }

    Switch {
        id: switch13
        x: 409
        y: 270
        width: 321
        height: 32
        text: qsTr("Discharge Open But Should Be Closed")
        checked: bms.DischargeOpen
        onClicked: bms.setDischargeOpen(checked)
    }

    Switch {
        id: switch14
        x: 181
        y: 327
        width: 209
        height: 32
        text: qsTr("CT High Cell Voltage")
        checked: bms.CtHighCellVoltage
        onClicked: bms.setCtHighCellVoltage(checked)
    }

    Switch {
        id: switch15
        x: 181
        y: 365
        width: 221
        height: 32
        text: qsTr("CT High Temp/Current")
        checked: bms.CtHighTempCurrent
        onClicked: bms.setCtHighTempCurrent(checked)
    }

    Switch {
        id: switch16
        x: 181
        y: 403
        text: qsTr("CT Pack Current")
        checked: bms.CtPackCurrent
        onClicked: bms.setCtPackCurrent(checked)
    }

    Switch {
        id: switch17
        x: 181
        y: 441
        width: 214
        height: 32
        text: qsTr("DT Low Cell Voltage")
        checked: bms.DtLowCellVoltage
        onClicked: bms.setDtLowCellVoltage(checked)
    }

    Switch {
        id: switch18
        x: 181
        y: 479
        width: 221
        height: 32
        text: qsTr("DT High Temp/Current")
        checked: bms.DtHighTempCurrent
        onClicked: bms.setDtHighTempCurrent(checked)
    }

    Switch {
        id: switch19
        x: 181
        y: 517
        width: 181
        height: 32
        text: qsTr("DT Pack Current")
        checked: bms.DtPackCurrent
        onClicked: bms.setDtPackCurrent(checked)
    }

    Switch {
        id: switch20
        x: 409
        y: 327
        width: 150
        height: 32
        text: qsTr("Protection")
        checked: bms.Protection
        onClicked: bms.setProtection(checked)
    }

    Switch {
        id: switch21
        x: 409
        y: 365
        width: 181
        height: 32
        text: qsTr("Orion Timeout")
        checked: bms.OrionTimeout
        onClicked: bms.setOrionTimeout(checked)
    }

    Switch {
        id: switch22
        x: 409
        y: 403
        width: 201
        height: 32
        text: qsTr("CNC High Current")
        checked: bms.CncHighCurrent
        onClicked: bms.setCncHighCurrent(checked)
    }

    Switch {
        id: switch23
        x: 409
        y: 441
        width: 201
        height: 32
        text: qsTr("DNC High Current")
        checked: bms.DncHighCurrent
        onClicked: bms.setDncHighCurrent(checked)
    }

    Switch {
        id: switch24
        x: 409
        y: 479
        width: 233
        height: 32
        text: qsTr("Contactor Disconnected")
        checked: bms.ContactorDisconnected
        onClicked: bms.setContactorDisconnected(checked)
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

    Text {
        id: driverControlsStream
        x: 27
        y: 586
        width: 665
        height: 14
        text: "Byte Stream: " + bms.byteStreamStr
        font.pixelSize: 16
    }

    Text {
        id: driverControlsStream1
        x: 27
        y: 606
        width: 665
        height: 14
        text: "Encoded Stream: " + bms.encodedByteStreamStr
        font.pixelSize: 16
    }
}
