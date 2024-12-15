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
                    id: proximitySensor1
                    text: qsTr("GPS Year")
                    value: telemetry.gpsYear
                    onValueChanged: telemetry.setGpsYear(value)
                }

                IntSpinBox {
                    id: proximitySensor2
                    text: qsTr("GPS Month")
                    value: telemetry.gpsMonth
                    onValueChanged: telemetry.setGpsMonth(value)
                }

                IntSpinBox {
                    id: proximitySensor3
                    text: qsTr("GPS Day")
                    value: telemetry.gpsDay
                    onValueChanged: telemetry.setGpsDay(value)
                }

                IntSpinBox {
                    id: proximitySensor4
                    text: qsTr("GPS Hour")
                    value: telemetry.gpsHour
                    onValueChanged: telemetry.setGpsHour(value)
                }

                IntSpinBox {
                    id: proximitySensor5
                    text: qsTr("GPS Minute")
                    value: telemetry.gpsMinute
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsMinute(value)
                }

                IntSpinBox {
                    id: proximitySensor6
                    text: qsTr("GPS Second")
                    value: telemetry.gpsSecond
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsSecond(value)
                }

                IntSpinBox {
                    id: proximitySensor7
                    text: qsTr("Validity Flags")
                    value: telemetry.gpsValidityFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsValidityFlags(value)
                }

                IntSpinBox {
                    id: proximitySensor8
                    text: qsTr("Fix Status Flags")
                    value: telemetry.gpsFixStatusFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsFixStatusFlags(value)
                }

                IntSpinBox {
                    id: proximitySensor9
                    text: qsTr("Additional Flags")
                    value: telemetry.gpsAdditionalFlags
                    anchors.rightMargin: 0
                    onValueChanged: telemetry.setGpsAdditionalFlags(value)
                }
            }

            Column {
                id: column
                spacing: 20
                width: 245

                IntSpinBox {
                    id: proximitySensor10
                    text: qsTr("Longitude")
                    value: telemetry.gpsLongitude
                    onValueChanged: telemetry.setGpsLongitude(value)
                }

                IntSpinBox {
                    id: proximitySensor11
                    text: qsTr("Latitude")
                    value: telemetry.gpsLatitude
                    onValueChanged: telemetry.setGpsLatitude(value)
                }

                IntSpinBox {
                    id: proximitySensor12
                    text: qsTr("MPU Temperature")
                    value: telemetry.mpuTemperature
                    onValueChanged: telemetry.setMpuTemperature(value)
                }

                IntSpinBox {
                    id: proximitySensor13
                    text: qsTr("MPU Acceleration X")
                    value: telemetry.mpuAccelerationX
                    onValueChanged: telemetry.setMpuAccelerationX(value)
                }

                IntSpinBox {
                    id: proximitySensor14
                    text: qsTr("MPU Acceleration Y")
                    value: telemetry.mpuAccelerationY
                    onValueChanged: telemetry.setMpuAccelerationY(value)
                }

                IntSpinBox {
                    id: proximitySensor15
                    text: qsTr("MPU Acceleration Z")
                    value: telemetry.mpuAccelerationZ
                    onValueChanged: telemetry.setMpuAccelerationZ(value)
                }

                IntSpinBox {
                    id: proximitySensor16
                    text: qsTr("MPU Rotation X")
                    value: telemetry.mpuRotationX
                    onValueChanged: telemetry.setMpuRotationX(value)
                }

                IntSpinBox {
                    id: proximitySensor17
                    text: qsTr("MPU Rotation Y")
                    value: telemetry.mpuRotationY
                    onValueChanged: telemetry.setMpuRotationY(value)
                }

                IntSpinBox {
                    id: proximitySensor18
                    text: qsTr("MPU Rotation Z")
                    value: telemetry.mpuRotationZ
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
