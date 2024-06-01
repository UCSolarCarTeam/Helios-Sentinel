import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {
    width: 900
    height: 600

    Rectangle {
        id: mainContainer
        x: 0
        y: 0
        width: 900
        height: 600
        color: "#ffffff"
        radius: 25
        z: -2



        Text {
            id: text3
            x: 25
            y: 502
            text: qsTr("BYTE STREAM")
            font.pixelSize: 16
        }

        Text {
            id: text4
            x: 25
            y: 526
            text: qsTr("ENCODED")
            font.pixelSize: 16
        }
    }

    TabBar {
        id: tabBar
        x: 0
        y: 0
        width: 315
        height: 48

        TabButton {
            id: limitFlag
            x: 0
            y: 0
            width: 152
            height: 48
            text: qsTr("Limit Flags")
        }

        TabButton {
            id: errorFlag
            x: 158
            y: 0
            text: qsTr("Error Flags")
        }
    }

    StackLayout {
        id: stackLayout
        x: 4
        y: 49
        width: 892
        height: 357
        currentIndex: tabBar.currentIndex

        Rectangle {
            id: limitFlagContainer
            width: 850
            height: 325
            color: "#ffbf80"
            radius: 25
            z: -1

            Switch {
                id: switch22
                x: 43
                y: 49
                width: 274
                height: 32
                text: qsTr("DCL Reduced Due To Low SOC")
            }

            Switch {
                id: switch23
                x: 43
                y: 87
                width: 341
                height: 32
                text: qsTr("DCL Reduced Due To High Cell Resistance")
            }

            Switch {
                id: switch24
                x: 43
                y: 125
                width: 305
                height: 32
                text: qsTr("DCL Reduced Due To Temperature")
            }

            Switch {
                id: switch25
                x: 43
                y: 163
                width: 330
                height: 32
                text: qsTr("DCL Reduced Due To Low Cell Voltage")
            }

            Switch {
                id: switch30
                x: 43
                y: 201
                width: 330
                height: 32
                text: qsTr("DCL Reduced Due To Low Pack Voltage")
            }

            Switch {
                id: switch31
                x: 43
                y: 239
                width: 375
                height: 32
                text: qsTr("DCL and CCL Reduced Due to Voltage Failsafe")
            }

            Switch {
                id: switch32
                x: 43
                y: 277
                width: 422
                height: 32
                text: qsTr("DCL and CCL Reduced Due to Communication Failsafe")
            }

            Switch {
                id: switch33
                x: 449
                y: 49
                width: 281
                height: 32
                text: qsTr("CCL Reduced Due To High SOC")
            }

            Switch {
                id: switch26
                x: 449
                y: 87
                width: 341
                height: 32
                text: qsTr("CCL Reduced Due to High Cell Resistance")
            }

            Switch {
                id: switch27
                x: 449
                y: 125
                width: 298
                height: 32
                text: qsTr("CCL Reduced Due To Temperature")
            }

            Switch {
                id: switch28
                x: 449
                y: 163
                width: 330
                height: 32
                text: qsTr("CCL Reduced Due To High Cell Voltage")
            }

            Switch {
                id: switch29
                x: 449
                y: 201
                width: 330
                height: 32
                text: qsTr("CCL Reduced Due To High Pack Voltage")
            }

            Switch {
                id: switch34
                x: 449
                y: 239
                width: 307
                height: 32
                text: qsTr("CCL Reduced Due To Charger Latch")
            }

            Switch {
                id: switch35
                x: 449
                y: 277
                width: 401
                height: 32
                text: qsTr("CCL Reduced Due To Alternate Current Limit [MPI]")
            }
        }

        Rectangle {
            id: errorFlagContainer
            width: 775
            height: 325
            color: "#fff480"
            radius: 25
            z: -1



            Switch {
                id: switch2
                x: 39
                y: 90
                text: qsTr("Internal Conversion")
            }

            Switch {
                id: switch1
                x: 39
                y: 52
                text: qsTr("Internal Communication")
            }

            Switch {
                id: switch3
                x: 39
                y: 128
                text: qsTr("Weak Cell")
            }

            Switch {
                id: switch4
                x: 39
                y: 166
                text: qsTr("Low Cell Voltage")
            }

            Switch {
                id: switch5
                x: 39
                y: 204
                text: qsTr("Open Wiring")
            }

            Switch {
                id: switch6
                x: 39
                y: 242
                text: qsTr("Current Sensor")
            }

            Switch {
                id: switch7
                x: 39
                y: 280
                text: qsTr("Pack Voltage Sensor")
            }

            Switch {
                id: switch8
                x: 265
                y: 52
                text: qsTr("Weak Pack")
            }

            Switch {
                id: switch9
                x: 265
                y: 90
                width: 216
                height: 32
                text: qsTr("Voltage Redundancy")
            }

            Switch {
                id: switch10
                x: 265
                y: 128
                width: 172
                height: 32
                text: qsTr("Fan Monitor")
            }

            Switch {
                id: switch11
                x: 265
                y: 166
                text: qsTr("Thermistor")
            }

            Switch {
                id: switch12
                x: 265
                y: 204
                width: 244
                height: 32
                text: qsTr("CANBUS Communications")
            }

            Switch {
                id: switch13
                x: 265
                y: 242
                width: 205
                height: 32
                text: qsTr("Always-On Supply")
            }

            Switch {
                id: switch14
                x: 265
                y: 280
                width: 228
                height: 32
                text: qsTr("High Voltage Isolation")
            }

            Switch {
                id: switch15
                x: 497
                y: 52
                width: 198
                height: 32
                text: qsTr("12V Power Supply")
            }

            Switch {
                id: switch16
                x: 497
                y: 90
                width: 249
                height: 32
                text: qsTr("Charge Limit Enforcement")
            }

            Switch {
                id: switch17
                x: 497
                y: 128
                width: 264
                height: 32
                text: qsTr("Discharge Limit Enforcement")
            }

            Switch {
                id: switch18
                x: 497
                y: 166
                width: 228
                height: 32
                text: qsTr("Charger Safety Relay")
            }

            Switch {
                id: switch19
                x: 497
                y: 204
                width: 244
                height: 32
                text: qsTr("Internal Memory")
            }

            Switch {
                id: switch20
                x: 497
                y: 242
                width: 205
                height: 32
                text: qsTr("Internal Thermistor")
            }

            Switch {
                id: switch21
                x: 497
                y: 280
                width: 228
                height: 32
                text: qsTr("Internal Logic")
            }
        }
    }

}
