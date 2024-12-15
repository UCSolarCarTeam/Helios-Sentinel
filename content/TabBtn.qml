import QtQuick
import QtQuick.Controls

Button {
    id: myButton
    property bool isSelected: false
    property string buttonText: "Button"
    height: 35
    width: implicitWidth
    text: buttonText
    bottomInset: 0
    topInset: 0
    background: Rectangle {
        color: myButton.isSelected ? "#A9A9A9" : "lightgray"
        radius: 12
        border.color: myButton.isSelected ? "#007BFF" : "black"
        border.width: 2
    }
    Rectangle{
        x: 0
        y: 23
        width: parent.width
        height: 12
        color: myButton.isSelected ? "#A9A9A9" : "lightgray"
        Rectangle {
            width: 2
            height: parent.height
            border.color: myButton.isSelected ? "#007BFF" : "black"
            anchors.left: parent.left
        }
        Rectangle {
            width: 2
            height: parent.height
            border.color: myButton.isSelected ? "#007BFF" : "black"
            anchors.right: parent.right
        }
    }
    Rectangle {
        x: 0
        y: parent.height - 2
        width: parent.width
        height: 2
        color: myButton.isSelected ? "transparent" : "black" // Bottom border color
    }
}
