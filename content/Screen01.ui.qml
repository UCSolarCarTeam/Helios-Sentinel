

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import ViscommTester
import QtQuick.Studio.Components

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    color: Constants.backgroundColor
    z: -2

    property bool isRowButtonSelected: false

    Row {
        id: row
        x: 0
        y: isRowButtonSelected ? 210 : 0
        width: 870
        height: 77

        Button {
            id: button
            text: qsTr("Button")
            background: Rectangle {
                color: "lightgray"
                radius: 0
            }
            onClicked: isRowButtonSelected = true
        }

        Button {
            id: button1
            text: qsTr("Button")
            background: Rectangle {
                color: "lightgray"
                radius: 0
            }
            onClicked: isRowButtonSelected = false
        }

        Button {
            id: button2
            text: qsTr("Button")
            background: Rectangle {
                color: "lightgray"
                radius: 0
            }
            onClicked: isRowButtonSelected = true
        }
    }

    Row {
        id: row1
        x: 0
        y: isRowButtonSelected ? 0 : 210
        width: 870
        height: 77
        Button {
            id: button3
            text: qsTr("test")
            onClicked: isRowButtonSelected = false
        }

        Button {
            id: button4
            text: qsTr("test3")
            onClicked: isRowButtonSelected = false
        }

        Button {
            id: button5
            text: qsTr("test4")
            onClicked: isRowButtonSelected = false
        }
    }
}
