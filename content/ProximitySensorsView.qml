import QtQuick 2.15
import QtQuick.Controls 6.2
import QtQuick.Studio.Components 1.0

Item {
    width: 550
    height: 350

    Column {
            anchors.fill: parent
            anchors.margins: 10
            spacing: 20

            Text {
                text: "Proximity Sensors Packet"
                font.family: "Verdana"
                font.bold: true
            }

            Column {
                spacing: 20

                IntSpinBox {
                    id: proximitySensor1
                    text: qsTr("Proximity Sensor 1")
                    value: proximitySensors.proximitySensor1
                    onValueChanged: proximitySensors.setProximitySensor1(value)
                }

                IntSpinBox {
                    id: proximitySensor2
                    text: qsTr("Proximity Sensor 2")
                    value: proximitySensors.proximitySensor2
                    onValueChanged: proximitySensors.setProximitySensor2(value)
                }

                IntSpinBox {
                    id: proximitySensor3
                    text: qsTr("Proximity Sensor 3")
                    value: proximitySensors.proximitySensor3
                    onValueChanged: proximitySensors.setProximitySensor3(value)
                }

                IntSpinBox {
                    id: proximitySensor4
                    text: qsTr("Proximity Sensor 4")
                    value: proximitySensors.proximitySensor4
                    onValueChanged: proximitySensors.setProximitySensor4(value)
                }
            }

            BytePreview {
                id: bytePreview
                raw: proximitySensors.byteStreamStr
                encoded: proximitySensors.encodedByteStreamStr
            }
        }
}
