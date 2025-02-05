import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 550
    height: 850

    Row {
        Text{
            text:"Helios"
            x:5
            y:65
        }
        Switch {
            id: switch1
            x: 8
            y: 60
            checked: settings.isElysia
            onClicked: settings.setIsElysia(checked)

        }
        Text{
            text:"Elysia"
            x:10
            y:65
        }
    }
}
