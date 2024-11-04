import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0


Item {
    property var motorDetails
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
            text: qsTr("Motor " + motorDetails.motorNum + " Details")
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
                    value: motorDetails.controlValue
                    onValueChanged: motorDetails.setControlValue(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Control Value")
                    font.pixelSize: 12
                }
            }
            Switch {
                id: switch1
                x: 2
                y: 65
                width: 135
                height: 37
                text: qsTr("Control Mode")
                checked: motorDetails.controlMode
                onClicked: motorDetails.setControlMode(checked)
            }
            Switch {
                id: switch2
                x: 2
                y: 105
                width: 135
                height: 37
                text: qsTr("Motor Mode")
                checked: motorDetails.motorMode
                onClicked: motorDetails.setMotorMode(checked)
            }
            Switch {
                id: switch3
                x: 2
                y: 145
                width: 135
                height: 37
                text: qsTr("Software Enabled")
                checked: motorDetails.softwareEnable
                onClicked: motorDetails.setSoftwareEnable(checked)
            }
            Switch {
                id: switch4
                x: 2
                y: 185
                width: 135
                height: 37
                text: qsTr("Debug Mode")
                checked: motorDetails.debugMode
                onClicked: motorDetails.setDebugMode(checked)
            }

            // GroupItem {
            //     x: 2
            //     y: 65
            //     SpinBox {
            //         x: 0
            //         y: 0
            //         width: 99
            //         height: 30
            //         value: motorDetails.phaseBCurrent
            //         onValueChanged: motorDetails.setPhaseBCurrent(value)
            //     }

            //     Text {
            //         x: 123
            //         y: 8
            //         text: qsTr("Phase B Current")
            //         font.pixelSize: 12
            //     }
            // }

            // GroupItem {
            //     x: 3
            //     y: 133
            //     SpinBox {
            //         x: 0
            //         y: 0
            //         width: 99
            //         height: 30
            //         value: motorDetails.motorVoltageReal
            //         onValueChanged: motorDetails.setMotorVoltageReal(value)
            //     }

            //     Text {
            //         x: 123
            //         y: 8
            //         text: qsTr("Motor Voltage Real")
            //         font.pixelSize: 12
            //     }
            // }

            // GroupItem {
            //     x: 0
            //     y: 197
            //     SpinBox {
            //         x: 0
            //         y: 0
            //         width: 99
            //         height: 30
            //         value: motorDetails.motorVoltageImag
            //         onValueChanged: motorDetails.setMotorVoltageImag(value)
            //     }

            //     Text {
            //         x: 123
            //         y: 8
            //         text: qsTr("Motor Voltage Imaginary")
            //         font.pixelSize: 12
            //     }
            // }

            // GroupItem {
            //     x: 0
            //     y: 261
            //     SpinBox {
            //         x: 0
            //         y: 0
            //         width: 99
            //         height: 30
            //         value: motorDetails.motorCurrentReal
            //         onValueChanged: motorDetails.setMotorCurrentReal(value)
            //     }

            //     Text {
            //         x: 123
            //         y: 8
            //         text: qsTr("Motor Current Real")
            //         font.pixelSize: 12
            //     }
            // }

            // GroupItem {
            //     x: 0
            //     y: 318
            //     SpinBox {
            //         x: 0
            //         y: 0
            //         width: 99
            //         height: 30
            //         value: motorDetails.motorCurrentImag
            //         onValueChanged: motorDetails.setMotorCurrentImag(value)
            //     }

            //     Text {
            //         x: 123
            //         y: 8
            //         text: qsTr("Motor Current Imaginary")
            //         font.pixelSize: 12
            //     }
            // }

            // GroupItem {
            //     x: 0
            //     y: 374
            //     SpinBox {
            //         x: 0
            //         y: 0
            //         width: 99
            //         height: 30
            //         value: motorDetails.blackEMF
            //         onValueChanged: motorDetails.setBlackEMF(value)
            //     }

            //     Text {
            //         x: 123
            //         y: 8
            //         text: qsTr("Black EMF")
            //         font.pixelSize: 12
            //     }
            // }

            // GroupItem {
            //     x: 3
            //     y: 436
            //     SpinBox {
            //         x: 0
            //         y: 0
            //         width: 99
            //         height: 30
            //         value: motorDetails.voltageRailSupply15
            //         onValueChanged: motorDetails.setVoltageRailSupply15(value)
            //     }

            //     Text {
            //         x: 123
            //         y: 8
            //         text: qsTr("15V Voltage Rail Supply")
            //         font.pixelSize: 12
            //     }
            // }
        }

        // GroupItem {
        //     x: 355
        //     y: 76
        //     GroupItem {
        //         x: 2
        //         y: 0
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.voltageRailSupply3
        //             onValueChanged: motorDetails.setVoltageRailSupply3(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("3.3V Voltage Rail Supply")
        //             font.pixelSize: 12
        //         }
        //     }

        //     GroupItem {
        //         x: 2
        //         y: 65
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.voltageRailSupply2
        //             onValueChanged: motorDetails.setVoltageRailSupply2(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("1.9V Voltage Rail Supply")
        //             font.pixelSize: 12
        //         }
        //     }

        //     GroupItem {
        //         x: 3
        //         y: 133
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.heatSinkTemp
        //             onValueChanged: motorDetails.setHeatSinkTemp(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("Heat-sink Temperature")
        //             font.pixelSize: 12
        //         }
        //     }

        //     GroupItem {
        //         x: 0
        //         y: 197
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.motorTemp
        //             onValueChanged: motorDetails.setMotorTemp(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("Motor Temperature")
        //             font.pixelSize: 12
        //         }
        //     }

        //     GroupItem {
        //         x: 0
        //         y: 261
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.dspBoardTemp
        //             onValueChanged: motorDetails.setDspBoardTemp(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("DSP Boaprd Tem")
        //             font.pixelSize: 12
        //         }
        //     }

        //     GroupItem {
        //         x: 0
        //         y: 318
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.dcBusAmpHours
        //             onValueChanged: motorDetails.setDcBusAmpHours(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("DC Bus AmpHours")
        //             font.pixelSize: 12
        //         }
        //     }

        //     GroupItem {
        //         x: 0
        //         y: 374
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.odometer
        //             onValueChanged: motorDetails.setOdometer(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("Odometer")
        //             font.pixelSize: 12
        //         }
        //     }

        //     GroupItem {
        //         x: 3
        //         y: 436
        //         SpinBox {
        //             x: 0
        //             y: 0
        //             width: 99
        //             height: 30
        //             value: motorDetails.slipSpeed
        //             onValueChanged: motorDetails.setSlipSpeed(value)
        //         }

        //         Text {
        //             x: 123
        //             y: 8
        //             text: qsTr("Slip Speed")
        //             font.pixelSize: 12
        //         }
        //     }
        // }
    }
    Text {
        id: text22
        x: 43
        y: 550
        width: 442
        height: 14
        text: "Byte Stream: " + motorDetails.byteStreamStr
        font.pixelSize: 16
    }

    Text {
        id: text23
        x: 43
        y: 580
        width: 442
        height: 14
        text: "Encoded Stream: " + motorDetails.encodedByteStreamStr
        font.pixelSize: 16
    }
}
