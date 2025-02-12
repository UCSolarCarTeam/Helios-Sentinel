import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 550
    height: 850

    Switch {
        id: switch1
        x: 8
        y: 166
        text: qsTr("Toggle between Elysia and Helios")
        checked: settings.getIsElysia
        onClicked: settings.setIsElysia(checked)

    }

    Switch {
        id: serialPortSwitch
        x: 8
        y: 60
        text: qsTr("Toggle Serial Port Connection")
        checked: settings.connectSerialPort
        onClicked: settings.setConnectSerialPort(checked)
    }

    Text {
        id: text1
        x: 63
        y: 115
        text: serialPortSwitch.checked ? qsTr("Status: Connected. Port to pass to Mercury: ") + settings.secondPortName
                                       : qsTr("Status: Disconnected.")
        font.pixelSize: 12
    }
}
