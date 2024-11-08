import QtQuick 2.15
import QtQuick.Controls 6.2
import QtQuick.Studio.Components 1.0

Item {
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 529
        height: 718
        color: "#e683d4"

        GroupItem {
            x: 26
            y: 22

            SpinBox {
                id: spinBoxYear
                x: 0
                y: 0
                from: 0
                to: 2200
                value: telemetry.gpsYear
                onValueChanged: telemetry.setGpsYear(value)
            }

            Text {
                id: text1
                x: 44
                y: 62
                text: qsTr("GPS Year")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 184
            y: 22
            SpinBox {
                id: spinBoxMonth
                x: 0
                y: 0
                from: 0
                to: 12
                value: telemetry.gpsMonth
                onValueChanged: telemetry.setGpsMonth(value)
            }

            Text {
                x: 44
                y: 62
                text: qsTr("GPS Month")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 353
            y: 22
            SpinBox {
                id: spinBoxDay
                x: 0
                y: 0
                from: 0
                to: 31
                value: telemetry.gpsDay
                onValueChanged: telemetry.setGpsDay(value)
            }

            Text {
                x: 44
                y: 62
                text: qsTr("GPS Day")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 23
            y: 126
            SpinBox {
                id: spinBoxHour
                x: 0
                y: 0
                from: 0
                to: 24
                value: telemetry.gpsHour
                onValueChanged: telemetry.setGpsHour(value)
            }

            Text {
                x: 44
                y: 62
                text: qsTr("GPS Hour")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 184
            y: 126
            SpinBox {
                id: spinBoxMinute
                x: 0
                y: 0
                from: 0
                to: 60
                value: telemetry.gpsMinute
                onValueChanged: telemetry.setGpsMinute(value)
            }

            Text {
                x: 44
                y: 62
                text: qsTr("GPS Minute")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 353
            y: 126
            SpinBox {
                id: spinBoxSecond
                x: 0
                y: 0
                from: 0
                to: 60
                value: telemetry.gpsSecond
                onValueChanged: telemetry.setGpsSecond(value)
            }

            Text {
                x: 44
                y: 62
                text: qsTr("GPS Second")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 23
            y: 231
            SpinBox {
                id: spinBoxValidityFlags
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.gpsValidityFlags
                onValueChanged: telemetry.setGpsValidityFlags(value)
            }

            Text {
                x: 33
                y: 62
                text: qsTr("Validity Flags")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 184
            y: 231
            SpinBox {
                id: spinBoxFixStatusFlags
                x: 0
                y: 0
                from: 0
                to: 60
                value: telemetry.gpsFixStatusFlags
                onValueChanged: telemetry.setGpsFixStatusFlags(value)
            }

            Text {
                x: 25
                y: 62
                text: qsTr("Fix Status Flags")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 353
            y: 231
            SpinBox {
                id: spinBoxAdditionalFlags
                x: 0
                y: 0
                from: 0
                to: 60
                value: telemetry.gpsAdditionalFlags
                onValueChanged: telemetry.setGpsAdditionalFlags(value)
            }

            Text {
                x: 25
                y: 62
                text: qsTr("Additional Flags")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 26
            y: 334
            SpinBox {
                id: spinBoxLongitude
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.gpsLongitude
                onValueChanged: telemetry.setGpsLongitude(value)
            }

            Text {
                x: 42
                y: 62
                text: qsTr("Longitude")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 187
            y: 334
            SpinBox {
                id: spinBoxLatitude
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.gpsLatitude
                onValueChanged: telemetry.setGpsLatitude(value)
            }

            Text {
                x: 47
                y: 62
                text: qsTr("Latitude")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 356
            y: 334
            SpinBox {
                id: spinBoxTemperature
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.mpuTemperature
                onValueChanged: telemetry.setMpuTemperature(value)
            }

            Text {
                x: 25
                y: 62
                text: qsTr("MPU Temperature")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 23
            y: 437
            SpinBox {
                id: spinBoxAccelX
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.mpuAccelerationX
                onValueChanged: telemetry.setMpuAccelerationX(value)
            }

            Text {
                x: 17
                y: 62
                text: qsTr("MPU Acceleration X")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 184
            y: 437
            SpinBox {
                id: spinBoxAccelY
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.mpuAccelerationY
                onValueChanged: telemetry.setMpuAccelerationY(value)
            }

            Text {
                x: 14
                y: 62
                text: qsTr("MPU Acceleration Y")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 353
            y: 437
            SpinBox {
                id: spinBoxAccelZ
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.mpuAccelerationZ
                onValueChanged: telemetry.setMpuAccelerationZ(value)
            }

            Text {
                x: 14
                y: 62
                text: qsTr("MPU Acceleration Z")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 23
            y: 544
            SpinBox {
                id: spinBoxRotationX
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.mpuRotationX
                onValueChanged: telemetry.setMpuRotationX(value)
            }

            Text {
                x: 26
                y: 62
                text: qsTr("MPU Rotation X")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 184
            y: 544
            SpinBox {
                id: spinBoxRotationY
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.mpuRotationY
                onValueChanged: telemetry.setMpuRotationY(value)
            }

            Text {
                x: 26
                y: 62
                text: qsTr("MPU Rotation Y")
                font.pixelSize: 12
            }
        }

        GroupItem {
            x: 353
            y: 544
            SpinBox {
                id: spinBoxRotationZ
                x: 0
                y: 0
                from: 0
                to: 255
                value: telemetry.mpuRotationZ
                onValueChanged: telemetry.setMpuRotationZ(value)
            }

            Text {
                x: 26
                y: 62
                text: qsTr("MPU Rotation Z")
                font.pixelSize: 12
            }
        }
        Text {
            id: text2
            x: 23
            y: 644
            text: qsTr("Byte Stream: " + telemetry.byteStreamStr)
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 23
            y: 665
            text: qsTr("Encoded Byte Stream: " + telemetry.encodedByteStreamStr)
            font.pixelSize: 12
        }
    }
}
