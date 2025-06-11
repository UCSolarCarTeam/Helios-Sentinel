import QtQuick 2.15
import QtQuick.Controls 6.2

import "../Components"

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
                    value: telemetry.Month
                    onValueChanged: telemetry.setMonth(value)
                    min: 0
                    max: 12
                }

                IntSpinBox {
                    id: gpsDay
                    text: qsTr("GPS Day")
                    value: telemetry.Day
                    onValueChanged: telemetry.setDay(value)
                    min: 0
                    max: 31
                }

                IntSpinBox {
                    id: gpsHour
                    text: qsTr("GPS Hour")
                    value: telemetry.Hour
                    onValueChanged: telemetry.setHour(value)
                    min: 0
                    max: 23
                }

                IntSpinBox {
                    id: gpsMinute
                    text: qsTr("GPS Minute")
                    value: telemetry.Minute
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setMinute(value)
                    min: 0
                    max: 59
                }

                IntSpinBox {
                    id: gpsSecond
                    text: qsTr("GPS Second")
                    value: telemetry.Second
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setSecond(value)
                    min: 0
                    max: 59
                }

                IntSpinBox {
                    id: validityFlags
                    text: qsTr("Validity Flags")
                    value: telemetry.ValidityFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setValidityFlags(value)
                    min: 0
                    max: 255
                }

                IntSpinBox {
                    id: fixStatusFlags
                    text: qsTr("Fix Status Flags")
                    value: telemetry.FixStatusFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setFixStatusFlags(value)
                    min: 0
                    max: 255
                }

                IntSpinBox {
                    id: additionalFlags
                    text: qsTr("Additional Flags")
                    value: telemetry.AdditionalFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setAdditionalFlags(value)
                    min: 0
                    max: 255
                }
            }

            Column {
                id: column
                spacing: 20
                width: 245

                FloatSpinBox {
                    id: longitude
                    text: qsTr("Longitude")
                    decimals: 6;
                    inputValue: telemetry.Longitude
                    onInputValueUpdated: telemetry.setLongitude(inputValue)
                    min: -180
                    max: 180
                }

                FloatSpinBox {
                    id: latitude
                    text: qsTr("Latitude")
                    decimals: 6;
                    inputValue: telemetry.Latitude
                    onInputValueUpdated: telemetry.setLatitude(inputValue)
                    min: -90
                    max: 90
                }

                IntSpinBox {
                    id: mpuTemperature
                    text: qsTr("MPU Temperature")
                    value: telemetry.MpuTemperature
                    onValueChanged: telemetry.setMpuTemperature(value)
                    min: -32768
                    max: 32767
                }

                IntSpinBox {
                    id: mpueAccelerationX
                    text: qsTr("MPU Acceleration X")
                    value: telemetry.AccelerationX
                    onValueChanged: telemetry.setAccelerationX(value)
                    min: -32768
                    max: 32767
                }

                IntSpinBox {
                    id: mpueAccelerationY
                    text: qsTr("MPU Acceleration Y")
                    value: telemetry.AccelerationY
                    onValueChanged: telemetry.setAccelerationY(value)
                    min: -32768
                    max: 32767
                }

                IntSpinBox {
                    id: mpueAccelerationZ
                    text: qsTr("MPU Acceleration Z")
                    value: telemetry.AccelerationZ
                    onValueChanged: telemetry.setAccelerationZ(value)
                    min: -32768
                    max: 32767
                }

                IntSpinBox {
                    id: mpuRotationX
                    text: qsTr("MPU Rotation X")
                    value: telemetry.RotationX
                    onValueChanged: telemetry.setRotationX(value)
                    min: -32768
                    max: 32767
                }

                IntSpinBox {
                    id: mpuRotationY
                    text: qsTr("MPU Rotation Y")
                    value: telemetry.RotationY
                    onValueChanged: telemetry.setRotationY(value)
                    min: -32768
                    max: 32767
                }

                IntSpinBox {
                    id: mpuRotationZ
                    text: qsTr("MPU Rotation Z")
                    value: telemetry.RotationZ
                    onValueChanged: telemetry.setRotationZ(value)
                    min: -32768
                    max: 32767
                }
            }
        }
    }
}
