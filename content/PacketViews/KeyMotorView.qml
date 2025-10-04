import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0

import "../Components"

Item {
    width: 550
    height: 350

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20
        
        Text {
            text: "Key Motor Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Column {
            spacing: 20

             FloatSpinBox {
                id: velocity
                text: qsTr("Velocity")
                decimals: 6;
                inputValue: keyMotor.Velocity
                onInputValueUpdated: keyMotor.setVelocity(inputValue)
            }

                FloatSpinBox {
                id: current
                text: qsTr("Current")
                decimals: 6;
                inputValue: keyMotor.Current
                onInputValueUpdated: keyMotor.setCurrent(inputValue)
            }

                FloatSpinBox {
                id: busCurrentOut
                text: qsTr("Bus Current Out")
                decimals: 6;
                inputValue: keyMotor.BusCurrentOut
                onInputValueUpdated: keyMotor.setBusCurrentOut(inputValue)
            }
        }
    }
}


