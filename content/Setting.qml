import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 550
    height: 850

    Switch {
        id: switch1
        x: 8
        y: 60
        text: qsTr("Toggle between Elysia and Helios")
        checked: settings.getIsElysia
        onClicked: settings.setIsElysia(checked)

    }
}
