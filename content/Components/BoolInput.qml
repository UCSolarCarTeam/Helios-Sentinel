import QtQuick
import QtQuick.Controls

Rectangle {
    property var fieldData
    property var packet

    radius: 10
    color: "#f8fafc"

    width: 500
    height: 76

    Text {
        text: fieldData.name
        wrapMode: Text.Wrap
        font.pixelSize: 14

        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            right: toggleRow.left
            margins: 12
        }
    }

    Row {
        id: toggleRow
        spacing: 12

        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
            rightMargin: 12
        }

        Rectangle {

            anchors {
                verticalCenter: parent.verticalCenter
            }

            color: packet[fieldData.getter] ? "#e7000b" : "#eceef2"
            width: 60
            height: 22
            radius: 5

            Text {
                text: packet[fieldData.getter] ? "ON" : "OFF"
                color: packet[fieldData.getter] ? "white" : "black"
                font.pixelSize: 14
                anchors{
                    centerIn: parent
                }
            }
        }

        Toggle {
            on: packet[fieldData.getter]
            onOnChanged: {
                packet[fieldData.setter](on);
            }
        }
    }
}
