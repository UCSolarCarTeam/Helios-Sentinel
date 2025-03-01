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
                    value: telemetry.GpsYear
                    onValueChanged: telemetry.setGpsYear(value)
                }

                IntSpinBox {
                    id: gpsMonth
                    text: qsTr("GPS Month")
                    range: { "from": 0, "to": 12 }
                    value: telemetry.GpsMonth
                    onValueChanged: telemetry.setGpsMonth(value)
                }

                IntSpinBox {
                    id: gpsDay
                    text: qsTr("GPS Day")
                    range: { "from": 0, "to": 31 }
                    value: telemetry.GpsDay
                    onValueChanged: telemetry.setGpsDay(value)
                }

                IntSpinBox {
                    id: gpsHour
                    text: qsTr("GPS Hour")
                    range: { "from": 0, "to": 23 }
                    value: telemetry.GpsHour
                    onValueChanged: telemetry.setGpsHour(value)
                }

                IntSpinBox {
                    id: gpsMinute
                    text: qsTr("GPS Minute")
                    range: { "from": 0, "to": 59 }
                    value: telemetry.GpsMinute
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsMinute(value)
                }

                IntSpinBox {
                    id: gpsSecond
                    text: qsTr("GPS Second")
                    range: { "from": 0, "to": 59 }
                    value: telemetry.GpsSecond
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsSecond(value)
                }

                IntSpinBox {
                    id: validityFlags
                    text: qsTr("Validity Flags")
                    range: { "from": 0, "to": 255 }
                    value: telemetry.GpsValidityFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsValidityFlags(value)
                }

                IntSpinBox {
                    id: fixStatusFlags
                    text: qsTr("Fix Status Flags")
                    range: { "from": 0, "to": 255 }
                    value: telemetry.GpsFixStatusFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsFixStatusFlags(value)
                }

                IntSpinBox {
                    id: additionalFlags
                    text: qsTr("Additional Flags")
                    range: { "from": 0, "to": 255 }
                    value: telemetry.GpsAdditionalFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsAdditionalFlags(value)
                }
            }

            Column {
                id: column
                spacing: 20
                width: 245

                FloatSpinBox {
                    id: longitude
                    text: qsTr("Longitude")
                    inputValue: telemetry.GpsLongitude
                    onInputValueUpdated: telemetry.setGpsLongitude(inputValue)
                }

                FloatSpinBox {
                    id: latitude
                    text: qsTr("Latitude")
                    inputValue: telemetry.GpsLatitude
                    onInputValueUpdated: telemetry.setGpsLatitude(inputValue)
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
                    value: telemetry.MpuAccelerationX
                    onValueChanged: telemetry.setMpuAccelerationX(value)
                }

                IntSpinBox {
                    id: mpueAccelerationY
                    text: qsTr("MPU Acceleration Y")
                    value: telemetry.MpuAccelerationY
                    onValueChanged: telemetry.setMpuAccelerationY(value)
                }

                IntSpinBox {
                    id: mpueAccelerationZ
                    text: qsTr("MPU Acceleration Z")
                    value: telemetry.MpuAccelerationZ
                    onValueChanged: telemetry.setMpuAccelerationZ(value)
                }

                IntSpinBox {
                    id: mpuRotationX
                    text: qsTr("MPU Rotation X")
                    value: telemetry.MpuRotationX
                    onValueChanged: telemetry.setMpuRotationX(value)
                }

                IntSpinBox {
                    id: mpuRotationY
                    text: qsTr("MPU Rotation Y")
                    value: telemetry.MpuRotationY
                    onValueChanged: telemetry.setMpuRotationY(value)
                }

                IntSpinBox {
                    id: mpuRotationZ
                    text: qsTr("MPU Rotation Z")
                    value: telemetry.MpuRotationZ
                    onValueChanged: telemetry.setMpuRotationZ(value)
                }
            }
        }

        BytePreview {
            id: bytePreview
            raw: telemetry.byteStreamStr
            encoded: telemetry.encodedByteStreamStr
        }
    }
}
