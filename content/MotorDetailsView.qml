import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0


Item {
    property var motorDetails : motorDetails0
    width: 550
    height: 875
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
                range: { "from": -32768, "to": 32767 }
                text: qsTr("Control Value")
                value: motorDetails.ControlValue
                onValueChanged: motorDetails.setControlValue(value)
            }

            FlagBox {
                title: "Control Flags"
                flags: [
                    {
                        text: qsTr("Control Mode"),
                        checked: motorDetails.ControlMode,
                        onClicked: function(checked) { motorDetails.setControlMode(checked) }
                    },
                    {
                        text: qsTr("Motor Mode"),
                        checked: motorDetails.MotorMode,
                        onClicked: function(checked) { motorDetails.setMotorMode(checked) }
                    },
                    {
                        text: qsTr("Software Enable"),
                        checked: motorDetails.SoftwareEnable,
                        onClicked: function(checked) { motorDetails.setSoftwareEnable(checked) }
                    },
                    {
                        text: qsTr("Debug Mode"),
                        checked: motorDetails.DebugMode,
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
                        range: { "from": -32768, "to": 32767 }
                        value: motorDetails.CurrentMotorTorque
                        onValueChanged: motorDetails.setCurrentMotorTorque(value)
                    }

                    IntSpinBox {
                        text: qsTr("Current RPM")
                        range: { "from": -32768, "to": 32767 }
                        value: motorDetails.CurrentRpmValue
                        onValueChanged: motorDetails.setCurrentRpmValue(value)
                    }

                    IntSpinBox {
                        text: qsTr("Motor Temperature")
                        range: { "from": -128, "to": 127 }
                        value: motorDetails.MotorTemperature
                        onValueChanged: motorDetails.setMotorTemperature(value)
                    }
                }

                Column {
                    spacing: 20

                    IntSpinBox {
                        text: qsTr("Inverter Peak Current")
                        range: { "from": -32768, "to": 32767 }
                        value: motorDetails.InverterPeakCurrent
                        onValueChanged: motorDetails.setInverterPeakCurrent(value)
                    }

                    IntSpinBox {
                        text: qsTr("Current Motor Power")
                        range: { "from": -32768, "to": 32767 }
                        value: motorDetails.CurrentMotorPower
                        onValueChanged: motorDetails.setCurrentMotorPower(value)
                    }

                    IntSpinBox {
                        text: qsTr("Absolute Angle")
                        value: motorDetails.AbsoluteAngle
                        onValueChanged: motorDetails.setAbsoluteAngle(value)
                    }
                }
            }
           
            FlagBox {
                title: "Warning Flags"
                flags: [
                    {
                        text: qsTr("Motor About To Stall"),
                        checked: motorDetails.MotorAboutToStall,
                        onClicked: function(checked) { motorDetails.setMotorAboutToStall(checked) }
                    },
                    {
                        text: qsTr("Delay In Reading Temp Sensor"),
                        checked: motorDetails.DelayInReadingTempSensor,
                        onClicked: function(checked) { motorDetails.setDelayInReadingTempSensor(checked) }
                    },
                    {
                        text: qsTr("Delay In Reading Pos Sensor"),
                        checked: motorDetails.DelayInReadingPosSensor,
                        onClicked: function(checked) { motorDetails.setDelayInReadingPosSensor(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Temp Very High"),
                        checked: motorDetails.Inverter1TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter1TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Temp Very High"),
                        checked: motorDetails.Inverter2TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter2TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Temp Very High"),
                        checked: motorDetails.Inverter3TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter3TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Temp Very High"),
                        checked: motorDetails.Inverter4TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter4TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Temp Very High"),
                        checked: motorDetails.Inverter5TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter5TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Temp Very High"),
                        checked: motorDetails.Inverter6TempVeryHigh,
                        onClicked: function(checked) { motorDetails.setInverter6TempVeryHigh(checked) }
                    },
                    {
                        text: qsTr("CPU Temperature Very High"),
                        checked: motorDetails.CpuTemperatureVeryHigh,
                        onClicked: function(checked) { motorDetails.setCpuTemperatureVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Hall Temperature Very High"),
                        checked: motorDetails.HallTemperatureVeryHigh,
                        onClicked: function(checked) { motorDetails.setHallTemperatureVeryHigh(checked) }
                    },
                    {
                        text: qsTr("DC Link Temperature Very High"),
                        checked: motorDetails.DclinkTemperatureVeryHigh,
                        onClicked: function(checked) { motorDetails.setDclinkTemperatureVeryHigh(checked) }
                    },
                    {
                        text: qsTr("Delay In DC Link Communication"),
                        checked: motorDetails.DelayInDclinkCommunication,
                        onClicked: function(checked) { motorDetails.setDelayInDclinkCommunication(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Over Current Warning"),
                        checked: motorDetails.Inverter1OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter1OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Over Current Warning"),
                        checked: motorDetails.Inverter2OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter2OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Over Current Warning"),
                        checked: motorDetails.Inverter3OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter3OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Over Current Warning"),
                        checked: motorDetails.Inverter4OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter4OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Over Current Warning"),
                        checked: motorDetails.Inverter5OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter5OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Over Current Warning"),
                        checked: motorDetails.Inverter6OverCurrentWarning,
                        onClicked: function(checked) { motorDetails.setInverter6OverCurrentWarning(checked) }
                    },
                    {
                        text: qsTr("DC Overvoltage Warning"),
                        checked: motorDetails.DcOvervoltageWarning,
                        onClicked: function(checked) { motorDetails.setDcOvervoltageWarning(checked) }
                    },
                    {
                        text: qsTr("DC Undervoltage Warning"),
                        checked: motorDetails.DcUndervoltageWarning,
                        onClicked: function(checked) { motorDetails.setDcUndervoltageWarning(checked) }
                    },
                    {
                        text: qsTr("CAN Comms Timeout"),
                        checked: motorDetails.CanCommsTimeout,
                        onClicked: function(checked) { motorDetails.setCanCommsTimeout(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Fault Warning"),
                        checked: motorDetails.Inverter1faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter1faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Fault Warning"),
                        checked: motorDetails.Inverter2faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter2faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Fault Warning"),
                        checked: motorDetails.Inverter3faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter3faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Fault Warning"),
                        checked: motorDetails.Inverter4faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter4faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Fault Warning"),
                        checked: motorDetails.Inverter5faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter5faultWarning(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Fault Warning"),
                        checked: motorDetails.Inverter6faultWarning,
                        onClicked: function(checked) { motorDetails.setInverter6faultWarning(checked) }
                    },
                    {
                        text: qsTr("CAN Send Warning"),
                        checked: motorDetails.CanSendWarning,
                        onClicked: function(checked) { motorDetails.setCanSendWarning(checked) }
                    },
                    {
                        text: qsTr("Lost Frames On CAN Bus Warning"),
                        checked: motorDetails.LostFramesOnCanBusWarning,
                        onClicked: function(checked) { motorDetails.setLostFramesOnCanBusWarning(checked) }
                    },
                    {
                        text: qsTr("Overspeed Warning"),
                        checked: motorDetails.OverspeedWarning,
                        onClicked: function(checked) { motorDetails.setOverspeedWarning(checked) }
                    },
                    {
                        text: qsTr("CPU Overload"),
                        checked: motorDetails.CpuOverload,
                        onClicked: function(checked) { motorDetails.setCpuOverload(checked) }
                    },
                    {
                        text: qsTr("Torque Limited"),
                        checked: motorDetails.TorqueLimited,
                        onClicked: function(checked) { motorDetails.setTorqueLimited(checked) }
                    },
                    {
                        text: qsTr("Start At High RPM"),
                        checked: motorDetails.StartAtHighRpm,
                        onClicked: function(checked) { motorDetails.setStartAtHighRpm(checked) }
                    }
                ]
            }

            FlagBox {
                title: "Error Flags"
                flags: [
                    {
                        text: qsTr("Init Error"),
                        checked: motorDetails.InitError,
                        onClicked: function(checked) { motorDetails.setInitError(checked) }
                    },
                    {
                        text: qsTr("Settings Not Found"),
                        checked: motorDetails.SettingsNotFound,
                        onClicked: function(checked) { motorDetails.setSettingsNotFound(checked) }
                    },
                    {
                        text: qsTr("Motor Stalled"),
                        checked: motorDetails.MotorStalled,
                        onClicked: function(checked) { motorDetails.setMotorStalled(checked) }
                    },
                    {
                        text: qsTr("Controller Data Reading Timeout"),
                        checked: motorDetails.ControllerDataReadingTimeout,
                        onClicked: function(checked) { motorDetails.setControllerDataReadingTimeout(checked) }
                    },
                    {
                        text: qsTr("Invalid Hall Sensor Sequence"),
                        checked: motorDetails.InvalidHallSensorSequence,
                        onClicked: function(checked) { motorDetails.setInvalidHallSensorSequence(checked) }
                    },
                    {
                        text: qsTr("Invalid Hall Sector"),
                        checked: motorDetails.InvalidHallSector,
                        onClicked: function(checked) { motorDetails.setInvalidHallSector(checked) }
                    },
                    {
                        text: qsTr("Error Reading Temp Sensor"),
                        checked: motorDetails.ErrorReadingTempSensor,
                        onClicked: function(checked) { motorDetails.setErrorReadingTempSensor(checked) }
                    },
                    {
                        text: qsTr("Position Sensor Reading Error"),
                        checked: motorDetails.PositionSensorReadingError,
                        onClicked: function(checked) { motorDetails.setPositionSensorReadingError(checked) }
                    },
                    {
                        text: qsTr("Error Reading Encoder"),
                        checked: motorDetails.ErrorReadingEncoder,
                        onClicked: function(checked) { motorDetails.setErrorReadingEncoder(checked) }
                    },
                    {
                        text: qsTr("Zero Position Offset Not Set"),
                        checked: motorDetails.ZeroPositionOffsetNotSet,
                        onClicked: function(checked) { motorDetails.setZeroPositionOffsetNotSet(checked) }
                    },
                    {
                        text: qsTr("HW Enable Not Set"),
                        checked: motorDetails.HwEnableNotSet,
                        onClicked: function(checked) { motorDetails.setHwEnableNotSet(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Temp Too High"),
                        checked: motorDetails.Inverter1TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter1TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Temp Too High"),
                        checked: motorDetails.Inverter2TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter2TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Temp Too High"),
                        checked: motorDetails.Inverter3TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter3TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Temp Too High"),
                        checked: motorDetails.Inverter4TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter4TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Temp Too High"),
                        checked: motorDetails.Inverter5TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter5TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Temp Too High"),
                        checked: motorDetails.Inverter6TempTooHigh,
                        onClicked: function(checked) { motorDetails.setInverter6TempTooHigh(checked) }
                    },
                    {
                        text: qsTr("CPU Temperature Too High"),
                        checked: motorDetails.CpuTemperatureTooHigh,
                        onClicked: function(checked) { motorDetails.setCpuTemperatureTooHigh(checked) }
                    },
                    {
                        text: qsTr("Hall Temperature Too High"),
                        checked: motorDetails.HallTemperatureTooHigh,
                        onClicked: function(checked) { motorDetails.setHallTemperatureTooHigh(checked) }
                    },
                    {
                        text: qsTr("DC Link Temperature Too High"),
                        checked: motorDetails.DclinkTemperatureTooHigh,
                        onClicked: function(checked) { motorDetails.setDclinkTemperatureTooHigh(checked) }
                    },
                    {
                        text: qsTr("Error In DC Link Communication"),
                        checked: motorDetails.ErrorInDclinkCommunication,
                        onClicked: function(checked) { motorDetails.setErrorInDclinkCommunication(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Overcurrent Error"),
                        checked: motorDetails.Inverter1OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter1OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Overcurrent Error"),
                        checked: motorDetails.Inverter2OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter2OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Overcurrent Error"),
                        checked: motorDetails.Inverter3OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter3OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Overcurrent Error"),
                        checked: motorDetails.Inverter4OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter4OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Overcurrent Error"),
                        checked: motorDetails.Inverter5OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter5OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Overcurrent Error"),
                        checked: motorDetails.Inverter6OvercurrentError,
                        onClicked: function(checked) { motorDetails.setInverter6OvercurrentError(checked) }
                    },
                    {
                        text: qsTr("DC Overvoltage Error"),
                        checked: motorDetails.DcOvervoltageError,
                        onClicked: function(checked) { motorDetails.setDcOvervoltageError(checked) }
                    },
                    {
                        text: qsTr("DC Undervoltage Error"),
                        checked: motorDetails.DcUndervoltageError,
                        onClicked: function(checked) { motorDetails.setDcUndervoltageError(checked) }
                    },
                    {
                        text: qsTr("Double CAN ID On Bus"),
                        checked: motorDetails.DoubleCanIdOnBus,
                        onClicked: function(checked) { motorDetails.setDoubleCanIdOnBus(checked) }
                    },
                    {
                        text: qsTr("CAN Comms Timeout Error"),
                        checked: motorDetails.CanCommsTimeoutError,
                        onClicked: function(checked) { motorDetails.setCanCommsTimeoutError(checked) }
                    },
                    {
                        text: qsTr("Inverter 1 Fault Error"),
                        checked: motorDetails.Inverter1FaultError,
                        onClicked: function(checked) { motorDetails.setInverter1FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 2 Fault Error"),
                        checked: motorDetails.Inverter2FaultError,
                        onClicked: function(checked) { motorDetails.setInverter2FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 3 Fault Error"),
                        checked: motorDetails.Inverter3FaultError,
                        onClicked: function(checked) { motorDetails.setInverter3FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 4 Fault Error"),
                        checked: motorDetails.Inverter4FaultError,
                        onClicked: function(checked) { motorDetails.setInverter4FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 5 Fault Error"),
                        checked: motorDetails.Inverter5FaultError,
                        onClicked: function(checked) { motorDetails.setInverter5FaultError(checked) }
                    },
                    {
                        text: qsTr("Inverter 6 Fault Error"),
                        checked: motorDetails.Inverter6FaultError,
                        onClicked: function(checked) { motorDetails.setInverter6FaultError(checked) }
                    },
                    {
                        text: qsTr("CAN Send Error"),
                        checked: motorDetails.CanSendError,
                        onClicked: function(checked) { motorDetails.setCanSendError(checked) }
                    },
                    {
                        text: qsTr("Lost Frames On CAN Bus Error"),
                        checked: motorDetails.LostFramesOnCanBusError,
                        onClicked: function(checked) { motorDetails.setLostFramesOnCanBusError(checked) }
                    },
                    {
                        text: qsTr("Overspeed Error"),
                        checked: motorDetails.OverspeedError,
                        onClicked: function(checked) { motorDetails.setOverspeedError(checked) }
                    },
                    {
                        text: qsTr("CPU Overloaded"),
                        checked: motorDetails.CpuOverloaded,
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
