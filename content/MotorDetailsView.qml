import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0


Item {
    property var motorDetails : motorDetails0
    width: 550
    height: 620
    x: 0
    y: 0
    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Proximity Sensors Packet"
            font.family: "Verdana"
            font.bold: true
        }

        ComboBox {
            id: motorSelector
            width: 150
            model: ["Motor 0", "Motor 1"]
            onCurrentIndexChanged: {
                motorDetails = currentIndex === 0 ? motorDetails0 : motorDetails1
            }
        }

        Column {
            spacing: 20
            
            IntSpinBox {
                id: spinBox
                text: qsTr("Control Value")
                value: motorDetails.controlValue
                onValueChanged: motorDetails.setControlValue(value)
            }

            FlagBox {
                title: "Control Flags"
                flags: [
                    {
                        text: qsTr("Control Mode"),
                        checked: motorDetails.controlMode,
                        onClicked: function(checked) { motorDetails.setControlMode(checked) }
                    },
                    {
                        text: qsTr("Motor Mode"),
                        checked: motorDetails.motorMode,
                        onClicked: function(checked) { motorDetails.setMotorMode(checked) }
                    },
                    {
                        text: qsTr("Software Enable"),
                        checked: motorDetails.softwareEnable,
                        onClicked: function(checked) { motorDetails.setSoftwareEnable(checked) }
                    },
                    {
                        text: qsTr("Debug Mode"),
                        checked: motorDetails.debugMode,
                        onClicked: function(checked) { motorDetails.setDebugMode(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20

                    IntSpinBox {
                        text: qsTr("Current Motor Torque")
                        value: motorDetails.currentMotorTorque
                        onValueChanged: motorDetails.setCurrentMotorTorque(value)
                    }

                    IntSpinBox {
                        text: qsTr("Current RPM")
                        value: motorDetails.currentRpmValue
                        onValueChanged: motorDetails.setCurrentRpmValue(value)
                    }

                    IntSpinBox {
                        text: qsTr("Motor Temperature")
                        value: motorDetails.motorTemperature
                        onValueChanged: motorDetails.setMotorTemperature(value)
                    }
                }

                Column {
                    spacing: 20

                    IntSpinBox {
                        text: qsTr("Inverter Peak Current")
                        value: motorDetails.inverterPeakCurrent
                        onValueChanged: motorDetails.setInverterPeakCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("Current Motor Power")
                        value: motorDetails.currentMotorPower
                        onValueChanged: motorDetails.setCurrentMotorPower(value)
                    }

                    IntSpinBox {
                        text: qsTr("Absolute Angle")
                        value: motorDetails.absoluteAngle
                        onValueChanged: motorDetails.setAbsoluteAngle(value)
                    }
                }
            }
           
            FlagBox {
                title: "Warning Flags"
                flags: [
                    {
                        text: qsTr("Motor About To Stall"),
                        checked: motorDetails.motorAboutToStall,
                        onClicked: function(checked) { motorDetails.setMotorAboutToStall(checked) }
                    },
                    {
                        text: qsTr("Delay In Reading Temp Sensor"),
                        checked: motorDetails.delayInReadingTempSensor,
                        onClicked: function(checked) { motorDetails.setDelayInReadingTempSensor(checked) }
                    },
                    {
                        text: qsTr("Delay In Reading Pos Sensor"),
                        checked: motorDetails.delayInReadingPosSensor,
                        onClicked: function(checked) { motorDetails.setDelayInReadingPosSensor(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Temp Very High"),
                        checked: motorDetails.inverter1TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter1TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Temp Very High"),
                        checked: motorDetails.inverter2TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter2TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Temp Very High"),
                        checked: motorDetails.inverter3TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter3TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Temp Very High"),
                        checked: motorDetails.inverter4TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter4TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Temp Very High"),
                        checked: motorDetails.inverter5TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter5TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Temp Very High"),
                        checked: motorDetails.inverter6TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter6TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("CPU Temperature Very High"),
                        checked: motorDetails.cpuTemperatureVeryHigh,
                        onClicked: function(checked) { motorDetails.setCpuTemperatureVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Hall Temperature Very High"),
                        checked: motorDetails.hallTemperatureVeryHigh,
                        onClicked: function(checked) { motorDetails.setHallTemperatureVeryHigh(checked) }
                    },
                    {
                        text: qsTr("DC Link Temperature Very High"),
                        checked: motorDetails.dclinkTemperatureVeryHigh,
                        onClicked: function(checked) { motorDetails.setDclinkTemperatureVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Delay In DC Link Communication"),
                        checked: motorDetails.delayInDclinkCommunication,
                        onClicked: function(checked) { motorDetails.setDelayInDclinkCommunication(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Over Current Warning"),
                        checked: motorDetails.inverter1OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter1OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Over Current Warning"),
                        checked: motorDetails.inverter2OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter2OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Over Current Warning"),
                        checked: motorDetails.inverter3OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter3OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Over Current Warning"),
                        checked: motorDetails.inverter4OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter4OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Over Current Warning"),
                        checked: motorDetails.inverter5OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter5OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Over Current Warning"),
                        checked: motorDetails.inverter6OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter6OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("DC Overvoltage Warning"),
                        checked: motorDetails.dcOvervoltageWarning,
                        onClicked: function(checked) { motorDetails.setDcOvervoltageWarning(checked) }
                    },
                    {
                        text: qsTr("DC Undervoltage Warning"),
                        checked: motorDetails.dcUndervoltageWarning,
                        onClicked: function(checked) { motorDetails.setDcUndervoltageWarning(checked) }
                    },
                    {
                        text: qsTr("CAN Comms Timeout"),
                        checked: motorDetails.canCommsTimeout,
                        onClicked: function(checked) { motorDetails.setCanCommsTimeout(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Fault Warning"),
                        checked: motorDetails.inverter1faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter1faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Fault Warning"),
                        checked: motorDetails.inverter2faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter2faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Fault Warning"),
                        checked: motorDetails.inverter3faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter3faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Fault Warning"),
                        checked: motorDetails.inverter4faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter4faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Fault Warning"),
                        checked: motorDetails.inverter5faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter5faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Fault Warning"),
                        checked: motorDetails.inverter6faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter6faultWarning(checked) }
                    },
                    {
                        text: qsTr("CAN Send Warning"),
                        checked: motorDetails.canSendWarning,
                        onClicked: function(checked) { motorDetails.setCanSendWarning(checked) }
                    },
                    {
                        text: qsTr("Lost Frames On CAN Bus Warning"),
                        checked: motorDetails.lostFramesOnCanBusWarning,
                        onClicked: function(checked) { motorDetails.setLostFramesOnCanBusWarning(checked) }
                    },
                    {
                        text: qsTr("Overspeed Warning"),
                        checked: motorDetails.overspeedWarning,
                        onClicked: function(checked) { motorDetails.setOverspeedWarning(checked) }
                    },
                    {
                        text: qsTr("CPU Overload"),
                        checked: motorDetails.cpuOverload,
                        onClicked: function(checked) { motorDetails.setCpuOverload(checked) }
                    },
                    {
                        text: qsTr("Torque Limited"),
                        checked: motorDetails.torqueLimited,
                        onClicked: function(checked) { motorDetails.setTorqueLimited(checked) }
                    },
                    {
                        text: qsTr("Start At High RPM"),
                        checked: motorDetails.startAtHighRpm,
                        onClicked: function(checked) { motorDetails.setStartAtHighRpm(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Error Flags"
                flags: [
                    {
                        text: qsTr("Init Error"),
                        checked: motorDetails.initError,
                        onClicked: function(checked) { motorDetails.setInitError(checked) }
                    },
                    {
                        text: qsTr("Settings Not Found"),
                        checked: motorDetails.settingsNotFound,
                        onClicked: function(checked) { motorDetails.setSettingsNotFound(checked) }
                    },
                    {
                        text: qsTr("Motor Stalled"),
                        checked: motorDetails.motorStalled,
                        onClicked: function(checked) { motorDetails.setMotorStalled(checked) }
                    },
                    {
                        text: qsTr("Controller Data Reading Timeout"),
                        checked: motorDetails.controllerDataReadingTimeout,
                        onClicked: function(checked) { motorDetails.setControllerDataReadingTimeout(checked) }
                    },
                    {
                        text: qsTr("Invalid Hall Sensor Sequence"),
                        checked: motorDetails.invalidHallSensorSequence,
                        onClicked: function(checked) { motorDetails.setInvalidHallSensorSequence(checked) }
                    },
                    {
                        text: qsTr("Invalid Hall Sector"),
                        checked: motorDetails.invalidHallSector,
                        onClicked: function(checked) { motorDetails.setInvalidHallSector(checked) }
                    },
                    {
                        text: qsTr("Error Reading Temp Sensor"),
                        checked: motorDetails.errorReadingTempSensor,
                        onClicked: function(checked) { motorDetails.setErrorReadingTempSensor(checked) }
                    },
                    {
                        text: qsTr("Position Sensor Reading Error"),
                        checked: motorDetails.positionSensorReadingError,
                        onClicked: function(checked) { motorDetails.setPositionSensorReadingError(checked) }
                    },
                    {
                        text: qsTr("Error Reading Encoder"),
                        checked: motorDetails.errorReadingEncoder,
                        onClicked: function(checked) { motorDetails.setErrorReadingEncoder(checked) }
                    },
                    {
                        text: qsTr("Zero Position Offset Not Set"),
                        checked: motorDetails.zeroPositionOffsetNotSet,
                        onClicked: function(checked) { motorDetails.setZeroPositionOffsetNotSet(checked) }
                    },
                    {
                        text: qsTr("HW Enable Not Set"),
                        checked: motorDetails.hwEnableNotSet,
                        onClicked: function(checked) { motorDetails.setHwEnableNotSet(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Temp Too High"),
                        checked: motorDetails.inverter1TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter1TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Temp Too High"),
                        checked: motorDetails.inverter2TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter2TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Temp Too High"),
                        checked: motorDetails.inverter3TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter3TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Temp Too High"),
                        checked: motorDetails.inverter4TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter4TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Temp Too High"),
                        checked: motorDetails.inverter5TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter5TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Temp Too High"),
                        checked: motorDetails.inverter6TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter6TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("CPU Temperature Too High"),
                        checked: motorDetails.cpuTemperatureTooHigh,
                        onClicked: function(checked) { motorDetails.setCpuTemperatureTooHigh(checked) }
                    },
                    {
                        text: qsTr("Hall Temperature Too High"),
                        checked: motorDetails.hallTemperatureTooHigh,
                        onClicked: function(checked) { motorDetails.setHallTemperatureTooHigh(checked) }
                    },
                    {
                        text: qsTr("DC Link Temperature Too High"),
                        checked: motorDetails.dclinkTemperatureTooHigh,
                        onClicked: function(checked) { motorDetails.setDclinkTemperatureTooHigh(checked) }
                    },
                    {
                        text: qsTr("Error In DC Link Communication"),
                        checked: motorDetails.errorInDclinkCommunication,
                        onClicked: function(checked) { motorDetails.setErrorInDclinkCommunication(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Overcurrent Error"),
                        checked: motorDetails.inverter1OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter1OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Overcurrent Error"),
                        checked: motorDetails.inverter2OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter2OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Overcurrent Error"),
                        checked: motorDetails.inverter3OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter3OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Overcurrent Error"),
                        checked: motorDetails.inverter4OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter4OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Overcurrent Error"),
                        checked: motorDetails.inverter5OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter5OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Overcurrent Error"),
                        checked: motorDetails.inverter6OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter6OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("DC Overvoltage Error"),
                        checked: motorDetails.dcOvervoltageError,
                        onClicked: function(checked) { motorDetails.setDcOvervoltageError(checked) }
                    },
                    {
                        text: qsTr("DC Undervoltage Error"),
                        checked: motorDetails.dcUndervoltageError,
                        onClicked: function(checked) { motorDetails.setDcUndervoltageError(checked) }
                    },
                    {
                        text: qsTr("Double CAN ID On Bus"),
                        checked: motorDetails.doubleCanIdOnBus,
                        onClicked: function(checked) { motorDetails.setDoubleCanIdOnBus(checked) }
                    },
                    {
                        text: qsTr("CAN Comms Timeout Error"),
                        checked: motorDetails.canCommsTimeoutError,
                        onClicked: function(checked) { motorDetails.setCanCommsTimeoutError(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Fault Error"),
                        checked: motorDetails.inverter1FaultError,
                        onClicked: function(checked) { motorDetails.setInverter1FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Fault Error"),
                        checked: motorDetails.inverter2FaultError,
                        onClicked: function(checked) { motorDetails.setInverter2FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Fault Error"),
                        checked: motorDetails.inverter3FaultError,
                        onClicked: function(checked) { motorDetails.setInverter3FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Fault Error"),
                        checked: motorDetails.inverter4FaultError,
                        onClicked: function(checked) { motorDetails.setInverter4FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Fault Error"),
                        checked: motorDetails.inverter5FaultError,
                        onClicked: function(checked) { motorDetails.setInverter5FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Fault Error"),
                        checked: motorDetails.inverter6FaultError,
                        onClicked: function(checked) { motorDetails.setInverter6FaultError(checked) }
                    },
                    {
                        text: qsTr("CAN Send Error"),
                        checked: motorDetails.canSendError,
                        onClicked: function(checked) { motorDetails.setCanSendError(checked) }
                    },
                    {
                        text: qsTr("Lost Frames On CAN Bus Error"),
                        checked: motorDetails.lostFramesOnCanBusError,
                        onClicked: function(checked) { motorDetails.setLostFramesOnCanBusError(checked) }
                    },
                    {
                        text: qsTr("Overspeed Error"),
                        checked: motorDetails.overspeedError,
                        onClicked: function(checked) { motorDetails.setOverspeedError(checked) }
                    },
                    {
                        text: qsTr("CPU Overloaded"),
                        checked: motorDetails.cpuOverloaded,
                        onClicked: function(checked) { motorDetails.setCpuOverloaded(checked) }
                    }
                ]
            }

        }

        BytePreview {
            id: bytePreview
            raw: motorDetails.byteStreamStr
            encoded: motorDetails.encodedByteStreamStr
        }
    }
}
