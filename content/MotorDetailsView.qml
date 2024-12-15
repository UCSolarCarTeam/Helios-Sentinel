import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0


Item {
    property var motorDetails : motorDetails0
    width: 550
    height: 620
    x: 0
    y: 0
    Column {
        spacing: 20

        Text {
            text: "Proximity Sensors Packet"
            font.family: "Verdana"
            font.bold: true
        }

        ComboBox {
            id: motorSelector
            width: 150
            model: ["Motor 0", "Motor 1"]
            onCurrentIndexChanged: {
                motorDetails = currentIndex === 0 ? motorDetails0 : motorDetails1
            }
        }

        Column{
            spacing: 20

            Text {
                text: "TODO"
                font.pixelSize: 12
            }
        }
    }
}
