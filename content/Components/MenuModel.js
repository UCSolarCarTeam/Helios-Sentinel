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
                fields: [{name: "test"}]
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
                                name: "Distance 3",
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
                fields: [{name: "test"}]
            }
        ]
