import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."

Item {
    width: 600
    height: 200
    opacity: 1
    visible: true

    FlagBox{
        title:"Light Status"
        flags:[
            {
                title:qsTr("Lights Alive"),
                checked: lights.LightsAlive,
                onClicked: function(checked) {lights.setLightsAlive(checked)}
            },
            {
                title:qsTr("Low Beams"),
                checked: lights.LowBeams,
                onClicked: function(checked) {lights.setLowBeams(checked)}

            },
            {
                title:qsTr("Left Signal"),
                checked: lights.LeftSignal,
                onClicked: function(checked){lights.setLeftSignal(checked)}

            },
            {
                title: qsTr("High Beams"),
                checked: lights.HighBeams,
                onClicked: function(checked){lights.setHighBeams(checked)}
            },
            {
                title:qsTr("Right Signal"),
                checked: lights.RightSignal,
                onClicked: function(checked) {lights.setRightSignal(checked)}
            },
            {
                title: qsTr("Brake Lights"),
                checked: lights.BrakeLights,
                onClicked: function(checked) {lights.setBrakeLights(checked)}

            },
            {
                text: qsTr("BMS Light"),
                checked: lights.BmsLight,
                onClicked: function(checked) {lights.setBmsLight(checked)}
            },

        ]
    }
    BytePreview {
        id: bytePreview
        raw: lights.byteStreamStr
        encoded: lights.encodedByteStreamStr
    }
}
