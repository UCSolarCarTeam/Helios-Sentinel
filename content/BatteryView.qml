import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 550
    height: 850

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20
        
        Text {
            text: "Battery Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Column {
            spacing: 20

            Switch {
                id: switch1
                text: qsTr("BMU Alive")
                checked: battery.alive
                onClicked: battery.setAlive(checked)
            }

            FlagBox {
                title: "BMS Relay Flags"
                flags: [
                    {
                        text: qsTr("Discharge Relay"),
                        checked: battery.dischargeRelay,
                        onClicked: function(checked) { battery.setDischargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charge Relay"),
                        checked: battery.chargeRelay,
                        onClicked: function(checked) { battery.setChargeRelay(checked) }
                    },
                    {
                        text: qsTr("Charger Safety"),
                        checked: battery.chargerSafety,
                        onClicked: function(checked) { battery.setChargerSafety(checked) }
                    },
                    {
                        text: qsTr("Malfunction Indicator"),
                        checked: battery.malfunctionIndicator,
                        onClicked: function(checked) { battery.setMalfunctionIndicator(checked) }
                    },
                    {
                        text: qsTr("Multi-Purpose Input Signal"),
                        checked: battery.multiPurposeInputSignal,
                        onClicked: function(checked) { battery.setMultiPurposeInputSignal(checked) }
                    },
                    {
                        text: qsTr("Always-on Signal"),
                        checked: battery.alwaysOnSignal,
                        onClicked: function(checked) { battery.setAlwaysOnSignal(checked) }
                    },
                    {
                        text: qsTr("Is-Ready Signal"),
                        checked: battery.isReadySignal,
                        onClicked: function(checked) { battery.setIsReadySignal(checked) }
                    },
                    {
                        text: qsTr("Is-Charging Signal"),
                        checked: battery.isChargingSignal,
                        onClicked: function(checked) { battery.setIsChargingSignal(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Populated Cells")
                        value: battery.populatedCells
                        onValueChanged: battery.setPopulatedCells(value)
                    }

                    IntSpinBox {
                        text: qsTr("12V Input")
                        value: battery.input12V
                        onValueChanged: battery.setInput12V(value)
                    }

                    IntSpinBox {
                        text: qsTr("Fan Voltage")
                        value: battery.fanVoltage
                        onValueChanged: battery.setFanVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack Current")
                        value: battery.packCurrent
                        onValueChanged: battery.setPackCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack Voltage")
                        value: battery.packVoltage
                        onValueChanged: battery.setPackVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack SOC")
                        value: battery.packSoc
                        onValueChanged: battery.setPackSoc(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack Amphours")
                        value: battery.packAmphours
                        onValueChanged: battery.setPackAmphours(value)
                    }

                    IntSpinBox {
                        text: qsTr("Pack DOD")
                        value: battery.packDod
                        onValueChanged: battery.setPackDod(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Temp")
                        value: battery.highTemp
                        onValueChanged: battery.setHighTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Thermistor ID")
                        value: battery.highThermistorId
                        onValueChanged: battery.setHighThermistorId(value)
                    }
                }

                Column {
                    spacing: 20
                    width: 245

                    IntSpinBox {
                        text: qsTr("Low Temp")
                        value: battery.lowTemp
                        onValueChanged: battery.setLowTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Thermistor ID")
                        value: battery.lowThermistorId
                        onValueChanged: battery.setLowThermistorId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Temp")
                        value: battery.avgTemp
                        onValueChanged: battery.setAvgTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Internal Temp")
                        value: battery.internalTemp
                        onValueChanged: battery.setInternalTemp(value)
                    }

                    IntSpinBox {
                        text: qsTr("Fan Speed")
                        value: battery.fanSpeed
                        onValueChanged: battery.setFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Req. Fan Speed")
                        value: battery.reqFanSpeed
                        onValueChanged: battery.setReqFanSpeed(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage")
                        value: battery.lowCellVoltage
                        onValueChanged: battery.setLowCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("Low Cell Voltage ID")
                        value: battery.lowCellVoltageId
                        onValueChanged: battery.setLowCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage")
                        value: battery.highCellVoltage
                        onValueChanged: battery.setHighCellVoltage(value)
                    }

                    IntSpinBox {
                        text: qsTr("High Cell Voltage ID")
                        value: battery.highCellVoltageId
                        onValueChanged: battery.setHighCellVoltageId(value)
                    }

                    IntSpinBox {
                        text: qsTr("Avg Cell Voltage")
                        value: battery.avgCellVoltage
                        onValueChanged: battery.setAvgCellVoltage(value)
                    }
                }
            }
        }

        BytePreview {
            id: bytePreview
            raw: battery.byteStreamStr
            encoded: battery.encodedByteStreamStr
        }
    }

    // Switch {
    //     id: switch1
    //     x: 38
    //     y: 27
    //     text: qsTr("BMU")
    //     checked: battery.bmuAlive
    //     onClicked: battery.setBmuAlive(checked)
    // }

    // Switch {
    //     id: switch2
    //     x: 173
    //     y: 27
    //     text: qsTr("Discharge Relay")
    //     checked: battery.dischargeRelay
    //     onClicked: battery.setDischargeRelay(checked)
    // }

    // Switch {
    //     id: switch3
    //     x: 173
    //     y: 74
    //     text: qsTr("Charge Relay")
    //     checked: battery.chargeRelay
    //     onClicked: battery.setChargeRelay(checked)
    // }

    // Switch {
    //     id: switch4
    //     x: 173
    //     y: 121
    //     text: qsTr("Charger Safety")
    //     checked: battery.chargerSafety
    //     onClicked: battery.setChargerSafety(checked)
    // }

    // Switch {
    //     id: switch5
    //     x: 173
    //     y: 175
    //     text: qsTr("Malfunction Indicator")
    //     checked: battery.malfunctionIndicator
    //     onClicked: battery.setMalfunctionIndicator(checked)
    // }

    // Switch {
    //     id: switch6
    //     x: 386
    //     y: 27
    //     text: qsTr("Multi-Purpose Input Signal")
    //     checked: battery.multiPurposeInputSignal
    //     onClicked: battery.setMultiPurposeInputSignal(checked)
    // }

    // Switch {
    //     id: switch7
    //     x: 386
    //     y: 74
    //     text: qsTr("Always-on Signal")
    //     checked: battery.alwaysOnSignal
    //     onClicked: battery.setAlwaysOnSignal(checked)
    // }

    // Switch {
    //     id: switch8
    //     x: 386
    //     y: 121
    //     text: qsTr("Is-Ready Signal")
    //     checked: battery.isReadySignal
    //     onClicked: battery.setIsReadySignal(checked)
    // }

    // Switch {
    //     id: switch9
    //     x: 386
    //     y: 175
    //     text: qsTr("Is-Charging Signal")
    //     checked: battery.isChargingSignal
    //     onClicked: battery.setIsChargingSignal(checked)
    // }

    // SpinBox {
    //     id: spinBox
    //     x: 38
    //     y: 259
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.populatedCells
    //     onValueChanged: battery.setPopulatedCells(value)
    // }


    // Text {
    //     id: text1
    //     x: 43
    //     y: 239
    //     text: qsTr("Populated Cells")
    //     font.pixelSize: 12
    // }

    // FloatSpinBox {
    //     id: floatSpinBox1
    //     x:138
    //     y:259
    //     width:94
    //     height:36
    //     value: decimalToInt(battery.input12V)
    //     stepSize: decimalToInt(0.5)
    //     onValueChanged: battery.setInput12V(value / decimalFactor)
    // }



    // Text {
    //     id: text2
    //     x: 136
    //     y: 239
    //     text: qsTr("12V Input Voltage")
    //     font.pixelSize: 12
    // }

    // FloatSpinBox {
    //     id: floatSpinBox2
    //     x: 238
    //     y: 259
    //     width: 94
    //     height: 36
    //     value: decimalToInt(battery.fanVoltage)
    //     onValueChanged: battery.setFanVoltage(value/decimalFactor)
    //     stepSize: decimalToInt(0.5)
    // }

    // Text {
    //     id: text3
    //     x: 253
    //     y: 239
    //     text: qsTr("Fan Voltage")
    //     font.pixelSize: 12
    // }

    // FloatSpinBox {
    //     id: floatSpinBox3
    //     x: 338
    //     y: 259
    //     width: 94
    //     height: 36
    //     value: decimalToInt(battery.packCurrent)
    //     onValueChanged: battery.setPackCurrent(value/decimalFactor)
    //     stepSize: decimalToInt(0.5)
    // }

    // Text {
    //     id: text4
    //     x: 350
    //     y: 239
    //     text: qsTr("Pack Current")
    //     font.pixelSize: 12
    // }

    // FloatSpinBox {
    //     id: floatSpinBox4
    //     x: 438
    //     y: 259
    //     width: 94
    //     height: 36
    //     editable: true
    //     value: decimalToInt(battery.packVoltage)
    //     onValueChanged: battery.setPackVoltage(value/decimalFactor)
    //     stepSize: decimalToInt(0.5)
    // }

    // Text {
    //     id: text5
    //     x: 450
    //     y: 239
    //     text: qsTr("Pack Voltage")
    //     font.pixelSize: 12
    // }

    // FloatSpinBox {
    //     id: floatSpinBox5
    //     x: 538
    //     y: 259
    //     width: 94
    //     height: 36
    //     editable: true
    //     value: decimalToInt(battery.packSoc)
    //     onValueChanged: battery.setPackSoc(value/decimalFactor)
    //     stepSize: decimalToInt(0.5)
    // }

    // Text {
    //     id: text6
    //     x: 563
    //     y: 239
    //     text: qsTr("Pack SOC")
    //     font.pixelSize: 12
    // }

    // FloatSpinBox {
    //     id: floatSpinBox6
    //     x: 638
    //     y: 259
    //     width: 94
    //     height: 36
    //     editable: true
    //     value: decimalToInt(battery.packAmphours)
    //     onValueChanged: battery.setPackAmphours(value/decimalFactor)
    //      stepSize: decimalToInt(0.5)
    // }

    // Text {
    //     id: text7
    //     x: 643
    //     y: 239
    //     text: qsTr("Pack Amphours")
    //     font.pixelSize: 12
    // }

    // FloatSpinBox {
    //     id: floatSpinBox7
    //     x: 42
    //     y: 326
    //     width: 94
    //     height: 36
    //     value: decimalToInt(battery.setPackDod)
    //     onValueChanged: battery.setPackDod(value/decimalFactor)
    // }

    // Text {
    //     id: text8
    //     x: 62
    //     y: 306
    //     text: qsTr("Pack DOD")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox8
    //     x: 142
    //     y: 326
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.highTemp
    //     onValueChanged: battery.setHighTemp(value)
    // }

    // Text {
    //     id: text9
    //     x: 160
    //     y: 306
    //     text: qsTr("High Temp")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox9
    //     x: 242
    //     y: 326
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.highThermistorId
    //     onValueChanged: battery.setHighThermistorId(value)
    // }

    // Text {
    //     id: text10
    //     x: 234
    //     y: 306
    //     text: qsTr("High Thermistor ID")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox10
    //     x: 342
    //     y: 326
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.lowTemp
    //     onValueChanged: battery.setLowTemp(value)
    // }

    // Text {
    //     id: text11
    //     x: 357
    //     y: 306
    //     text: qsTr("Low Temp")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox11
    //     x: 442
    //     y: 326
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.lowThermistorId
    //     onValueChanged: battery.setLowThermistorId(value)
    // }

    // Text {
    //     id: text12
    //     x: 435
    //     y: 306
    //     text: qsTr("Low Thermistor ID")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox12
    //     x: 542
    //     y: 326
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.avgTemp
    //     onValueChanged: battery.setAvgTemp(value)
    // }

    // Text {
    //     id: text13
    //     x: 563
    //     y: 306
    //     text: qsTr("Avg Temp")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox13
    //     x: 642
    //     y: 326
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.internalTemp
    //     onValueChanged: battery.setInternalTemp(value)
    // }

    // Text {
    //     id: text14
    //     x: 652
    //     y: 306
    //     text: qsTr("Internal Temp")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox14
    //     x: 42
    //     y: 394
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.fanSpeed
    //     onValueChanged: battery.setFanSpeed(value)
    // }

    // Text {
    //     id: text15
    //     x: 64
    //     y: 374
    //     text: qsTr("Fan Speed")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox15
    //     x: 142
    //     y: 394
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.reqFanSpeed
    //     onValueChanged: battery.setReqFanSpeed(value)
    // }

    // Text {
    //     id: text16
    //     x: 147
    //     y: 374
    //     text: qsTr("Req. Fan Speed")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox16
    //     x: 242
    //     y: 394
    //     width: 94
    //     height: 36
    //     to: 65535
    //     editable: true
    //     value: battery.lowCellVoltage
    //     onValueChanged: battery.setLowCellVoltage(value)
    // }

    // Text {
    //     id: text17
    //     x: 241
    //     y: 374
    //     text: qsTr("Low Cell Voltage")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox17
    //     x: 342
    //     y: 394
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.lowCellVoltageId
    //     onValueChanged: battery.setLowCellVoltageId(value)
    // }

    // Text {
    //     id: text18
    //     x: 344
    //     y: 374
    //     text: qsTr("Low Cell Volt. ID")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox18
    //     x: 442
    //     y: 394
    //     width: 94
    //     height: 36
    //     to: 65535
    //     editable: true
    //     value: battery.highCellVoltage
    //     onValueChanged: battery.setHighCellVoltage(value)
    // }

    // Text {
    //     id: text19
    //     x: 442
    //     y: 374
    //     text: qsTr("High Cell Voltage")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox19
    //     x: 542
    //     y: 394
    //     width: 94
    //     height: 36
    //     to: 255
    //     editable: true
    //     value: battery.highCellVoltageId
    //     onValueChanged: battery.setHighCellVoltageId(value)
    // }

    // Text {
    //     id: text20
    //     x: 542
    //     y: 374
    //     text: qsTr("High Cell Volt. ID")
    //     font.pixelSize: 12
    // }

    // SpinBox {
    //     id: spinBox20
    //     x: 642
    //     y: 394
    //     width: 94
    //     height: 36
    //     to: 65535
    //     editable: true
    //     value: battery.avgCellVoltage
    //     onValueChanged: battery.setAvgCellVoltage(value)
    // }

    // Text {
    //     id: text21
    //     x: 647
    //     y: 374
    //     text: qsTr("Avg Cell Voltage")
    //     font.pixelSize: 12
    // }

    // Rectangle {
    //     id: rectangle
    //     x: 0
    //     y: 0
    //     width: 775
    //     height: 500
    //     color: "#e9fba6"
    //     radius: 25
    //     z: -1
    // }

    // Text {
    //     id: text22
    //     x: 43
    //     y: 444
    //     width: 442
    //     height: 14
    //     text: "Byte Stream: " + battery.byteStreamStr
    //     font.pixelSize: 16
    // }

    // Text {
    //     id: text23
    //     x: 43
    //     y: 469
    //     width: 442
    //     height: 14
    //     text: "Encoded Stream: " + battery.encodedByteStreamStr
    //     font.pixelSize: 16
    // }
}
