import QtQuick 2.15
import QtQuick.Controls 2.15

import "../Components"

Item {
    width: 550
    height: 1250

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "MPPT Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Text {
            text: "MPPT 0 Channel 0"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M0C0ArrayVoltage
                    onValueChanged: mppt.setM0C0ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M0C0ArrayCurrent
                    onValueChanged: mppt.setM0C0ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M0C0BatteryVoltage
                    onValueChanged: mppt.setM0C0BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M0C0Temperature
                    onValueChanged: mppt.setM0C0Temperature(value) 
                }
            }
        }

        Text {
            text: "MPPT 0 Channel 1"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M0C1ArrayVoltage
                    onValueChanged: mppt.setM0C1ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M0C1ArrayCurrent
                    onValueChanged: mppt.setM0C1ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M0C1BatteryVoltage
                    onValueChanged: mppt.setM0C1BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M0C1Temperature
                    onValueChanged: mppt.setM0C1Temperature(value) 
                }
            }
        }

        Text {
            text: "MPPT 1 Channel 0"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M1C0ArrayVoltage
                    onValueChanged: mppt.setM1C0ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M1C0ArrayCurrent
                    onValueChanged: mppt.setM1C0ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M1C0BatteryVoltage
                    onValueChanged: mppt.setM1C0BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M1C0Temperature
                    onValueChanged: mppt.setM1C0Temperature(value) 
                }
            }
        }

        Text {
            text: "MPPT 1 Channel 1"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M1C1ArrayVoltage
                    onValueChanged: mppt.setM1C1ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M1C1ArrayCurrent
                    onValueChanged: mppt.setM1C1ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M1C1BatteryVoltage
                    onValueChanged: mppt.setM1C1BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M1C1Temperature
                    onValueChanged: mppt.setM1C1Temperature(value) 
                }
            }
        }

        Text {
            text: "MPPT 2 Channel 0"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M2C0ArrayVoltage
                    onValueChanged: mppt.setM2C0ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M2C0ArrayCurrent
                    onValueChanged: mppt.setM2C0ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M2C0BatteryVoltage
                    onValueChanged: mppt.setM2C0BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M2C0Temperature
                    onValueChanged: mppt.setM2C0Temperature(value) 
                }
            }
        }

        Text {
            text: "MPPT 2 Channel 1"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M2C1ArrayVoltage
                    onValueChanged: mppt.setM2C1ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M2C1ArrayCurrent
                    onValueChanged: mppt.setM2C1ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M2C1BatteryVoltage
                    onValueChanged: mppt.setM2C1BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M2C1Temperature
                    onValueChanged: mppt.setM2C1Temperature(value) 
                }
            }
        }

        Text {
            text: "MPPT 3 Channel 0"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M3C0ArrayVoltage
                    onValueChanged: mppt.setM3C0ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M3C0ArrayCurrent
                    onValueChanged: mppt.setM3C0ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M3C0BatteryVoltage
                    onValueChanged: mppt.setM3C0BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M3C0Temperature
                    onValueChanged: mppt.setM3C0Temperature(value) 
                }
            }
        }

        Text {
            text: "MPPT 3 Channel 1"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Array Voltage"
                    value: mppt.M3C1ArrayVoltage
                    onValueChanged: mppt.setM3C1ArrayVoltage(value)
                }

                IntSpinBox {
                    text: "Array Current"
                    value: mppt.M3C1ArrayCurrent
                    onValueChanged: mppt.setM3C1ArrayCurrent(value)
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Battery Voltage"
                    value: mppt.M3C1BatteryVoltage
                    onValueChanged: mppt.setM3C1BatteryVoltage(value)
                }

                IntSpinBox {
                    text: "Temperature"
                    value: mppt.M3C1Temperature
                    onValueChanged: mppt.setM3C1Temperature(value) 
                }
            }
        }
    }
}
