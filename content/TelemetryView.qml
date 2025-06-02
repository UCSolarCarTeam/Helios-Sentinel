import QtQuick 2.15
import QtQuick.Controls 6.2
import QtQuick.Studio.Components 1.0

Item {
    width: 550
    height: 575

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Telemetry Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                id: column1
                spacing: 20
                width: 245

                IntSpinBox {
                    id: gpsYear
                    text: qsTr("GPS Year")
                    value: telemetry.Year
                    onValueChanged: telemetry.setYear(value)
                }

                IntSpinBox {
                    id: gpsMonth
                    text: qsTr("GPS Month")
                    range: { "from": 0, "to": 12 }
                    value: telemetry.Month
                    onValueChanged: telemetry.setMonth(value)
                }

                IntSpinBox {
                    id: gpsDay
                    text: qsTr("GPS Day")
                    range: { "from": 0, "to": 31 }
                    value: telemetry.Day
                    onValueChanged: telemetry.setDay(value)
                }

                IntSpinBox {
                    id: gpsHour
                    text: qsTr("GPS Hour")
                    range: { "from": 0, "to": 23 }
                    value: telemetry.Hour
                    onValueChanged: telemetry.setHour(value)
                }

                IntSpinBox {
                    id: gpsMinute
                    text: qsTr("GPS Minute")
                    range: { "from": 0, "to": 59 }
                    value: telemetry.Minute
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setMinute(value)
                }

                IntSpinBox {
                    id: gpsSecond
                    text: qsTr("GPS Second")
                    range: { "from": 0, "to": 59 }
                    value: telemetry.Second
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setSecond(value)
                }

                IntSpinBox {
                    id: validityFlags
                    text: qsTr("Validity Flags")
                    range: { "from": 0, "to": 255 }
                    value: telemetry.ValidityFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setValidityFlags(value)
                }

                IntSpinBox {
                    id: fixStatusFlags
                    text: qsTr("Fix Status Flags")
                    range: { "from": 0, "to": 255 }
                    value: telemetry.FixStatusFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setFixStatusFlags(value)
                }

                IntSpinBox {
                    id: additionalFlags
                    text: qsTr("Additional Flags")
                    range: { "from": 0, "to": 255 }
                    value: telemetry.AdditionalFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setAdditionalFlags(value)
                }
            }

            Column {
                id: column
                spacing: 20
                width: 245

                FloatSpinBox {
                    id: longitude
                    text: qsTr("Longitude")
                    range: { "from": -180, "to": 180 }
                    decimals: 6;
                    inputValue: telemetry.Longitude
                    onInputValueUpdated: telemetry.setLongitude(inputValue)
                }

                FloatSpinBox {
                    id: latitude
                    text: qsTr("Latitude")
                    range: { "from": -90, "to": 90 }
                    decimals: 6;
                    inputValue: telemetry.Latitude
                    onInputValueUpdated: telemetry.setLatitude(inputValue)
                }

                IntSpinBox {
                    id: mpuTemperature
                    text: qsTr("MPU Temperature")
                    value: telemetry.MpuTemperature
                    onValueChanged: telemetry.setMpuTemperature(value)
                }

                IntSpinBox {
                    id: mpueAccelerationX
                    text: qsTr("MPU Acceleration X")
                    value: telemetry.AccelerationX
                    onValueChanged: telemetry.setAccelerationX(value)
                }

                IntSpinBox {
                    id: mpueAccelerationY
                    text: qsTr("MPU Acceleration Y")
                    value: telemetry.AccelerationY
                    onValueChanged: telemetry.setAccelerationY(value)
                }

                IntSpinBox {
                    id: mpueAccelerationZ
                    text: qsTr("MPU Acceleration Z")
                    value: telemetry.AccelerationZ
                    onValueChanged: telemetry.setAccelerationZ(value)
                }

                IntSpinBox {
                    id: mpuRotationX
                    text: qsTr("MPU Rotation X")
                    value: telemetry.RotationX
                    onValueChanged: telemetry.setRotationX(value)
                }

                IntSpinBox {
                    id: mpuRotationY
                    text: qsTr("MPU Rotation Y")
                    value: telemetry.RotationY
                    onValueChanged: telemetry.setRotationY(value)
                }

                IntSpinBox {
                    id: mpuRotationZ
                    text: qsTr("MPU Rotation Z")
                    value: telemetry.RotationZ
                    onValueChanged: telemetry.setRotationZ(value)
                }
            }
        // }

        // BytePreview {
        //     id: bytePreview
        //     raw: telemetry.byteStreamStr
        //     encoded: telemetry.encodedByteStreamStr
        // }
        }
    }
}
