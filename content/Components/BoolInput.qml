import QtQuick

Rectangle {
    property var fieldData
    property var packet

    radius: 10
    color: "#f8fafc"

    Text {
        text: fieldData.name + " (" + packet[fieldData.getter] + ")"
    }
}
