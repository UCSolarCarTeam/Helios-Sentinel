import QtQuick
import QtQuick.Controls

Rectangle {
    id: root
    width: 530
    height: 100
    color: "lightgrey"
    border.width: 1.5

    property alias raw: text2.text
    property alias encoded: text3.text

    Text {
        x: 10
        y: 5
        text: "Byte Stream:"
    }

    Text {
        id: text2
        x: 10
        y: 29
        width: parent.width - 20
        text: qsTr("PLACEHOLDER 1234134214124124")
        font.pixelSize: 12
        elide: Text.ElideRight
        ToolTip.text: text
    }

    Text {
        x: 10
        y: 51
        text: "Encoded Byte Stream:"
    }

    Text {
        id: text3
        x: 10
        y: 75
        width: parent.width - 20
        text: qsTr("PLACEHOLDER !@#$!@#%#@$@#$@#")
        font.pixelSize: 12
        elide: Text.ElideRight
        ToolTip.text: text
    }
}
