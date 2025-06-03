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

    property alias min: spinBox.from
    property alias max: spinBox.to

    Column {
        spacing: 5

        Text {
            id: text1
            font.pixelSize: 14
        }

        Row{
            spacing: 5

            SpinBox {
                id: spinBox
                width: 110
                height: 25
                font.pixelSize: 12
                from: intSpinBox.min
                to: intSpinBox.max
                editable: true
                bottomPadding: 1
                topPadding: 1
                spacing: 5
                wheelEnabled: true
                rightPadding: 25
                leftPadding: 25
                anchors.leftMargin: 10
                onValueChanged: customValueChanged(value)
            }

            Text{
                text: "cm"
            }
        }
    }

    width: text1.implicitWidth + spinBox.width + spinBox.anchors.leftMargin
}
