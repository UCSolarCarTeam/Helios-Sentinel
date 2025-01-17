
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0


Item {
    property var motorDetailsElysia
    width: 660
    height: 620

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 660
        height: 620
        color: "#79ed8d"
        radius: 25

        Text {
            id: text2
            x: 267
            y: 22
            text: qsTr("Motor " + motorDetailsElysia.motorNum + " Details")
            font.pixelSize: 20
        }

        GroupItem {
            x: 47
            y: 76

            GroupItem {
                x: 2
                y: 0
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.phaseCCurrent
                    onValueChanged: motorDetailsElysia.setPhaseCCurrent(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Phase C Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 2
                y: 65
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.phaseBCurrent
                    onValueChanged: motorDetailsElysia.setPhaseBCurrent(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Phase B Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 3
                y: 133
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.motorVoltageReal
                    onValueChanged: motorDetailsElysia.setMotorVoltageReal(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Motor Voltage Real")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 197
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.motorVoltageImag
                    onValueChanged: motorDetailsElysia.setMotorVoltageImag(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Motor Voltage Imaginary")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 261
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.motorCurrentReal
                    onValueChanged: motorDetailsElysia.setMotorCurrentReal(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Motor Current Real")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 318
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.motorCurrentImag
                    onValueChanged: motorDetailsElysia.setMotorCurrentImag(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Motor Current Imaginary")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 374
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.blackEMF
                    onValueChanged: motorDetailsElysia.setBlackEMF(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Black EMF")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 3
                y: 436
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.voltageRailSupply15
                    onValueChanged: motorDetailsElysia.setVoltageRailSupply15(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("15V Voltage Rail Supply")
                    font.pixelSize: 12
                }
            }
        }

        GroupItem {
            x: 355
            y: 76
            GroupItem {
                x: 2
                y: 0
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.voltageRailSupply3
                    onValueChanged: motorDetailsElysia.setVoltageRailSupply3(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("3.3V Voltage Rail Supply")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 2
                y: 65
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.voltageRailSupply2
                    onValueChanged: motorDetailsElysia.setVoltageRailSupply2(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("1.9V Voltage Rail Supply")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 3
                y: 133
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.heatSinkTemp
                    onValueChanged: motorDetailsElysia.setHeatSinkTemp(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Heat-sink Temperature")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 197
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.motorTemp
                    onValueChanged: motorDetailsElysia.setMotorTemp(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Motor Temperature")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 261
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.dspBoardTemp
                    onValueChanged: motorDetailsElysia.setDspBoardTemp(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("DSP Boaprd Tem")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 318
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.dcBusAmpHours
                    onValueChanged: motorDetailsElysia.setDcBusAmpHours(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("DC Bus AmpHours")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 374
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.odometer
                    onValueChanged: motorDetailsElysia.setOdometer(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Odometer")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 3
                y: 436
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetailsElysia.slipSpeed
                    onValueChanged: motorDetails.setSlipSpeed(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Slip Speed")
                    font.pixelSize: 12
                }
            }
        }
    }
    Text {
        id: text22
        x: 43
        y: 550
        width: 442
        height: 14
        text: "Byte Stream: " + motorDetailsElysia.byteStreamStr
        font.pixelSize: 16
    }

    Text {
        id: text23
        x: 43
        y: 580
        width: 442
        height: 14
        text: "Encoded Stream: " + motorDetailsElysia.encodedByteStreamStr
        font.pixelSize: 16
    }
}
