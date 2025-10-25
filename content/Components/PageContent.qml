import QtQuick
import QtQuick.Effects
import QtQuick.Layouts

Item {
    id: pageContent

    width: parent.width
    height: cardColumn.height

    // list of fields for a packet
    property var fields

    // active packet context
    property var packet

    //Column display of can message cards
    Column {
        id: cardColumn
        spacing: 20

        // Make a card for every can message
        Repeater {
            model: pageContent.fields

            Item {
                id: card
                width: pageContent.width
                height: cardBack.height + 5

                // Is the can message preview open or closed
                property bool isPreviewCollapsed: true

                Rectangle {
                    id: cardBack

                    color: "white"
                    radius: 15
                    border.color: "#1a000000"
                    border.width: 1

                    anchors {
                        left: parent.left
                        right: parent.right
                        top: topRect.top
                        bottom: preview.bottom
                        topMargin: -1
                    }
                }

                // Border line
                Rectangle {
                    color: cardBack.border.color
                    z:10
                    height: 1
                    anchors {
                        left: card.left
                        right: card.right
                        top: hideBottomRadius.top
                    }
                }

                // Background for card title header section
                Rectangle {
                    id: topRect
                    height: 75
                    radius: 15

                    gradient: Gradient {
                        GradientStop {
                            position: 0
                            color: "#f8fafc"
                        }
                        GradientStop {
                            position: 1
                            color: "#ffffff"
                        }
                        orientation: Gradient.Horizontal
                    }

                    anchors {
                        left: card.left
                        right: card.right
                        top: card.top
                        leftMargin: 1
                        rightMargin: 1
                        topMargin: 1
                    }

                    Text {
                        text: modelData.name
                        color: "#0f172b"
                        font.pixelSize: 16
                        anchors {
                            verticalCenter: topRect.verticalCenter
                            verticalCenterOffset: -7.5
                            left: topRect.left
                            leftMargin: 24
                        }
                    }
                }

                // Hides bottom radius of topRect
                Rectangle {
                    id: hideBottomRadius
                    color: "#FFF"
                    height: 50
                    anchors {
                        left: card.left
                        right: card.right
                        top: topRect.bottom
                        topMargin: -15
                        leftMargin: 1
                        rightMargin: 1
                    }
                }

                //Grid display for user input fields, displays 2 per row
                Grid {
                    id: inputGrid
                    columns: 2
                    rowSpacing: 10
                    columnSpacing: 10

                    anchors {
                        top: topRect.bottom
                        left: card.left
                        right: card.right
                        leftMargin: 24
                        rightMargin: 24
                        topMargin: 24
                    }

                    // Generate an (num, float, or bool) input field for each field in can message
                    Repeater {
                        model: modelData.children
                        delegate: Item {
                            width: (inputGrid.width - inputGrid.columnSpacing - 24) / inputGrid.columns
                            height: 45
                            Component.onCompleted: {
                                const map = { num: numInput, float: floatInput, bool: boolInput }
                                const comp = map[modelData.type]
                                if (comp) comp.createObject(this, { fieldData: modelData, packet: pageContent.packet })
                            }
                        }
                    }
                }

                // Button for expanding and collapsing CAN preview
                Rectangle {
                    id: previewBtn
                    height: 35
                    color: hovered ? "#e9ebef" : "#FFF"
                    radius: 10
                    border.color: "#1a000000"
                    border.width: 1
                    anchors {
                        left: card.left
                        right: card.right
                        top: inputGrid.bottom
                        leftMargin: 24
                        rightMargin: 24
                        topMargin: 24
                    }

                    //Tracks if button is hovered over in Mouse area
                    property bool hovered: false

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: parent.hovered = true
                        onExited: parent.hovered = false
                        onClicked: card.isPreviewCollapsed = !card.isPreviewCollapsed
                    }

                    Text {
                        text: "CAN Message Preview"
                        anchors {
                            left: previewBtn.left
                            verticalCenter: previewBtn.verticalCenter
                            leftMargin: 24
                        }
                    }

                    Image {
                        source: "../images/ArrowIcon.png"
                        sourceSize.height: 16
                        sourceSize.width: 16
                        width: 16
                        height: 16
                        anchors {
                            right: previewBtn.right
                            verticalCenter: previewBtn.verticalCenter
                            rightMargin: 24
                        }
                        rotation: card.isPreviewCollapsed ? 0 : 180
                    }
                }

                //CAN message preview Item - Displays CAN message information and can be hidden via previewBtn
                Item {
                    id: preview
                    height: card.isPreviewCollapsed ? 0 : 100
                    visible: !card.isPreviewCollapsed

                    anchors {
                        top: previewBtn.bottom
                        left: card.left
                        right: card.right
                        topMargin: 16
                        leftMargin: 24
                        rightMargin: 24
                    }

                    //CAN information to be displayed
                    property var previewItems: [
                        {
                            attr: "Message ID:",
                            val: modelData.id ? modelData.id : "-0x069"
                        },
                        {
                            attr: "Frequency:",
                            val: modelData.freq ?  modelData.freq + " Hz" : "-69 Hz"
                        },
                        {
                            attr: "Payload:",
                            val: modelData.messageLength ? modelData.messageLength + " Bytes" : "-69 Bytes"
                        }
                    ]

                    Repeater {
                        model: preview.previewItems

                        delegate: Item {
                            width: previewStat.width + valBack.width + 8
                            height: 22

                            anchors {
                               left: model.index === 0 ? preview.left : undefined
                               horizontalCenter: model.index === 1 ? preview.horizontalCenter : undefined
                               right: model.index === 2 ? preview.right : undefined
                           }

                            Text {
                                id: previewStat
                                text: modelData.attr
                                font.pixelSize: 15
                                color: "#45556c"
                            }

                            Rectangle {
                                id: valBack
                                height: previewVal.height + 4
                                width: previewVal.width + 16
                                color: "#FFF"
                                radius: 7
                                border.color: "#1a000000"

                                anchors {
                                    horizontalCenter: previewVal.horizontalCenter
                                    verticalCenter: previewVal.verticalCenter
                                }
                            }

                            Text {

                                id: previewVal
                                text: modelData.val
                                font.pixelSize: 14
                                font.family: "Courier"
                                anchors {
                                    left: previewStat.right
                                    leftMargin: 16
                                }
                            }
                        }
                    }

                    //CAN message byte display
                    Rectangle {
                        id: payloadDisplay
                        height: 45
                        color: "black"
                        radius: 10
                        anchors {
                            right: preview.right
                            left: preview.left
                            top: preview.top
                            topMargin: 32
                        }

                        Text {
                            text: {
                                //Formats the value into bytes
                                var val = pageContent.packet[modelData.getter];
                                var hex = ("0000000000000000" + Number(val).toString(16).toUpperCase()).slice(-(modelData.messageLength * 2));
                                var formattedHex = hex.match(/.{2}/g).reverse().join(" ");
                                return formattedHex;
                            }

                            font.pixelSize: 16
                            font.family: "Courier"
                            color: "#ff6467"

                            anchors {
                                left: payloadDisplay.left
                                verticalCenter: payloadDisplay.verticalCenter
                                leftMargin: 24
                            }
                        }
                    }
                }
            }
        }
    }

    Component {
        id: numInput

        Rectangle {
            radius: 10
            color: "#f8fafc"
            anchors.fill: parent
            property var fieldData
            property var packet

            MouseArea {
                anchors.fill: parent
                onClicked: packet[parent.fieldData.setter](packet[fieldData.getter] +1)
            }

            Text {
                id: text1
                color: "red"
                z:200
                text: parent.fieldData.name
            }

            Text {
                text: "NUMBER TODO"
                anchors.top: text1.bottom
            }
        }
    }

    Component {
        id: floatInput

        Rectangle {
            property var data

            radius: 10
            color: "#f8fafc"

            Text {
                text: data.name
            }

            Text {
                text: "FLOAT TODO"
            }
        }
    }

    Component {
        id: boolInput

        Rectangle {
            property var data

            radius: 10
            color: "#f8fafc"

            Text {
                text: data.name
            }

            Text {
                text: "BOOL TODO"
            }
        }
    }
}
