import QtQuick

Rectangle {
    id: numInput
    radius: 5
    color: "#f8fafc"

    height: 76

    property var fieldData
    property var packet
    property int decimalPlaces: 0

    onFieldDataChanged: {
        if (fieldData && fieldData.type === "float")
            decimalPlaces = fieldData ? fieldData.decimalPlaces : 0
    }

    Column {
        spacing: 12
        width: parent.width
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
            margins: 8
        }

        Text {
            id: text1
            color: "#314158"
            text: numInput.fieldData.name + " (" + numInput.fieldData.units + ")"
            font.pixelSize: 15
        }

        Item {
            width: parent.width
            height: 30
            Row {
                width: parent.width
                spacing: 12

                Rectangle {
                    id: decreaseBtn
                    color: isHovered ? "#e9ebef": "#FFF"
                    width: 30
                    height: 30
                    border.color: "#1a000000"
                    radius: 5

                    property bool isHovered

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: parent.isHovered = true
                        onExited: parent.isHovered = false
                        onClicked: {
                                let current = numInput.packet[numInput.fieldData.getter]
                                let newVal = current - (1 / Math.pow(10, numInput.decimalPlaces))

                                if (newVal < numInput.fieldData.min)
                                    newVal = numInput.fieldData.min

                                numInput.packet[numInput.fieldData.setter](
                                    parseFloat(newVal.toFixed(numInput.decimalPlaces))
                                )
                            }
                    }

                    Image {
                        source: "../images/MinusIcon.png"
                        anchors {
                            fill: parent
                            margins: 9
                        }
                    }
                }

                Rectangle {
                    width: numInput.width - decreaseBtn.width - increaseBtn.height - 48
                    height: 30
                    color: "#f3f3f5"
                    radius: 5

                    TextInput {
                        color:"#0a0a0a"
                        text: numInput.packet[numInput.fieldData.getter].toFixed(numInput.decimalPlaces)
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        font.pixelSize: 14

                        onAccepted: {
                            let value = parseFloat(text)

                            // Clamp between min and max
                            if (value < numInput.fieldData.min)
                                value = numInput.fieldData.min
                            else if (value > numInput.fieldData.max)
                                value = numInput.fieldData.max

                            // Update the source and text display
                            numInput.packet[numInput.fieldData.setter](value)
                            text = value.toFixed(numInput.decimalPlaces)
                        }
                        anchors {
                            fill: parent
                        }
                    }
                }

                Rectangle {
                    id: increaseBtn
                    color: isHovered ? "#e9ebef": "#FFF"
                    width: 30
                    height: 30
                    border.color: "#1a000000"
                    radius: 5

                    property bool isHovered

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: parent.isHovered = true
                        onExited: parent.isHovered = false
                        onClicked: {
                                let current = numInput.packet[numInput.fieldData.getter]
                                let newVal = current + (1 / Math.pow(10, numInput.decimalPlaces))

                                if (newVal > numInput.fieldData.max)
                                    newVal = numInput.fieldData.max

                                numInput.packet[numInput.fieldData.setter](
                                    parseFloat(newVal.toFixed(numInput.decimalPlaces))
                                )
                            }
                    }

                    Image {
                        source: "../images/PlusIcon.png"
                        anchors {
                            fill: parent
                            margins: 9
                        }
                    }
                }
            }
        }
    }
}

