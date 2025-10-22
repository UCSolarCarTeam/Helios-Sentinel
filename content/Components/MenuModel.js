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
                        name: "Sensor 1",
                        units: "cm",
                        min: 0,
                        max: 255,
                        children: 0,
                        parent: false,
                        type: "num",
                        getter: function() { return proximitySensors.ProximitySensor1 },
                        setter: function(v) { proximitySensors.setProximitySensor1(v) }
                    },
                    {
                        name: "Sensor 2",
                        units: "cm",
                        min: 0,
                        max: 255,
                        children: 0,
                        parent: false,
                        type: "num",
                        getter: function() { return proximitySensors.ProximitySensor2 },
                        setter: function(v) { proximitySensors.setProximitySensor2(v) }
                    },
                    {
                        name: "Sensor 3",
                        units: "cm",
                        min: 0,
                        max: 255,
                        children: 0,
                        parent: false,
                        type: "num",
                        getter: function() { return proximitySensors.ProximitySensor3 },
                        setter: function(v) { proximitySensors.setProximitySensor3(v) }
                    },
                    {
                        name: "Sensor 4",
                        units: "cm",
                        min: 0,
                        max: 255,
                        children: 0,
                        parent: false,
                        type: "num",
                        getter: function() { return proximitySensors.ProximitySensor4 },
                        setter: function(v) { proximitySensors.setProximitySensor4(v) }
                    }
                ]
            },
            {
                title: "Contactors",
                icon: "../images/ContactorsIcon.png",
                fields: [{name: "test"}]
            }
        ]
