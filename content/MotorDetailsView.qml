import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0


Item {
    property var motorDetails
    width: 1500
    height: 620



    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 1500
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
            GroupItem {
                x: 2
                y: 225
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetails.currentMotorTorque
                    onValueChanged: motorDetails.setCurrentMotorTorque(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Current Motor Torque")
                    font.pixelSize: 12
                }
            }
            GroupItem {
                x: 2
                y: 265
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetails.currentRpmValue
                    onValueChanged: motorDetails.setCurrentRpmValue(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Current RPM Value")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 2
                y: 305
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetails.motorTemperature
                    onValueChanged: motorDetails.setMotorTemperature(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Motor Temperature")
                    font.pixelSize: 12
                }
            }
            GroupItem {
                x: 2
                y: 345
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetails.inverterPeakCurrent
                    onValueChanged: motorDetails.setInverterPeakCurrent(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Inverter Peak Current")
                    font.pixelSize: 12
                }
            }
            GroupItem {
                x: 2
                y: 385
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetails.currentMotorPower
                    onValueChanged: motorDetails.setCurrentMotorPower(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Current Motor Power")
                    font.pixelSize: 12
                }
            }
            GroupItem {
                x: 2
                y: 425
                SpinBox {
                    x: 0
                    y: 0
                    width: 99
                    height: 30
                    value: motorDetails.absoluteAngle
                    onValueChanged: motorDetails.setAbsoluteAngle(value)
                }

                Text {
                    x: 123
                    y: 8
                    text: qsTr("Absolute Angle")
                    font.pixelSize: 12
                }
            }
            Switch {
                id: switch6
                x: 145
                y: 65
                width: 135
                height: 37
                text: qsTr("Motor About to Stall")
                checked: motorDetails.motorAboutToStall
                onClicked: motorDetails.setMotorAboutToStall(checked)
            }
            Switch {
                id: switch7
                x: 145
                y: 105
                width: 135
                height: 37
                text: qsTr("Delay In reading Temp Sensor")
                checked: motorDetails.delayInReadingTempSensor
                onClicked: motorDetails.setDelayInReadingTempSensor(checked)
            }
            Switch {
                id: switch8
                x: 145
                y: 145
                width: 135
                height: 37
                text: qsTr("Delay in reading pos sensor")
                checked: motorDetails.delayInReadingPosSensor
                onClicked: motorDetails.setDelayInReadingPosSensor(checked)
            }
            Switch {
                id: switch9
                x: 145
                y: 185
                width: 135
                height: 37
                text: qsTr("Inverter 1 Temp High")
                checked: motorDetails.inverter1TempVeryHigh
                onClicked: motorDetails.setInverter1TempVeryHigh(checked)
            }
            Switch {
                id: switch10
                x: 275
                y: 65
                width: 135
                height: 37
                text: qsTr("Inverter 2 Temp High")
                checked: motorDetails.inverter2TempVeryHigh
                onClicked: motorDetails.setInverter2TempVeryHigh(checked)
            }
            Switch {
                id: switch11
                x: 275
                y: 105
                width: 135
                height: 37
                text: qsTr("Inverter 3 Temp High")
                checked: motorDetails.inverter3TempVeryHigh
                onClicked: motorDetails.setInverter3TempVeryHigh(checked)
            }
            Switch {
                id: switch12
                x: 275
                y: 145
                width: 135
                height: 37
                text: qsTr("Inverter 4 Temp High")
                checked: motorDetails.inverter4TempVeryHigh
                onClicked: motorDetails.setInverter4TempVeryHigh(checked)
            }
            Switch {
                id: switch13
                x: 275
                y: 185
                width: 135
                height: 37
                text: qsTr("Inverter 5 Temp High")
                checked: motorDetails.inverter5TempTooHigh
                onClicked: motorDetails.setInverter5TempVeryHigh(checked)
            }
            Switch {
                id: switch14
                x: 405
                y: 65
                width: 135
                height: 37
                text: qsTr("Inverter 6 Temp High")
                checked: motorDetails.inverter6TempTooHigh
                onClicked: motorDetails.setInverter6TempVeryHigh(checked)
            }
            Switch {
                id: switch15
                x: 405
                y: 105
                width: 135
                height: 37
                text: qsTr("CPU Temp High")
                checked: motorDetails.cpuTemperatureVeryHigh
                onClicked: motorDetails.setCpuTemperatureVeryHigh(checked)
            }
            Switch {
                id: switch16
                x: 405
                y: 145
                width: 135
                height: 37
                text: qsTr("Hall Temp High")
                checked: motorDetails.hallTemperatureVeryHigh
                onClicked: motorDetails.setHallTemperatureVeryHigh(checked)
            }
            Switch {
                id: switch17
                x: 405
                y: 185
                width: 135
                height: 37
                text: qsTr("Dc Link Temp High")
                checked: motorDetails.dclinkTemperatureVeryHigh
                onClicked: motorDetails.setDclinkTemperatureVeryHigh(checked)
            }
            Switch {
                id: switch18
                x: 545
                y: 65
                width: 135
                height: 37
                text: qsTr("Delay Dc Link Comm")
                checked: motorDetails.delayInDclinkCommunication
                onClicked: motorDetails.setDelayInDclinkCommunication(checked)
            }
            Switch {
                id: switch19
                x: 545
                y: 105
                width: 135
                height: 37
                text: qsTr("Inverter 1 Over Current")
                checked: motorDetails.inverter1OverCurrent
                onClicked: motorDetails.setInverter1OverCurrent(checked)
            }
            Switch {
                id: switch20
                x: 545
                y: 145
                width: 135
                height: 37
                text: qsTr("Inverter 2 Over Current")
                checked: motorDetails.inverter2OverCurrent
                onClicked: motorDetails.setInverter2OverCurrent(checked)
            }
            Switch {
                id: switch21
                x: 545
                y: 185
                width: 135
                height: 37
                text: qsTr("Inverter 3 Over Current")
                checked: motorDetails.inverter3OverCurrent
                onClicked: motorDetails.setInverter3OverCurrent(checked)
            }
            Switch {
                id: switch22
                x: 685
                y: 65
                width: 135
                height: 37
                text: qsTr("Inverter 4 Over Current")
                checked: motorDetails.inverter4OverCurrent
                onClicked: motorDetails.setInverter4OverCurrent(checked)
            }
            Switch {
                id: switch23
                x: 685
                y: 105
                width: 135
                height: 37
                text: qsTr("Inverter 5 Over Current")
                checked: motorDetails.inverter5OverCurrent
                onClicked: motorDetails.setInverter5OverCurrent(checked)
            }
            Switch {
                id: switch24
                x: 685
                y: 145
                width: 135
                height: 37
                text: qsTr("Inverter 6 Over Current")
                checked: motorDetails.inverter6OverCurrent
                onClicked: motorDetails.setInverter6OverCurrent(checked)
            }
            Switch {
                id: switch25
                x: 685
                y: 185
                width: 135
                height: 37
                text: qsTr("Dc Overvoltage")
                checked: motorDetails.dcOvervoltageWarning
                onClicked: motorDetails.setDcOvervoltageWarning(checked)
            }
            Switch {
                id: switch26
                x: 815
                y: 65
                width: 135
                height: 37
                text: qsTr("Dc Undervoltage")
                checked: motorDetails.dcUndervoltageWarning
                onClicked: motorDetails.setDcUndervoltageWarning(checked)
            }
            Switch {
                id: switch27
                x: 815
                y: 105
                width: 135
                height: 37
                text: qsTr("CAN Comms TImeout")
                checked: motorDetails.canCommsTimeout
                onClicked: motorDetails.setCanCommsTimeout(checked)
            }
            Switch {
                id: switch28
                x: 815
                y: 145
                width: 135
                height: 37
                text: qsTr("Inverter 1 Fault")
                checked: motorDetails.inverter1FaultWarning
                onClicked: motorDetails.setInverter1FaultWarning(checked)
            }
            Switch {
                id: switch29
                x: 815
                y: 145
                width: 135
                height: 37
                text: qsTr("Inverter 2 Fault")
                checked: motorDetails.inverter2FaultWarning
                onClicked: motorDetails.setInverter2FaultWarning(checked)
            }
            Switch {
                id: switch30
                x: 815
                y: 185
                width: 135
                height: 37
                text: qsTr("Inverter 3 Fault")
                checked: motorDetails.inverter3FaultWarning
                onClicked: motorDetails.setInverter3FaultWarning(checked)
            }
            Switch {
                id: switch31
                x: 275
                y: 225
                width: 135
                height: 37
                text: qsTr("Inverter 4 Fault")
                checked: motorDetails.inverter4FaultWarning
                onClicked: motorDetails.setInverter4FaultWarning(checked)
            }
            Switch {
                id: switch32
                x: 275
                y: 265
                width: 135
                height: 37
                text: qsTr("Inverter 5 Fault")
                checked: motorDetails.inverter5FaultWarning
                onClicked: motorDetails.setInverter5FaultWarning(checked)
            }
            Switch {
                id: switch33
                x: 275
                y: 305
                width: 135
                height: 37
                text: qsTr("Inverter 6 Fault")
                checked: motorDetails.inverter6FaultWarning
                onClicked: motorDetails.setInverter6FaultWarning(checked)
            }
            Switch {
                id: switch34
                x: 275
                y: 345
                width: 135
                height: 37
                text: qsTr("CAN Send Warn")
                checked: motorDetails.canSendWarning
                onClicked: motorDetails.setCanSendWarning(checked)
            }
            Switch {
                id: switch35
                x: 275
                y: 385
                width: 135
                height: 37
                text: qsTr("Lost Frame on CAN Bus")
                checked: motorDetails.lostFramesOnCanBusWarning
                onClicked: motorDetails.setLostFramesOnCanBusWarning(checked)
            }
            Switch {
                id: switch36
                x: 275
                y: 425
                width: 135
                height: 37
                text: qsTr("Over Speed Warn")
                checked: motorDetails.overspeedWarning
                onClicked: motorDetails.setOverspeedWarning(checked)
            }
            Switch {
                id: switch37
                x: 405
                y: 225
                width: 135
                height: 37
                text: qsTr("CPU Overload")
                checked: motorDetails.cpuOverload
                onClicked: motorDetails.setCpuOverload(checked)
            }
            Switch {
                id: switch38
                x: 405
                y: 265
                width: 135
                height: 37
                text: qsTr("Torque Limited")
                checked: motorDetails.torqueLimited
                onClicked: motorDetails.setTorqueLimited(checked)
            }
            Switch {
                id: switch39
                x: 405
                y: 305
                width: 135
                height: 37
                text: qsTr("Start High RPM")
                checked: motorDetails.startAtHighRpm
                onClicked: motorDetails.setStartAtHighRpm(checked)
            }
            Switch {
                id: switch40
                x: 405
                y: 345
                width: 135
                height: 37
                text: qsTr("Init Error")
                checked: motorDetails.initError
                onClicked: motorDetails.setInitError(checked)
            }
            Switch {
                id: switch41
                x: 405
                y: 385
                width: 135
                height: 37
                text: qsTr("Setting not found")
                checked: motorDetails.settingsNotFound
                onClicked: motorDetails.setSettingsNotFound(checked)
            }
            Switch {
                id: switch42
                x: 405
                y: 425
                width: 135
                height: 37
                text: qsTr("Motor Stalled")
                checked: motorDetails.motorStalled
                onClicked: motorDetails.setMotorStalled(checked)
            }
            Switch {
                id: switch43
                x: 545
                y: 225
                width: 135
                height: 37
                text: qsTr("Controller Data Reading Timeout")
                checked: motorDetails.controllerDataReadingTimeout
                onClicked: motorDetails.setControllerDataReadingTimeout(checked)
            }
            Switch {
                id: switch44
                x: 545
                y: 265
                width: 135
                height: 37
                text: qsTr("Invalid Hall Sensor Sequence")
                checked: motorDetails.invalidHallSensorSequence
                onClicked: motorDetails.setInvalidHallSensorSequence(checked)
            }
            Switch {
                id: switch45
                x: 545
                y: 305
                width: 135
                height: 37
                text: qsTr("Invalid Hall Sector")
                checked: motorDetails.invalidHallSector
                onClicked: motorDetails.setInvalidHallSector(checked)
            }
            Switch {
                id: switch46
                x: 545
                y: 345
                width: 135
                height: 37
                text: qsTr("Error Reading Temp Sensor")
                checked: motorDetails.errorReadingTempSensor
                onClicked: motorDetails.setErrorReadingTempSensor(checked)
            }
            Switch {
                id: switch47
                x: 545
                y: 385
                width: 135
                height: 37
                text: qsTr("Position Reading Sensor Error")
                checked: motorDetails.positionSensorReadingError
                onClicked: motorDetails.setPositionSensorReadingError(checked)
            }
            Switch {
                id: switch48
                x: 545
                y: 425
                width: 135
                height: 37
                text: qsTr("Error Reading Encoder")
                checked: motorDetails.errorReadingEncoder
                onClicked: motorDetails.setErrorReadingEncoder(checked)
            }
            Switch {
                id: switch49
                x: 685
                y: 225
                width: 135
                height: 37
                text: qsTr("Zero Position Offset not Set")
                checked: motorDetails.zeroPositionOffsetNotSet
                onClicked: motorDetails.setZeroPositionOffsetNotSet(checked)
            }
            Switch {
                id: switch50
                x: 685
                y: 265
                width: 135
                height: 37
                text: qsTr("Hw Enable Not Set")
                checked: motorDetails.hwEnableNotSet
                onClicked: motorDetails.setHwEnableNotSet(checked)
            }

            Switch {
                id: switch51
                x: 685
                y: 305
                width: 135
                height: 37
                text: qsTr("Inverter 1 Temp Too High")
                checked: motorDetails.inverter1TempTooHigh
                onClicked: motorDetails.setInverter1TempTooHigh(checked)
            }

            Switch {
                id: switch52
                x: 685
                y: 345
                width: 135
                height: 37
                text: qsTr("Inverter 2 Temp Too High")
                checked: motorDetails.inverter2TempTooHigh
                onClicked: motorDetails.setInverter2TempTooHigh(checked)
            }

            Switch {
                id: switch53
                x: 685
                y: 385
                width: 135
                height: 37
                text: qsTr("Inverter 3 Temp Too High")
                checked: motorDetails.inverter3TempTooHigh
                onClicked: motorDetails.setInverter3TempTooHigh(checked)
            }

            Switch {
                id: switch54
                x: 685
                y: 425
                width: 135
                height: 37
                text: qsTr("Inverter 4 Temp Too High")
                checked: motorDetails.inverter4TempTooHigh
                onClicked: motorDetails.setInverter4TempTooHigh(checked)
            }

            // Reset y and increment x to 825
            Switch {
                id: switch55
                x: 825
                y: 225
                width: 135
                height: 37
                text: qsTr("Inverter 5 Temp Too High")
                checked: motorDetails.inverter5TempTooHigh
                onClicked: motorDetails.setInverter5TempTooHigh(checked)
            }

            Switch {
                id: switch56
                x: 825
                y: 265
                width: 135
                height: 37
                text: qsTr("Inverter 6 Temp Too High")
                checked: motorDetails.inverter6TempTooHigh
                onClicked: motorDetails.setInverter6TempTooHigh(checked)
            }

            Switch {
                id: switch57
                x: 825
                y: 305
                width: 135
                height: 37
                text: qsTr("CPU Temperature Too High")
                checked: motorDetails.cpuTemperatureTooHigh
                onClicked: motorDetails.setCpuTemperatureTooHigh(checked)
            }

            Switch {
                id: switch58
                x: 825
                y: 345
                width: 135
                height: 37
                text: qsTr("Hall Temperature Too High")
                checked: motorDetails.hallTemperatureTooHigh
                onClicked: motorDetails.setHallTemperatureTooHigh(checked)
            }

            Switch {
                id: switch59
                x: 825
                y: 385
                width: 135
                height: 37
                text: qsTr("DC Link Temperature Too High")
                checked: motorDetails.dclinkTemperatureTooHigh
                onClicked: motorDetails.setDclinkTemperatureTooHigh(checked)
            }

            Switch {
                id: switch60
                x: 825
                y: 425
                width: 135
                height: 37
                text: qsTr("Error in DC Link Communication")
                checked: motorDetails.errorInDclinkCommunication
                onClicked: motorDetails.setErrorInDclinkCommunication(checked)
            }

            // Reset y and increment x to 965
            Switch {
                id: switch61
                x: 965
                y: 225
                width: 135
                height: 37
                text: qsTr("Inverter 1 Overcurrent")
                checked: motorDetails.inverter1OverCurrent
                onClicked: motorDetails.setInverter1Overcurrent(checked)
            }

            Switch {
                id: switch62
                x: 965
                y: 265
                width: 135
                height: 37
                text: qsTr("Inverter 2 Overcurrent")
                checked: motorDetails.inverter2OverCurrent
                onClicked: motorDetails.setInverter2Overcurrent(checked)
            }

            Switch {
                id: switch63
                x: 965
                y: 305
                width: 135
                height: 37
                text: qsTr("Inverter 3 Overcurrent")
                checked: motorDetails.inverter3OverCurrent
                onClicked: motorDetails.setInverter3Overcurrent(checked)
            }

            Switch {
                id: switch64
                x: 965
                y: 345
                width: 135
                height: 37
                text: qsTr("Inverter 4 Overcurrent")
                checked: motorDetails.inverter4OverCurrent
                onClicked: motorDetails.setInverter4Overcurrent(checked)
            }

            Switch {
                id: switch65
                x: 965
                y: 385
                width: 135
                height: 37
                text: qsTr("Inverter 5 Overcurrent")
                checked: motorDetails.inverter5OverCurrent
                onClicked: motorDetails.setInverter5Overcurrent(checked)
            }

            Switch {
                id: switch66
                x: 965
                y: 425
                width: 135
                height: 37
                text: qsTr("Inverter 6 Overcurrent")
                checked: motorDetails.inverter6OverCurrent
                onClicked: motorDetails.setInverter6Overcurrent(checked)
            }

            // Reset y and increment x to 1105
            Switch {
                id: switch67
                x: 1105
                y: 225
                width: 135
                height: 37
                text: qsTr("DC Overvoltage Error")
                checked: motorDetails.dcOvervoltageError
                onClicked: motorDetails.setDcOvervoltageError(checked)
            }

            Switch {
                id: switch68
                x: 1105
                y: 265
                width: 135
                height: 37
                text: qsTr("DC Undervoltage Error")
                checked: motorDetails.dcUndervoltageError
                onClicked: motorDetails.setDcUndervoltageError(checked)
            }

            Switch {
                id: switch69
                x: 1105
                y: 305
                width: 135
                height: 37
                text: qsTr("Double CAN Comms Timeout")
                checked: motorDetails.doubleCanCommsTimeout
                onClicked: motorDetails.setDoubleCanCommsTimeout(checked)
            }

            Switch {
                id: switch70
                x: 1105
                y: 345
                width: 135
                height: 37
                text: qsTr("CAN Comms Timeout Error")
                checked: motorDetails.canCommsTimeoutError
                onClicked: motorDetails.setCanCommsTimeoutError(checked)
            }
            Switch {
                id: switch71
                x: 955
                y: 65
                width: 135
                height: 37
                text: qsTr("Inverter 1 Fault Error")
                checked: motorDetails.inverter1FaultError
                onClicked: motorDetails.setInverter1FaultError(checked)
            }

            Switch {
                id: switch72
                x: 955
                y: 105
                width: 135
                height: 37
                text: qsTr("Inverter 2 Fault Error")
                checked: motorDetails.inverter2FaultError
                onClicked: motorDetails.setInverter2FaultError(checked)
            }

            Switch {
                id: switch73
                x: 955
                y: 145
                width: 135
                height: 37
                text: qsTr("Inverter 3 Fault Error")
                checked: motorDetails.inverter3FaultError
                onClicked: motorDetails.setInverter3FaultError(checked)
            }

            Switch {
                id: switch74
                x: 955
                y: 185
                width: 135
                height: 37
                text: qsTr("Inverter 4 Fault Error")
                checked: motorDetails.inverter4FaultError
                onClicked: motorDetails.setInverter4FaultError(checked)
            }

            Switch {
                id: switch75
                x: 1090
                y: 65
                width: 135
                height: 37
                text: qsTr("Inverter 5 Fault Error")
                checked: motorDetails.inverter5FaultError
                onClicked: motorDetails.setInverter5FaultError(checked)
            }

            Switch {
                id: switch76
                x: 1090
                y: 105
                width: 135
                height: 37
                text: qsTr("Inverter 6 Fault Error")
                checked: motorDetails.inverter6FaultError
                onClicked: motorDetails.setInverter6FaultError(checked)
            }

            Switch {
                id: switch77
                x: 1090
                y: 145
                width: 135
                height: 37
                text: qsTr("CAN Send Error")
                checked: motorDetails.canSendError
                onClicked: motorDetails.setCanSendError(checked)
            }

            Switch {
                id: switch78
                x: 1090
                y: 185
                width: 135
                height: 37
                text: qsTr("Lost Frames on CAN Bus Error")
                checked: motorDetails.lostFramesOnCanBusError
                onClicked: motorDetails.setLostFramesOnCanBusError(checked)
            }

            Switch {
                id: switch79
                x: 1225
                y: 65
                width: 135
                height: 37
                text: qsTr("Overspeed Error")
                checked: motorDetails.overspeedError
                onClicked: motorDetails.setOverspeedError(checked)
            }

            Switch {
                id: switch80
                x: 1225
                y: 105
                width: 135
                height: 37
                text: qsTr("CPU Overloaded")
                checked: motorDetails.cpuOverloaded
                onClicked: motorDetails.setCpuOverloaded(checked)
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
