import QtQuick
import QtQuick.Effects

Rectangle {
    id: header
    color: "#FFF"
    height: 50
    width: 200

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


}
