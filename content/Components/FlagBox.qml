import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 530
    height: 125

    property string title: "PLACEHOLDER"
    property var flags: []

    Text {
        id: flagGroupTitle
        text: title
        font.pointSize: 8
        font.family: "Verdana"
        font.bold: true
    }

    Rectangle {
        id: background
        y: 25
        width: parent.width
        height: 100
        color: "#DDD"
        z: -1
    }

    ScrollView {
        id: flagGroupScrollView
        y: 25
        width: parent.width
        height: 100

        Grid {
            id: flagGroupGrid
            columns: 3
            spacing: 20

            Repeater {
                model: flags

                CheckBox {
                    text: modelData.text
                    checked: modelData.checked
                    height: 30
                    font.pointSize: 8
                    onCheckedChanged: {
                        modelData.checked = checked
                        if (modelData.onClicked) {
                            modelData.onClicked(checked)
                        }
                    }
                }
            }
        }
    }
}
