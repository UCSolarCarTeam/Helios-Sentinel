import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    Switch {
        id: switch1
        x: 60
        y: 87
        text: qsTr("Internal Communication")
    }

    Switch {
        id: switch2
        x: 60
        y: 125
        text: qsTr("Internal Conversion")
    }

    Switch {
        id: switch3
        x: 60
        y: 163
        text: qsTr("Weak Cell")
    }

    Switch {
        id: switch4
        x: 60
        y: 201
        text: qsTr("Low Cell Voltage")
    }

    Switch {
        id: switch5
        x: 60
        y: 239
        text: qsTr("Open Wiring")
    }

    Switch {
        id: switch6
        x: 60
        y: 277
        text: qsTr("Current Sensor")
    }

    Switch {
        id: switch7
        x: 60
        y: 315
        text: qsTr("Pack Voltage Sensor")
    }

    Switch {
        id: switch8
        x: 286
        y: 87
        text: qsTr("Weak Pack")
    }

    Switch {
        id: switch9
        x: 286
        y: 125
        width: 216
        height: 32
        text: qsTr("Voltage Redundancy")
    }

    Switch {
        id: switch10
        x: 286
        y: 163
        width: 172
        height: 32
        text: qsTr("Fan Monitor")
    }

    Switch {
        id: switch11
        x: 286
        y: 201
        text: qsTr("Thermistor")
    }

    Switch {
        id: switch12
        x: 286
        y: 239
        width: 244
        height: 32
        text: qsTr("CANBUS Communications")
    }

    Switch {
        id: switch13
        x: 286
        y: 277
        width: 205
        height: 32
        text: qsTr("Always-On Supply")
    }

    Switch {
        id: switch14
        x: 286
        y: 315
        width: 228
        height: 32
        text: qsTr("High Voltage Isolation")
    }

    Switch {
        id: switch15
        x: 518
        y: 87
        width: 198
        height: 32
        text: qsTr("12V Power Supply")
    }

    Switch {
        id: switch16
        x: 518
        y: 125
        width: 249
        height: 32
        text: qsTr("Charge Limit Enforcement")
    }

    Switch {
        id: switch17
        x: 518
        y: 163
        width: 264
        height: 32
        text: qsTr("Discharge Limit Enforcement")
    }

    Switch {
        id: switch18
        x: 518
        y: 201
        width: 228
        height: 32
        text: qsTr("Charger Safety Relay")
    }

    Switch {
        id: switch19
        x: 518
        y: 239
        width: 244
        height: 32
        text: qsTr("Internal Memory")
    }

    Switch {
        id: switch20
        x: 518
        y: 277
        width: 205
        height: 32
        text: qsTr("Internal Thermistor")
    }

    Switch {
        id: switch21
        x: 518
        y: 315
        width: 228
        height: 32
        text: qsTr("Internal Logic")
    }

    Switch {
        id: switch22
        x: 61
        y: 419
        width: 274
        height: 32
        text: qsTr("DCL Reduced Due To Low SOC")
    }

    Switch {
        id: switch23
        x: 61
        y: 457
        width: 341
        height: 32
        text: qsTr("DCL Reduced Due To High Cell Resistance")
    }

    Switch {
        id: switch24
        x: 61
        y: 495
        width: 305
        height: 32
        text: qsTr("DCL Reduced Due To Temperature")
    }

    Switch {
        id: switch25
        x: 61
        y: 533
        width: 330
        height: 32
        text: qsTr("DCL Reduced Due To Low Cell Voltage")
    }

    Switch {
        id: switch30
        x: 61
        y: 571
        width: 330
        height: 32
        text: qsTr("DCL Reduced Due To Low Pack Voltage")
    }

    Switch {
        id: switch31
        x: 61
        y: 609
        width: 375
        height: 32
        text: qsTr("DCL and CCL Reduced Due to Voltage Failsafe")
    }

    Switch {
        id: switch32
        x: 61
        y: 647
        width: 422
        height: 32
        text: qsTr("DCL and CCL Reduced Due to Communication Failsafe")
    }

    Switch {
        id: switch33
        x: 467
        y: 419
        width: 281
        height: 32
        text: qsTr("CCL Reduced Due To High SOC")
    }

    Switch {
        id: switch26
        x: 467
        y: 457
        width: 341
        height: 32
        text: qsTr("CCL Reduced Due to High Cell Resistance")
    }

    Switch {
        id: switch27
        x: 467
        y: 495
        width: 298
        height: 32
        text: qsTr("CCL Reduced Due To Temperature")
    }

    Switch {
        id: switch28
        x: 467
        y: 533
        width: 330
        height: 32
        text: qsTr("CCL Reduced Due To High Cell Voltage")
    }

    Switch {
        id: switch29
        x: 467
        y: 571
        width: 330
        height: 32
        text: qsTr("CCL Reduced Due To High Pack Voltage")
    }

    Switch {
        id: switch34
        x: 467
        y: 609
        width: 307
        height: 32
        text: qsTr("CCL Reduced Due To Charger Latch")
    }

    Switch {
        id: switch35
        x: 467
        y: 647
        width: 401
        height: 32
        text: qsTr("CCL Reduced Due To Alternate Current Limit [MPI]")
    }

    Rectangle {
        id: rectangle
        x: 18
        y: 370
        width: 850
        height: 325
        color: "#ffbf80"
        radius: 25
        z: -1
    }

    Text {
        id: text1
        x: 83
        y: 390
        text: qsTr("Limit Flags")
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle1
        x: 21
        y: 35
        width: 775
        height: 325
        color: "#fff480"
        radius: 25
        z: -1
    }

    Text {
        id: text2
        x: 71
        y: 58
        text: qsTr("Error Flags")
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle2
        x: 0
        y: 0
        width: 900
        height: 775
        color: "#ff0000"
        radius: 25
        z: -2
    }

    Text {
        id: text3
        x: 27
        y: 709
        text: qsTr("BYTE STREAM")
        font.pixelSize: 16
    }

    Text {
        id: text4
        x: 27
        y: 733
        text: qsTr("ENCODED")
        font.pixelSize: 16
    }

    Text {
        id: text5
        x: 27
        y: 15
        text: qsTr("Battery Faults")
        font.pixelSize: 12
    }
}
