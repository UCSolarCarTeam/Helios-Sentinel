import QtQuick

Item {
    id: toggle

    property bool on: false

    width: 32
    height: 20

    function toggleSwitch () {
        if(toggle.state === "on")
            toggle.state = "off";
        else
            toggle.state = "on";
    }

    function release(x) {
        if(x === 1){
            if (toggle.state === "off") return;
        } else if (x === 15) {
            if (toggle.state === "on") return;
        }
        toggleSwitch();
    }

    Rectangle {
        id: background
        color: "#cbced4"

        width: 32
        height: 20
        radius: height/2


        MouseArea {
            anchors.fill: parent
            onClicked: toggleSwitch()
        }
    }

    Rectangle {
        id: knob
        color: "white"
        width: 16
        height: 16
        radius: height/2
        x: 1

        anchors {
            verticalCenter: background.verticalCenter
        }

        MouseArea {
            anchors.fill: parent
            drag.target: knob
            drag.axis: Drag.XAxis
            drag.minimumX: 1
            drag.maximumX: 15
            onReleased: release(knob.x)
            onClicked: toggleSwitch()
        }
    }

    states: [
        State {
            name: "on"
            PropertyChanges { target: knob; x: 15 }
            PropertyChanges { target: toggle; on: true }
            PropertyChanges { target: background; color: "#030213" }
        },
        State {
            name: "off"
            PropertyChanges { target: knob; x: 1 }
            PropertyChanges { target: toggle; on: false }
            PropertyChanges { target: background; color: "#cbced4" }
        }
    ]

    transitions: Transition {
        NumberAnimation { properties: "x"; easing.type: Easing.InOutQuad; duration: 200 }
    }
}
