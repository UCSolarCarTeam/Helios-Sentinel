import QtQuick 2.15
import QtQuick.Controls 2.15
import ".."

Item {
    width: 550
    height: 650

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Lights Packet"
            font.family: "Verdana"
            font.bold: true
        }
        FlagBox{
            title:"Light Status"
            flags:[
                {
                    text: qsTr("Lights Alive"),
                    checked: lightsElysia.LightsAlive,
                    onClicked: function(checked) {lightsElysia.setLightsAlive(checked)}
                },
                {
                    text:qsTr("Low Beams"),
                    checked: lightsElysia.LowBeams,
                    onClicked: function(checked) {lightsElysia.setLowBeams(checked)}

                },
                {
                    text:qsTr("Left Signal"),
                    checked: lightsElysia.LeftSignal,
                    onClicked: function(checked){lightsElysia.setLeftSignal(checked)}

                },
                {
                    text: qsTr("High Beams"),
                    checked: lightsElysia.HighBeams,
                    onClicked: function(checked){lightsElysia.setHighBeams(checked)}
                },
                {
                    text:qsTr("Right Signal"),
                    checked: lightsElysia.RightSignal,
                    onClicked: function(checked) {lightsElysia.setRightSignal(checked)}
                },
                {
                    text: qsTr("Brake Lights"),
                    checked: lightsElysia.BrakeLights,
                    onClicked: function(checked) {lightsElysia.setBrakeLights(checked)}

                },
                {
                    text: qsTr("BMS Light"),
                    checked: lightsElysia.BmsLight,
                    onClicked: function(checked) {lightsElysia.setBmsLight(checked)}
                },

            ]
        }
        BytePreview {
            id: bytePreview
            raw: lightsElysia.byteStreamStr
            encoded: lightsElysia.encodedByteStreamStr
        }
    }
}
