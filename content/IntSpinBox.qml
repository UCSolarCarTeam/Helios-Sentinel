import QtQuick
import QtQuick.Controls

Item {
    id: intSpinBox
    height: 25
    anchors.right: parent.right
    anchors.rightMargin: 0

    property alias text: text1.text
    property alias value: spinBox.value
    signal customValueChanged(int newValue)

    // Define default range as unsigned short
    property var range: {"from": 0, "to": 65535}

    Text {
        id: text1
        y: 4
        font.pixelSize: 14
    }

    SpinBox {
        id: spinBox
        y: 0
        width: 120
        height: 25
        from: range.from
        to: range.to
        editable: true
        bottomPadding: 1
        topPadding: 1
        spacing: 5
        wheelEnabled: true
        rightPadding: 25
        leftPadding: 25
        anchors.left: text1.right
        anchors.leftMargin: 10
        onValueChanged: customValueChanged(value)
    }

    width: text1.implicitWidth + spinBox.width + spinBox.anchors.leftMargin
}
