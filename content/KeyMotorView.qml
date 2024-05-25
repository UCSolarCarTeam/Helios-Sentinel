import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0

Item {
    id: keyMotor
    width: 820
    height: 370

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 820
        height: 370
        color: "#89f0a7"
        radius: 25

        Rectangle {
            id: rectangle1
            x: 56
            y: 28
            width: 313
            height: 298
            color: "#74a2e3"
            radius: 25

            Switch {
                id: switch1
                x: 89
                y: 35
                width: 135
                height: 37
                text: qsTr("M0 Alive")
            }

            GroupItem {
                x: 0
                y: 0

                Rectangle {
                    id: rectangle2
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    id: textInput
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    id: text1
                    x: 165
                    y: 90
                    text: qsTr("Set Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 38
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Set Velocity")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 78
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Bus Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 122
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Bus Voltage")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 164
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Vehicle Velocity")
                    font.pixelSize: 12
                }
            }
        }

        Rectangle {
            id: rectangle3
            x: 460
            y: 28
            width: 313
            height: 298
            color: "#74a2e3"
            radius: 25
            Switch {
                x: 89
                y: 35
                width: 135
                height: 37
                text: qsTr("M0 Alive")
            }

            GroupItem {
                x: 0
                y: 0
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Set Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 38
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Set Velocity")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 78
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Bus Current")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 122
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Bus Voltage")
                    font.pixelSize: 12
                }
            }

            GroupItem {
                x: 0
                y: 164
                height: 44
                Rectangle {
                    x: 59
                    y: 90
                    width: 80
                    height: 15
                    color: "#ffffff"
                }

                TextInput {
                    x: 0
                    y: 0
                    width: 80
                    height: 15
                    font.pixelSize: 12
                }

                Text {
                    x: 165
                    y: 90
                    text: qsTr("Vehicle Velocity")
                    font.pixelSize: 12
                }
            }
        }
    }
}


