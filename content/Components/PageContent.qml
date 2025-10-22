import QtQuick

Item {
    id: pageContent
    property var fields: [{name: "ERROR"}]

    Column {
        Repeater {
            id: contentRepeater
            model: pageContent.fields

            Rectangle {
                width: 100
                height: 100
                Text{
                    color: "red"
                    text: modelData.name
                }
            }
        }
    }
}
