.pragma library

var menuModel = [
            {
                title: "Key Motor",
                icon: "../images/KeyMotorIcon.png",
                fields: [{name: "test"}]
            },
            {
                title: "Motor Details",
                icon: "../images/MotorIcon.png",
                fields: [{name: "test"}]
            },
            {
                title: "B^3",
                icon: "../images/B3Icon.png",
                fields: [{name: "test"}]
            },
            {
                title: "Telemetry",
                icon: "../images/TelemetryIcon.png",
                fields: [{name: "test"}]
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
                        getter: function() { return proximitySensors.ProximitySensor1 },
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
                                getter: function() { return proximitySensors.ProximitySensor1 },
                                setter: function(v) { proximitySensors.setProximitySensor1(v) }
                            }
                        ],
                    },
                    {
                        name: "Proximity Sensor 2",
                        getter: function() { return proximitySensors.ProximitySensor2 },
                        freq: "2",
                        id: "0x700",
                        messageLength: 2,
                        children: [
                            {
                                name: "Distance 2",
                                units: "cm",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: function() { return proximitySensors.ProximitySensor2 },
                                setter: function(v) { proximitySensors.setProximitySensor2(v) }
                            }
                        ],
                    },
                    {
                        name: "Proximity Sensor 3",
                        getter: function() { return proximitySensors.ProximitySensor3 },
                        freq: "2",
                        id: "0x700",
                        messageLength: 2,
                        children: [
                            {
                                name: "Distance 3",
                                units: "cm",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: function() { return proximitySensors.ProximitySensor3 },
                                setter: function(v) { proximitySensors.setProximitySensor3(v) }
                            }
                        ],
                    },
                    {
                        name: "Proximity Sensor 3",
                        getter: function() { return proximitySensors.ProximitySensor3 },
                        freq: "2",
                        id: "0x700",
                        messageLength: 2,
                        children: [
                            {
                                name: "Distance 3",
                                units: "cm",
                                min: 0,
                                max: 255,
                                type: "num",
                                getter: function() { return proximitySensors.ProximitySensor3 },
                                setter: function(v) { proximitySensors.setProximitySensor3(v) }
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
