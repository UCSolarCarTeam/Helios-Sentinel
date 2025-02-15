import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."

Item {
    property var mppt : mpptElysia0
    width: 550
    height: 475

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "MPPT Packet"
            font.family: "Verdana"
            font.bold: true
        }

        ComboBox {
            id: mpptSelector
            width: 150
            model: ["MPPT 0", "MPPT 1", "MPPT 2", "MPPT 3"]
            onCurrentIndexChanged: {
                mppt = currentIndex === 0 ? mpptElysia0 : currentIndex === 1 ? mpptElysia1 : currentIndex === 2 ? mpptElysia2 : mpptElysia3
            }
        }

        Column{
            spacing: 20

            Switch {
                id: switch1
                text: qsTr("Is Alive")
                checked: mppt.Alive
                onClicked: mppt.setAlive(checked)
            }

            IntSpinBox {
                id: box1
                text: qsTr("Array Voltage")
                value: mppt.ArrayVoltage
                onValueChanged: mppt.setArrayVoltage(value)
            }

            IntSpinBox {
                id: box2
                text: qsTr("Array Current")
                value: mppt.ArrayCurrent
                onValueChanged: mppt.setArrayCurrent(value)
            }

            IntSpinBox {
                id: box3
                text: qsTr("Battery Voltage")
                value: mppt.BatteryVoltage
                onValueChanged: mppt.setBatteryVoltage(value)
            }

            IntSpinBox {
                id: box4
                text: qsTr("Temperature")
                value: mppt.Temp
                onValueChanged: mppt.setTemp(value)
            }
        }

        BytePreview {
            id: bytePreview
            raw: mppt.byteStreamStr
            encoded: mppt.encodedByteStreamStr
        }
    }
}
