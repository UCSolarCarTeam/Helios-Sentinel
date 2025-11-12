import QtQuick
import QtQuick.Effects

Rectangle {
    id: header
    color: "#FFF"
    height: 75
    width: 700

    property alias activePacket: headerTitle.text

    property color borderColor: "#e2e8f0"

    //Bottom border
    Rectangle {
        height: 1
        color: header.borderColor
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }

    MultiEffect {
        id: shadow
        source: header
        shadowScale: 1.05
        anchors.fill: source
        shadowColor: "#000"
        shadowEnabled: true
        shadowBlur: 0.5
        shadowOpacity: 0.3
    }

    Column {
        anchors{
            left: header.left
            verticalCenter: header.verticalCenter
            leftMargin: 24
        }

        Text {
            id: headerTitle
            text: "TEST"
            font.pixelSize: 16
            font.weight: Font.Medium
            font.family: "Verdana"

        }

        Text {
            text: "Configure CAN Messages"
            font.pixelSize: 12
            font.family: "Verdana"
            color: "#62748e"
        }
    }

    Rectangle {
        id: searchBox
        anchors {
            right: header.right
            verticalCenter: header.verticalCenter
            rightMargin: 24
        }

        color: "#f3f3f5"
        radius: 10
        width: 300
        height: 36

        Image {
            id: searchIcon
            source: "../images/SearchIcon.png"
            width: 16
            height: 16
            sourceSize.height: 16
            sourceSize.width: 16

            anchors {
                left: searchBox.left
                leftMargin: 12
                verticalCenter: searchBox.verticalCenter
            }
        }

        TextInput {
            id: textInput
            text: "Search CAN Messages..."
            color: "#717182"
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
            anchors{
                left: searchIcon.right
                leftMargin: 12
                right: searchBox.right
                top: searchBox.top
                bottom: searchBox.bottom
            }
        }
    }
}
