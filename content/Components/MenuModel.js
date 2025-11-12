.pragma library

var menuModel = [
            {
                title: "Key Motor",
                icon: "../images/KeyMotorIcon.png",
                fields: [
                    {
                        name: "Drive Commands",
                        getter: "DriveCommand",
                        freq: "10",
                        id: "0x501",
                        messageLength: 8,
                        children: [
                            {
                                name: "Motor Velocity",
                                units: "RPM",
                                min: -10000,
                                max: 10000,
                                type: "float",
                                decimalPlaces: 2,
                                getter: "Velocity",
                                setter: "setVelocity"
                            },
                            {
                                name: "Motor Current",
                                units: "%",
                                min: -100,
                                max: 100,
                                type: "float",
                                decimalPlaces: 2,
                                getter: "Current",
                                setter: "setCurrent"
                            }
                        ]
                    },
                    {
                        name: "Power Commands",
                        getter: "PowerCommand",
                        freq: "10",
                        id: "0x502",
                        messageLength: 8,
                        children: [
                            {
                                name: "Bus Current Out",
                                units: "%",
                                min: 0,
                                max: 100,
                                type: "float",
                                decimalPlaces: 2,
                                getter: "BusCurrentOut",
                                setter: "setBusCurrentOut"
                            }
                        ]
                    }
                ]
            },
            {
                title: "Motor Details",
                icon: "../images/MotorIcon.png",
                fields: [{name: "test"}]
            },
            {
                title: "B^3",
                icon: "../images/B3Icon.png",
                fields: [
                    {
                        name: "Light Inputs",
                        getter: "LightsInputs",
                        freq: "10",
                        id: "0x610",
                        messageLength: 1,
                        children: [
                            {
                                name: "Right Signal",
                                type: "bool",
                                getter: "RightSignalIn",
                                setter: "setRightSignalIn"
                            },
                            {
                                name: "Left Signal",
                                type: "bool",
                                getter: "LeftSignalIn",
                                setter: "setLeftSignalIn"
                            },
                            {
                                name: "Hazard Lights",
                                type: "bool",
                                getter: "HazardLightsIn",
                                setter: "setHazardLightsIn"
                            },
                            {
                                name: "Headlights",
                                type: "bool",
                                getter: "HeadlightsIn",
                                setter: "setHeadlightsIn"
                            },
                        ],
                    },
                    {
                        name: "Digital Inputs",
                        getter: "DigitalInputs",
                        freq: "20",
                        id: "0x611",
                        messageLength: 2,
                        children: [
                            {
                                name: "Foward",
                                type: "bool",
                                getter: "Forward",
                                setter: "setForward"
                            },
                            {
                                name: "Neutral",
                                type: "bool",
                                getter: "Neutral",
                                setter: "setNeutral"
                            },
                            {
                                name: "Reverse",
                                type: "bool",
                                getter: "Reverse",
                                setter: "setReverse"
                            },
                            {
                                name: "Horn",
                                type: "bool",
                                getter: "Horn",
                                setter: "setHorn"
                            },
                            {
                                name: "Brake",
                                type: "bool",
                                getter: "Brake",
                                setter: "setBrake"
                            },
                            {
                                name: "Handbrake",
                                type: "bool",
                                getter: "Handbrake",
                                setter: "setHandbrake"
                            },
                            {
                                name: "Motor Reset",
                                type: "bool",
                                getter: "MotorReset",
                                setter: "setMotorReset"
                            },
                            {
                                name: "Race Mode",
                                type: "bool",
                                getter: "RaceMode",
                                setter: "setRaceMode"
                            },
                            {
                                name: "Lap",
                                type: "bool",
                                getter: "Lap",
                                setter: "setLap"
                            },
                        ],
                    },
                    {
                        name: "Analog Inputs",
                        getter: "AnalogInputs",
                        freq: "20",
                        id: "0x612",
                        messageLength: 2,
                        children: [
                            {
                                name: "Acceleration",
                                units: "%",
                                min: 0,
                                max: 100,
                                type: "num",
                                getter: "Acceleration",
                                setter: "setAcceleration"
                            },
                            {
                                name: "Regen Braking",
                                units: "%",
                                min: 0,
                                max: 100,
                                type: "num",
                                getter: "RegenBraking",
                                setter: "setRegenBraking"
                            }
                        ],
                    },
                    {
                        name: "Lights Status",
                        getter: "LightsStatus",
                        freq: "5",
                        id: "0x620",
                        messageLength: 1,
                        children: [
                            {
                                name: "Right Signal",
                                type: "bool",
                                getter: "RightSignalStatus",
                                setter: "setRightSignalStatus"
                            },
                            {
                                name: "Left Signal",
                                type: "bool",
                                getter: "LeftSignalStatus",
                                setter: "setLeftSignalStatus"
                            },
                            {
                                name: "Daytime Running Lights",
                                type: "bool",
                                getter: "DaytimeRunningLightStatus",
                                setter: "setDaytimeRunningLightStatus"
                            },
                            {
                                name: "Headlights",
                                type: "bool",
                                getter: "HeadlightStatus",
                                setter: "setHeadlightStatus"
                            },
                            {
                                name: "Brake Lights",
                                type: "bool",
                                getter: "BrakeLightStatus",
                                setter: "setBrakeLightStatus"
                            },
                            {
                                name: "Horn",
                                type: "bool",
                                getter: "HornStatus",
                                setter: "setHornStatus"
                            },
                        ],
                    }
                ]
            },
            {
                title: "Telemetry",
                icon: "../images/TelemetryIcon.png",
                fields: [
                    {
                        name: "GPS Time",
                        getter: "GpsTime",
                        freq: "2",
                        id: "0x630",
                        messageLength: 8,
                        children: [
                            {
                                name: "Year",
                                units: "n/a",
                                min: 0,
                                max: 65535,
                                type: "num",
                                getter: "Year",
                                setter: "setYear"
                            },
                            {
                                name: "Month",
                                units: "n/a",
                                min: 1,
                                max: 12,
                                type: "num",
                                getter: "Month",
                                setter: "setMonth"
                            },
                            {
                                name: "Day",
                                units: "n/a",
                                min: 1,
                                max: 31,
                                type: "num",
                                getter: "Day",
                                setter: "setDay"
                            },
                            {
                                name: "Hour",
                                units: "n/a",
                                min: 0,
                                max: 23,
                                type: "num",
                                getter: "Hour",
                                setter: "setHour"
                            },
                            {
                                name: "Minute",
                                units: "n/a",
                                min: 0,
                                max: 59,
                                type: "num",
                                getter: "Minute",
                                setter: "setMinute"
                            },
                            {
                                name: "Second",
                                units: "n/a",
                                min: 0,
                                max: 59,
                                type: "num",
                                getter: "Second",
                                setter: "setSecond"
                            }
                        ]
                    },
                    {
                        name: "GPS Flags",
                        getter: "GpsFlags",
                        freq: "2",
                        id: "0x631",
                        messageLength: 4,
                        children: [
                            {
                                name: "Validity Flags",
                                units: "n/a",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: "ValidityFlags",
                                setter: "setValidityFlags"
                            },
                            {
                                name: "Fix Status Flags",
                                units: "n/a",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: "FixStatusFlags",
                                setter: "setFixStatusFlags"
                            },
                            {
                                name: "Additional Flags",
                                units: "n/a",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: "AdditionalFlags",
                                setter: "setAdditionalFlags"
                            }
                        ]
                    },
                    {
                        name: "GPS Position",
                        getter: "GpsPosition",
                        freq: "2",
                        id: "0x632",
                        messageLength: 8,
                        children: [
                            {
                                name: "Longitude",
                                units: "degrees",
                                min: -180,
                                max: 180,
                                type: "float",
                                decimalPlaces: 6,
                                getter: "Longitude",
                                setter: "setLongitude"
                            },
                            {
                                name: "Latitude",
                                units: "degrees",
                                min: -90,
                                max: 90,
                                type: "float",
                                decimalPlaces: 6,
                                getter: "Latitude",
                                setter: "setLatitude"
                            }
                        ]
                    },
                    {
                        name: "MPU Acceleration",
                        getter: "MpuAcceleration",
                        freq: "2",
                        id: "0x633",
                        messageLength: 8,
                        children: [
                            {
                                name: "X Acceleration",
                                units: "m/s²",
                                min: -32768,
                                max: 32767,
                                type: "num",
                                getter: "AccelerationX",
                                setter: "setAccelerationX"
                            },
                            {
                                name: "Y Acceleration",
                                units: "m/s²",
                                min: -32768,
                                max: 32767,
                                type: "num",
                                getter: "AccelerationY",
                                setter: "setAccelerationY"
                            },
                            {
                                name: "Z Acceleration",
                                units: "m/s²",
                                min: -32768,
                                max: 32767,
                                type: "num",
                                getter: "AccelerationZ",
                                setter: "setAccelerationZ"
                            }
                        ]
                    },
                    {
                        name: "MPU Gyroscope",
                        getter: "MpuGyroscope",
                        freq: "2",
                        id: "0x634",
                        messageLength: 8,
                        children: [
                            {
                                name: "X Rotation",
                                units: "°/s",
                                min: -32768,
                                max: 32767,
                                type: "num",
                                getter: "RotationX",
                                setter: "setRotationX"
                            },
                            {
                                name: "Y Rotation",
                                units: "°/s",
                                min: -32768,
                                max: 32767,
                                type: "num",
                                getter: "RotationY",
                                setter: "setRotationY"
                            },
                            {
                                name: "Z Rotation",
                                units: "°/s",
                                min: -32768,
                                max: 32767,
                                type: "num",
                                getter: "RotationZ",
                                setter: "setRotationZ"
                            }
                        ]
                    },
                    {
                        name: "MPU Temperature",
                        getter: "MpuTemperature",
                        freq: "2",
                        id: "0x635",
                        messageLength: 2,
                        children: [
                            {
                                name: "Temperature",
                                units: "°C",
                                min: -32768,
                                max: 32767,
                                type: "num",
                                getter: "MpuTemperature",
                                setter: "setMpuTemperature"
                            }
                        ]
                    }
                ]
            },
            {
                title: "Battery Faults",
                icon: "../images/BatteryFaultsIcon.png",
                fields: [{name: "test"}]
            },
            {
                title: "Battery",
                icon: "../images/BatteryIcon.png",
                fields: [{name: "test"}]
            },
            {
                title: "MPPT",
                icon: "../images/MpptIcon.png",
                fields: [{name: "test"}]
            },
            {
                title: "MBMS",
                icon: "../images/MbmsIcon.png",
                fields: [
                    {
                        name: "Contactor Commands",
                        getter: "ContactorCommand",
                        freq: "10",
                        id: "0x101",
                        messageLength: 1,
                        children: [
                            {
                                name: "Common Contactor Command",
                                type: "bool",
                                getter: "CommonContactorCommand",
                                setter: "setCommonContactorCommand"
                            },
                            {
                                name: "Motor Contactor Command",
                                type: "bool",
                                getter: "MotorContactorCommand",
                                setter: "setMotorContactorCommand"
                            },
                            {
                                name: "Array Contactor Command",
                                type: "bool",
                                getter: "ArrayContactorCommand",
                                setter: "setArrayContactorCommand"
                            },
                            {
                                name: "LV Contactor Command",
                                type: "bool",
                                getter: "LvContactorCommand",
                                setter: "setLvContactorCommand"
                            },
                            {
                                name: "Charge Contactor Command",
                                type: "bool",
                                getter: "ChargeContactorCommand",
                                setter: "setChargeContactorCommand"
                            }
                        ]
                    },
                    {
                        name: "Statuses",
                        getter: "Status",
                        freq: "10",
                        id: "0x102",
                        messageLength: 4,
                        children: [
                            {
                                name: "Auxillary Battery Voltage",
                                units: "V",
                                min: 0,
                                max: 31,
                                type: "num",
                                getter: "AuxillaryBatteryVoltage",
                                setter: "setAuxillaryBatteryVoltage"
                            },
                            {
                                name: "Strobe BMS Light",
                                type: "bool",
                                getter: "StrobeBmsLight",
                                setter: "setStrobeBmsLight"
                            },
                            {
                                name: "Charge Enable",
                                type: "bool",
                                getter: "ChargeEnable",
                                setter: "setChargeEnable"
                            },
                            {
                                name: "N Charge Safety",
                                type: "bool",
                                getter: "NChargeSafety",
                                setter: "setNChargeSafety"
                            },
                            {
                                name: "Discharge Enable",
                                type: "bool",
                                getter: "DischargeEnable",
                                setter: "setDischargeEnable"
                            },
                            {
                                name: "Orion Can Received Recently",
                                type: "bool",
                                getter: "OrionCanReceivedRecently",
                                setter: "setOrionCanReceivedRecently"
                            },
                            {
                                name: "Discharge Should Trip",
                                type: "bool",
                                getter: "DischargeShouldTrip",
                                setter: "setDischargeShouldTrip"
                            },
                            {
                                name: "Charge Should Trip",
                                type: "bool",
                                getter: "ChargeShouldTrip",
                                setter: "setChargeShouldTrip"
                            },
                            {
                                name: "Startup State",
                                units: "n/a",
                                min: 0,
                                max: 31,
                                type: "num",
                                getter: "StartupState",
                                setter: "setStartupState"
                            },
                            {
                                name: "System State",
                                units: "n/a",
                                min: 0,
                                max: 15,
                                type: "num",
                                getter: "SystemState",
                                setter: "setSystemState"
                            }
                        ]
                    },
                    {
                        name: "Power Selection Statuses",
                        getter: "PowerSelectionStatus",
                        freq: "10",
                        id: "0x103",
                        messageLength: 2,
                        children: [
                            {
                                name: "N Main Power Switch",
                                type: "bool",
                                getter: "NMainPowerSwitch",
                                setter: "setNMainPowerSwitch"
                            },
                            {
                                name: "External Shutdown",
                                type: "bool",
                                getter: "ExternalShutdown",
                                setter: "setExternalShutdown"
                            },
                            {
                                name: "En1",
                                type: "bool",
                                getter: "En1",
                                setter: "setEn1"
                            },
                            {
                                name: "N DCDC Fault",
                                type: "bool",
                                getter: "NDcdcFault",
                                setter: "setNDcdcFault"
                            },
                            {
                                name: "N 3AOC",
                                type: "bool",
                                getter: "N3Aoc",
                                setter: "setN3Aoc"
                            },
                            {
                                name: "N DCDC On",
                                type: "bool",
                                getter: "NDcdcOn",
                                setter: "setNDcdcOn"
                            },
                            {
                                name: "N Charge Fault",
                                type: "bool",
                                getter: "NChgFault",
                                setter: "setNChgFault"
                            },
                            {
                                name: "N Charge On",
                                type: "bool",
                                getter: "NChgOn",
                                setter: "setNChgOn"
                            },
                            {
                                name: "N Charge LV Enable",
                                type: "bool",
                                getter: "NChgLvEn",
                                setter: "setNChgLvEn"
                            },
                            {
                                name: "ABatt Disable",
                                type: "bool",
                                getter: "AbattDisable",
                                setter: "setAbattDisable"
                            },
                            {
                                name: "Key",
                                type: "bool",
                                getter: "Key",
                                setter: "setKey"
                            }
                        ]
                    },
                    {
                        name: "Trips",
                        getter: "Trip",
                        freq: "10",
                        id: "0x104",
                        messageLength: 4,
                        children: [
                            {
                                name: "High Cell Voltage Trip",
                                type: "bool",
                                getter: "HighCellVoltageTrip",
                                setter: "setHighCellVoltageTrip"
                            },
                            {
                                name: "Low Cell Voltage Trip",
                                type: "bool",
                                getter: "LowCellVoltageTrip",
                                setter: "setLowCellVoltageTrip"
                            },
                            {
                                name: "Common High Current Trip",
                                type: "bool",
                                getter: "CommonHighCurrentTrip",
                                setter: "setCommonHighCurrentTrip"
                            },
                            {
                                name: "Motor High Current Trip",
                                type: "bool",
                                getter: "MotorHighCurrentTrip",
                                setter: "setMotorHighCurrentTrip"
                            },
                            {
                                name: "Array High Current Trip",
                                type: "bool",
                                getter: "ArrayHighCurrentTrip",
                                setter: "setArrayHighCurrentTrip"
                            },
                            {
                                name: "Lv High Current Trip",
                                type: "bool",
                                getter: "LvHighCurrentTrip",
                                setter: "setLvHighCurrentTrip"
                            },
                            {
                                name: "Charge High Current Trip",
                                type: "bool",
                                getter: "ChargeHighCurrentTrip",
                                setter: "setChargeHighCurrentTrip"
                            },
                            {
                                name: "Protection Trip",
                                type: "bool",
                                getter: "ProtectionTrip",
                                setter: "setProtectionTrip"
                            },
                            {
                                name: "Orion Message Timeout Trip",
                                type: "bool",
                                getter: "OrionMessageTimeoutTrip",
                                setter: "setOrionMessageTimeoutTrip"
                            },
                            {
                                name: "Contactor Disconnected Unexpectedly Trip",
                                type: "bool",
                                getter: "ContactorDisconnectedUnexpectedlyTrip",
                                setter: "setContactorDisconnectedUnexpectedlyTrip"
                            },
                            {
                                name: "Contactor Connected Unexpectedly Trip",
                                type: "bool",
                                getter: "ContactorConnectedUnexpectelyTrip",
                                setter: "setContactorConnectedUnexpectelyTrip"
                            },
                            {
                                name: "Common Heartbeat Dead Trip",
                                type: "bool",
                                getter: "CommonHeartbeatDeadTrip",
                                setter: "setCommonHeartbeatDeadTrip"
                            },
                            {
                                name: "Motor Heartbeat Dead Trip",
                                type: "bool",
                                getter: "MotorHeartbeatDeadTrip",
                                setter: "setMotorHeartbeatDeadTrip"
                            },
                            {
                                name: "Array Heartbeat Dead Trip",
                                type: "bool",
                                getter: "ArrayHeartbeatDeadTrip",
                                setter: "setArrayHeartbeatDeadTrip"
                            },
                            {
                                name: "Lv Heartbeat Dead Trip",
                                type: "bool",
                                getter: "LvHeartbeatDeadTrip",
                                setter: "setLvHeartbeatDeadTrip"
                            },
                            {
                                name: "Charge Heartbeat Dead Trip",
                                type: "bool",
                                getter: "ChargeHeartbeatDeadTrip",
                                setter: "setChargeHeartbeatDeadTrip"
                            },
                            {
                                name: "Mps Disabled Trip",
                                type: "bool",
                                getter: "MpsDisabledTrip",
                                setter: "setMpsDisabledTrip"
                            },
                            {
                                name: "Esd Enabled Trip",
                                type: "bool",
                                getter: "EsdEnabledTrip",
                                setter: "setEsdEnabledTrip"
                            },
                            {
                                name: "High Temperature Trip",
                                type: "bool",
                                getter: "HighTemperatureTrip",
                                setter: "setHighTemperatureTrip"
                            },
                            {
                                name: "Low Temperature Trip",
                                type: "bool",
                                getter: "LowTemperatureTrip",
                                setter: "setLowTemperatureTrip"
                            }
                        ]
                    },
                    {
                        name: "Soft Battery Limit Warnings",
                        getter: "SoftBatteryLimitWarning",
                        freq: "10",
                        id: "0x105",
                        messageLength: 2,
                        children: [
                            {
                                name: "High Cell Voltage Warning",
                                type: "bool",
                                getter: "HighCellVoltageWarning",
                                setter: "setHighCellVoltageWarning"
                            },
                            {
                                name: "Low Cell Voltage Warning",
                                type: "bool",
                                getter: "LowCellVoltageWarning",
                                setter: "setLowCellVoltageWarning"
                            },
                            {
                                name: "Common High Current Warning",
                                type: "bool",
                                getter: "CommonHighCurrentWarning",
                                setter: "setCommonHighCurrentWarning"
                            },
                            {
                                name: "Motor High Current Warning",
                                type: "bool",
                                getter: "MotorHighCurrentWarning",
                                setter: "setMotorHighCurrentWarning"
                            },
                            {
                                name: "Array High Current Warning",
                                type: "bool",
                                getter: "ArrayHighCurrentWarning",
                                setter: "setArrayHighCurrentWarning"
                            },
                            {
                                name: "Lv High Current Warning",
                                type: "bool",
                                getter: "LvHighCurrentWarning",
                                setter: "setLvHighCurrentWarning"
                            },
                            {
                                name: "Charge High Current Warning",
                                type: "bool",
                                getter: "ChargeHighCurrentWarning",
                                setter: "setChargeHighCurrentWarning"
                            },
                            {
                                name: "High Temperature Warning",
                                type: "bool",
                                getter: "HighTemperatureWarning",
                                setter: "setHighTemperatureWarning"
                            },
                            {
                                name: "Low Temperature Warning",
                                type: "bool",
                                getter: "LowTemperatureWarning",
                                setter: "setLowTemperatureWarning"
                            },
                            {
                                name: "Can Oc12V Warning",
                                type: "bool",
                                getter: "CanOc12VWarning",
                                setter: "setCanOc12VWarning"
                            }
                        ]
                    }
                ]
            },
            {
                title: "Proximity Sensors",
                icon: "../images/ProximityIcon.png",
                fields: [
                    {
                        name: "Proximity Sensor 1",
                        getter: "ProximitySensor1",
                        freq: "2",
                        id: "0x700",
                        messageLength: 2,
                        children: [
                            {
                                name: "Distance 1",
                                units: "cm",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: "ProximitySensor1",
                                setter: "setProximitySensor1"
                            }
                        ],
                    },
                    {
                        name: "Proximity Sensor 2",
                        getter: "ProximitySensor2",
                        freq: "2",
                        id: "0x701",
                        messageLength: 2,
                        children: [
                            {
                                name: "Distance 2",
                                units: "cm",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: "ProximitySensor2",
                                setter: "setProximitySensor2"
                            }
                        ],
                    },
                    {
                        name: "Proximity Sensor 3",
                        getter: "ProximitySensor3",
                        freq: "2",
                        id: "0x702",
                        messageLength: 2,
                        children: [
                            {
                                name: "Distance 3",
                                units: "cm",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: "ProximitySensor3",
                                setter: "setProximitySensor3"
                            }
                        ],
                    },
                    {
                        name: "Proximity Sensor 4",
                        getter: "ProximitySensor4",
                        freq: "2",
                        id: "0x703",
                        messageLength: 2,
                        children: [
                            {
                                name: "Distance 4",
                                units: "cm",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: "ProximitySensor4",
                                setter: "setProximitySensor4"
                            }
                        ],
                    },
                ]
            },
            {
                title: "Contactors",
                icon: "../images/ContactorsIcon.png",
                fields: [
                    {
                        name: "Common Contactor",
                        getter: "Common",
                        freq: "10",
                        id: "0x210",
                        messageLength: 4,
                        children: [
                            {
                                name: "Is Precharger Closed",
                                type: "bool",
                                getter: "CommonIsPrechargerClosed",
                                setter: "setCommonIsPrechargerClosed"
                            },
                            {
                                name: "Is Precharger Closing",
                                type: "bool",
                                getter: "CommonIsPrechargerClosing",
                                setter: "setCommonIsPrechargerClosing"
                            },
                            {
                                name: "Precharger Error",
                                type: "bool",
                                getter: "CommonPrechargerError",
                                setter: "setCommonPrechargerError"
                            },
                            {
                                name: "Is Contactor Closed",
                                type: "bool",
                                getter: "CommonIsContactorClosed",
                                setter: "setCommonIsContactorClosed"
                            },
                            {
                                name: "Is Contactor Closing",
                                type: "bool",
                                getter: "CommonIsContactorClosing",
                                setter: "setCommonIsContactorClosing"
                            },
                            {
                                name: "Contactor Error",
                                type: "bool",
                                getter: "CommonContactorError",
                                setter: "setCommonContactorError"
                            },
                            {
                                name: "Line Current",
                                units: "0.1A",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "CommonLineCurrent",
                                setter: "setCommonLineCurrent"
                            },
                            {
                                name: "Charge Current",
                                units: "Unknown",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "CommonChargeCurrent",
                                setter: "setCommonChargeCurrent"
                            },
                            {
                                name: "Contactor Opening Error",
                                type: "bool",
                                getter: "CommonContactorOpeningError",
                                setter: "setCommonContactorOpeningError"
                            }
                        ]
                    },
                    {
                        name: "Motor Contactor",
                        getter: "Motor",
                        freq: "10",
                        id: "0x211",
                        messageLength: 4,
                        children: [
                            {
                                name: "Is Precharger Closed",
                                type: "bool",
                                getter: "MotorIsPrechargerClosed",
                                setter: "setMotorIsPrechargerClosed"
                            },
                            {
                                name: "Is Precharger Closing",
                                type: "bool",
                                getter: "MotorIsPrechargerClosing",
                                setter: "setMotorIsPrechargerClosing"
                            },
                            {
                                name: "Precharger Error",
                                type: "bool",
                                getter: "MotorPrechargerError",
                                setter: "setMotorPrechargerError"
                            },
                            {
                                name: "Is Contactor Closed",
                                type: "bool",
                                getter: "MotorIsContactorClosed",
                                setter: "setMotorIsContactorClosed"
                            },
                            {
                                name: "Is Contactor Closing",
                                type: "bool",
                                getter: "MotorIsContactorClosing",
                                setter: "setMotorIsContactorClosing"
                            },
                            {
                                name: "Contactor Error",
                                type: "bool",
                                getter: "MotorContactorError",
                                setter: "setMotorContactorError"
                            },
                            {
                                name: "Line Current",
                                units: "0.1A",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "MotorLineCurrent",
                                setter: "setMotorLineCurrent"
                            },
                            {
                                name: "Charge Current",
                                units: "Unknown",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "MotorChargeCurrent",
                                setter: "setMotorChargeCurrent"
                            },
                            {
                                name: "BPS Error",
                                type: "bool",
                                getter: "MotorBpsError",
                                setter: "setMotorBpsError"
                            }
                        ]
                    },
                    {
                        name: "Array Contactor",
                        getter: "Array",
                        freq: "10",
                        id: "0x212",
                        messageLength: 4,
                        children: [
                            {
                                name: "Is Precharger Closed",
                                type: "bool",
                                getter: "ArrayIsPrechargerClosed",
                                setter: "setArrayIsPrechargerClosed"
                            },
                            {
                                name: "Is Precharger Closing",
                                type: "bool",
                                getter: "ArrayIsPrechargerClosing",
                                setter: "setArrayIsPrechargerClosing"
                            },
                            {
                                name: "Precharger Error",
                                type: "bool",
                                getter: "ArrayPrechargerError",
                                setter: "setArrayPrechargerError"
                            },
                            {
                                name: "Is Contactor Closed",
                                type: "bool",
                                getter: "ArrayIsContactorClosed",
                                setter: "setArrayIsContactorClosed"
                            },
                            {
                                name: "Is Contactor Closing",
                                type: "bool",
                                getter: "ArrayIsContactorClosing",
                                setter: "setArrayIsContactorClosing"
                            },
                            {
                                name: "Contactor Error",
                                type: "bool",
                                getter: "ArrayContactorError",
                                setter: "setArrayContactorError"
                            },
                            {
                                name: "Line Current",
                                units: "0.1A",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "ArrayLineCurrent",
                                setter: "setArrayLineCurrent"
                            },
                            {
                                name: "Charge Current",
                                units: "Unknown",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "ArrayChargeCurrent",
                                setter: "setArrayChargeCurrent"
                            },
                            {
                                name: "BPS Error",
                                type: "bool",
                                getter: "ArrayBpsError",
                                setter: "setArrayBpsError"
                            }
                        ]
                    },
                    {
                        name: "LV Contactor",
                        getter: "Lv",
                        freq: "10",
                        id: "0x213",
                        messageLength: 4,
                        children: [
                            {
                                name: "Is Precharger Closed",
                                type: "bool",
                                getter: "LvIsPrechargerClosed",
                                setter: "setLvIsPrechargerClosed"
                            },
                            {
                                name: "Is Precharger Closing",
                                type: "bool",
                                getter: "LvIsPrechargerClosing",
                                setter: "setLvIsPrechargerClosing"
                            },
                            {
                                name: "Precharger Error",
                                type: "bool",
                                getter: "LvPrechargerError",
                                setter: "setLvPrechargerError"
                            },
                            {
                                name: "Is Contactor Closed",
                                type: "bool",
                                getter: "LvIsContactorClosed",
                                setter: "setLvIsContactorClosed"
                            },
                            {
                                name: "Is Contactor Closing",
                                type: "bool",
                                getter: "LvIsContactorClosing",
                                setter: "setLvIsContactorClosing"
                            },
                            {
                                name: "Contactor Error",
                                type: "bool",
                                getter: "LvContactorError",
                                setter: "setLvContactorError"
                            },
                            {
                                name: "Line Current",
                                units: "0.1A",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "LvLineCurrent",
                                setter: "setLvLineCurrent"
                            },
                            {
                                name: "Charge Current",
                                units: "Unknown",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "LvChargeCurrent",
                                setter: "setLvChargeCurrent"
                            },
                            {
                                name: "BPS Error",
                                type: "bool",
                                getter: "LvBpsError",
                                setter: "setLvBpsError"
                            }
                        ]
                    },
                    {
                        name: "Charge Contactor",
                        getter: "Charge",
                        freq: "10",
                        id: "0x214",
                        messageLength: 4,
                        children: [
                            {
                                name: "Is Precharger Closed",
                                type: "bool",
                                getter: "ChargeIsPrechargerClosed",
                                setter: "setChargeIsPrechargerClosed"
                            },
                            {
                                name: "Is Precharger Closing",
                                type: "bool",
                                getter: "ChargeIsPrechargerClosing",
                                setter: "setChargeIsPrechargerClosing"
                            },
                            {
                                name: "Precharger Error",
                                type: "bool",
                                getter: "ChargePrechargerError",
                                setter: "setChargePrechargerError"
                            },
                            {
                                name: "Is Contactor Closed",
                                type: "bool",
                                getter: "ChargeIsContactorClosed",
                                setter: "setChargeIsContactorClosed"
                            },
                            {
                                name: "Is Contactor Closing",
                                type: "bool",
                                getter: "ChargeIsContactorClosing",
                                setter: "setChargeIsContactorClosing"
                            },
                            {
                                name: "Contactor Error",
                                type: "bool",
                                getter: "ChargeContactorError",
                                setter: "setChargeContactorError"
                            },
                            {
                                name: "Line Current",
                                units: "0.1A",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "ChargeLineCurrent",
                                setter: "setChargeLineCurrent"
                            },
                            {
                                name: "Charge Current",
                                units: "Unknown",
                                min: 0,
                                max: 4095,
                                type: "num",
                                getter: "ChargeChargeCurrent",
                                setter: "setChargeChargeCurrent"
                            },
                            {
                                name: "BPS Error",
                                type: "bool",
                                getter: "ChargeBpsError",
                                setter: "setChargeBpsError"
                            }
                        ]
                    }
                ]
            }
        ]
