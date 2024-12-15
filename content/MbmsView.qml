import QtQuick 2.15
import QtQuick.Controls 6.2
import QtQuick.Studio.Components 1.0


Item {
        id: rectangle
        x: 0
        y: 0
        width: 818
        height: 691

        GroupItem {
            x: 72
            y: 14

            Text {
                id: text1
                x: 61
                y: 0
                text: qsTr("Contactor Status")
                font.pixelSize: 14
            }

            Switch {
                id: switch1
                x: 0
                y: 23
                text: qsTr("Common")
                checked: mbms.commonContactorState
                onClicked: mbms.setCommonContactorState(checked)
            }

            Switch {
                id: switch2
                x: 124
                y: 23
                text: qsTr("Motor")
                checked: mbms.motorContactorState
                onClicked: mbms.setMotorContactorState(checked)
            }

            Switch {
                id: switch3
                x: 0
                y: 62
                text: qsTr("Array")
                checked: mbms.arrayContactorState
                onClicked: mbms.setArrayContactorState(checked)
            }

            Switch {
                id: switch4
                x: 124
                y: 62
                text: qsTr("LV")
                checked: mbms.lvContactorState
                onClicked: mbms.setLvContactorState(checked)
            }

            Switch {
                id: switch5
                x: 45
                y: 101
                text: qsTr("Charge")
                checked: mbms.chargeContactorState
                onClicked: mbms.setChargeContactorState(checked)
            }
        }

        GroupItem {
            x: 428
            y: 14
            Text {
                x: 61
                y: 0
                text: qsTr("Contactor Error")
                font.pixelSize: 14
            }

            Switch {
                x: 0
                y: 23
                text: qsTr("Common")
                checked: mbms.commonContactorError
                onClicked: mbms.setCommonContactorError(checked)
            }

            Switch {
                x: 124
                y: 23
                text: qsTr("Motor")
                checked: mbms.motorContactorError
                onClicked: mbms.setMotorContactorError(checked)
            }

            Switch {
                x: 0
                y: 62
                text: qsTr("Array")
                checked: mbms.arrayContactorError
                onClicked: mbms.setArrayContactorError(checked)
            }

            Switch {
                x: 124
                y: 62
                text: qsTr("LV")
                checked: mbms.lvContactorError
                onClicked: mbms.setLvContactorError(checked)
            }

            Switch {
                x: 45
                y: 101
                text: qsTr("Charge")
                checked: mbms.chargeContactorError
                onClicked: mbms.setChargeContactorError(checked)
            }
        }

        GroupItem {
            x: 8
            y: 180
            Text {
                x: 109
                y: 0
                text: qsTr("Misc Status")
                font.pixelSize: 14
            }

            Switch {
                x: 0
                y: 23
                text: qsTr("Strobe BMS")
                checked: mbms.strobeBmsLight
                onClicked: mbms.setStrobeBmsLight(checked)
                font.pointSize: 10
            }

            Switch {
                x: 151
                y: 23
                text: qsTr("Allow Charge")
                checked: mbms.allowCharge
                onClicked: mbms.setAllowCharge(checked)
            }

            Switch {
                x: 0
                y: 62
                text: qsTr("High Voltage Enable")
                checked: mbms.highVoltageEnableState
                onClicked: mbms.setHighVoltageEnableState(checked)
                font.pointSize: 8
            }

            Switch {
                x: 151
                y: 62
                text: qsTr("Allow Discharge")
                checked: mbms.allowDischarge
                onClicked: mbms.setAllowDischarge(checked)
            }

            Switch {
                x: 0
                y: 101
                text: qsTr("OrionCAN Received")
                checked: mbms.orionCanReceivedRecently
                onClicked: mbms.setOrionCanReceivedRecently(checked)
                font.pointSize: 8
            }

            Switch {
                x: 151
                y: 99
                text: qsTr("Discharge Should Trip")
                checked: mbms.dischargeShouldTrip
                onClicked: mbms.setDischargeShouldTrip(checked)
                font.pointSize: 10
            }

            Switch {
                id: switch6
                x: 98
                y: 134
                text: qsTr("Charge Should Trip")
                checked: mbms.chargeShouldTrip
                onClicked: mbms.setChargeShouldTrip(checked)
            }
        }

        GroupItem {
            x: 380
            y: 180
            Text {
                x: 109
                y: 0
                text: qsTr("Trip Status")
                font.pixelSize: 14
            }

            Switch {
                x: 0
                y: 23
                text: qsTr("High Cell Voltage")
                checked: mbms.highCellVoltageTrip
                onClicked: mbms.setHighCellVoltageTrip(checked)
                font.pointSize: 10
            }

            Switch {
                x: 151
                y: 23
                text: qsTr("Low Cell Voltage")
                checked: mbms.lowCellVoltageTrip
                onClicked: mbms.setLowCellVoltageTrip(checked)
            }

            Switch {
                x: 0
                y: 62
                text: qsTr("High Common Current")
                checked: mbms.highCommonCurrentTrip
                onClicked: mbms.setHighCommonCurrentTrip(checked)
                font.pointSize: 8
            }

            Switch {
                x: 151
                y: 62
                text: qsTr("Motor High TC")
                checked: mbms.motorTCTrip
                onClicked: mbms.setMotorTCTrip(checked)
            }

            Switch {
                x: 0
                y: 98
                text: qsTr("Array High TC")
                checked: mbms.arrayTCTrip
                onClicked: mbms.setArrayTCTrip(checked)
                font.pointSize: 12
            }

            Switch {
                x: 151
                y: 99
                text: qsTr("LV High TC")
                checked: mbms.lvTCTrip
                onClicked: mbms.setLvTCTrip(checked)
                font.pointSize: 10
            }

            Switch {
                x: 0
                y: 133
                text: qsTr("Charge High TC")
                checked: mbms.chargeTCTrip
                onClicked: mbms.setChargeTCTrip(checked)
                font.pointSize: 10
                spacing: 8
                icon.width: 16
            }

            Switch {
                x: 151
                y: 133
                text: qsTr("Protection")
                checked: mbms.protectionTrip
                onClicked: mbms.setProtectionTrip(checked)
            }

            Switch {
                x: 0
                y: 168
                text: qsTr("Orion Message Timeout")
                checked: mbms.orionMessageTimeoutTrip
                onClicked: mbms.setOrionMessageTimeoutTrip(checked)
                font.pointSize: 7
            }

            Switch {
                x: 151
                y: 168
                text: qsTr("Contactor Disconnect")
                checked: mbms.contactorDisconnectedTrip
                onClicked: mbms.setContactorDisconnectedTrip(checked)
            }
        }

        GroupItem {
            x: 8
            y: 391

            SpinBox {
                id: spinBox
                x: 0
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.auxillaryBatteryVoltage
                onValueChanged: mbms.setAuxillaryBatteryVoltage(value)
            }

            SpinBox {
                id: spinBox1
                x: 161
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.motorVoltage
                onValueChanged: mbms.setMotorVoltage(value)
            }

            SpinBox {
                id: spinBox2
                x: 323
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.arrayVoltage
                onValueChanged: mbms.setArrayVoltage(value)
            }

            SpinBox {
                id: spinBox3
                x: 490
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.lvVoltage
                onValueChanged: mbms.setLvVoltage(value)
            }

            SpinBox {
                id: spinBox4
                x: 662
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.chargeVoltage
                onValueChanged: mbms.setChargeVoltage(value)
            }

            Text {
                id: text2
                x: 12
                y: 62
                text: qsTr("AUX Battery Voltage")
                font.pixelSize: 12
            }

            Text {
                id: text3
                x: 192
                y: 61
                text: qsTr("Motor Voltage")
                font.pixelSize: 12
            }

            Text {
                id: text4
                x: 363
                y: 61
                text: qsTr("Array Voltage")
                font.pixelSize: 12
            }

            Text {
                id: text5
                x: 530
                y: 61
                text: qsTr("LV Voltage")
                font.pixelSize: 12
            }

            Text {
                id: text6
                x: 687
                y: 61
                text: qsTr("Charge Voltage")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 8
            y: 505

            SpinBox {
                id: spinBox5
                x: 0
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.commonCurrent
                onValueChanged: mbms.setCommonCurrent(value)
            }

            SpinBox {
                id: spinBox6
                x: 161
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.motorCurrent
                onValueChanged: mbms.setMotorCurrent(value)
            }

            SpinBox {
                id: spinBox7
                x: 323
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.arrayCurrent
                onValueChanged: mbms.setArrayCurrent(value)
            }

            SpinBox {
                id: spinBox8
                x: 490
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.lvCurrent
                onValueChanged: mbms.setLvCurrent(value)
            }

            SpinBox {
                id: spinBox9
                x: 662
                y: 0
                from: 0
                to: 65535
                editable: true
                value: mbms.chargeCurrent
                onValueChanged: mbms.setChargeCurrent(value)
            }

            Text {
                x: 12
                y: 62
                text: qsTr("Common Current")
                font.pixelSize: 12
            }

            Text {
                x: 192
                y: 61
                text: qsTr("Motor Current")
                font.pixelSize: 12
            }

            Text {
                x: 363
                y: 61
                text: qsTr("Array Current")
                font.pixelSize: 12
            }

            Text {
                x: 530
                y: 61
                text: qsTr("LV Current")
                font.pixelSize: 12
            }

            Text {
                x: 687
                y: 61
                text: qsTr("Charge Current")
                font.pixelSize: 12
            }
        }

        Text {
            id: text7
            x: 72
            y: 616
            text: qsTr("Byte Stream: " + mbms.byteStreamStr)
            font.pixelSize: 12
        }

        Text {
            id: text8
            x: 72
            y: 651
            text: qsTr("Encoded ByteStream: " + mbms.encodedByteStreamStr)
            font.pixelSize: 12
        }
}
