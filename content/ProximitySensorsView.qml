import QtQuick 2.15
import QtQuick.Controls 6.2
import QtQuick.Studio.Components 1.0

Item {
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 351
        height: 389
        color: "#e16060"

        GroupItem {
            x: 120
            y: 224

            SpinBox {
                id: spinBox
                x: -102
                y: -207
                from: 0
                to: 255
                value: proximitySensors.proximitySensor1
                onValueChanged: proximitySensors.setProximitySensor1(value)
            }

            Text {
                id: text1
                x: 61
                y: -187
                text: qsTr("Proximity Sensor 1")
                font.pixelSize: 14
            }
        }

        GroupItem {
            x: 120
            y: 298
            SpinBox {
                x: -102
                y: -207
                from: 0
                to: 255
                value: proximitySensors.proximitySensor1
                onValueChanged: proximitySensors.setProximitySensor2(value)
            }

            Text {
                x: 61
                y: -187
                text: qsTr("Proximity Sensor 2")
                font.pixelSize: 14
            }
        }

        GroupItem {
            x: 120
            y: 375
            SpinBox {
                x: -102
                y: -207
                from: 0
                to: 255
                value: proximitySensors.proximitySensor3
                onValueChanged: proximitySensors.setProximitySensor3(value)
            }

            Text {
                x: 61
                y: -187
                text: qsTr("Proximity Sensor 3")
                font.pixelSize: 14
            }
        }

        GroupItem {
            x: 120
            y: 444
            SpinBox {
                x: -102
                y: -207
                from: 0
                to: 255
                value: proximitySensors.proximitySensor4
                onValueChanged: proximitySensors.setProximitySensor4(value)
            }

            Text {
                x: 61
                y: -187
                text: qsTr("Proximity Sensor 4")
                font.pixelSize: 14
            }
        }

        Text {
            id: text2
            x: 15
            y: 320
            text: qsTr("Byte Stream: " + proximitySensors.byteStreamStr)
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 16
            y: 351
            text: qsTr("Encoded Byte Stream: " + proximitySensors.encodedByteStreamStr)
            font.pixelSize: 12
        }
    }

}
