import QtQuick 2.15
import QtQuick.Controls 2.15

import "../Components"

Item {
    width: 550
    height: 1250

    property var mppt: mpptSelector.currentIndex === 0 ? mppt0C0 : 
                        mpptSelector.currentIndex === 1 ? mppt0C1 : 
                        mpptSelector.currentIndex === 2 ? mppt1C0 : 
                        mpptSelector.currentIndex === 3 ? mppt1C1 : 
                        mpptSelector.currentIndex === 4 ? mppt2C0 : 
                        mpptSelector.currentIndex === 5 ? mppt2C1 : 
                        mpptSelector.currentIndex === 6 ? mppt3C0 : 
                        mppt3C1

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
            model: ["Mppt 0C0", "Mppt 0C1", "Mppt 1C0", "Mppt 1C1", "Mppt 2C0", "Mppt 2C1", "Mppt 3C0", "Mppt 3C1"]
            currentIndex: 0
            width: 150
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.ArrayVoltage
                    onValueChanged: mppt.setArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.ArrayCurrent
                    onValueChanged: mppt.setArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.BatteryVoltage
                    onValueChanged: mppt.setBatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.Temperature
                    onValueChanged: mppt.setTemperature(value) 
                }
            }
        }
    }
}
