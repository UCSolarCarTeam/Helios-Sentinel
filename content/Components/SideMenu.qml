// pragma ComponentBehavior: Bound
import QtQuick

Rectangle {
    id: sideMenu
    width: isCollapsed ? 60 : 255
    height: 950

    color: "#000"

    property alias itemList: menuRepeater.model

    // Colors
    property color red1: "#e7000b"
    property color red2: "#c10007"
    property color textTitle: "#FFF"
    property color lightGrey: "#90a1b9"
    property color hoverColor: "#1d293d"

    // Menu Properties
    property string activeMenuItem: "Key Motor"
    property bool isCollapsed: false

    // Sentinel Logo at the top of menu
    Item {
        id: logo
        width: 140
        height: 40

        anchors {
            top: sideMenu.top
            left: sideMenu.left
            topMargin: 24
            leftMargin: sideMenu.isCollapsed ? 10 : 24
        }

        Rectangle {
            id: logoBack
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: sideMenu.red1
                }

                GradientStop {
                    position: 1
                    color: sideMenu.red2
                }
                orientation: Gradient.Vertical
            }
            width: 40
            height: 40
            radius: 7.5

        }

        Image {
            id: sentinelLogo
            source: "../images/SentinelLogo.png"
            sourceSize.height: 24
            sourceSize.width: 24
            width: 24
            height: 24
            anchors.centerIn: logoBack
        }

        Text {
            id: title
            text: "Sentinel"
            visible: !sideMenu.isCollapsed
            font.pixelSize: 16
            font.family: "Verdana"
            color: sideMenu.textTitle
            anchors {
                left: logoBack.right
                top: logoBack.top
                leftMargin: 10
            }
        }

        Text {
            text: "VizComm Tester"
            visible: !sideMenu.isCollapsed
            color: sideMenu.lightGrey
            font.pixelSize: 12
            anchors {
                left: title.left
                top: title.bottom
            }
        }
    }

    // Section Line
    Rectangle {
        id: breakLineTop
        border.color: sideMenu.lightGrey
        border.width: 1
        width: sideMenu.width
        height: 1

        anchors {
            top: logo.bottom
            topMargin: 24
        }
    }

    // Collapse Menu Button
    Rectangle {
        id: collapseMenuBtn
        width: 20
        height : 20
        radius: 10
        color: hovered ? sideMenu.hoverColor : "#000"
        border.color: sideMenu.lightGrey
        border.width: 1

        property bool hovered: false

        anchors {
            horizontalCenter: sideMenu.right
            verticalCenter: breakLineTop.verticalCenter
        }

        Image {
            source: "../images/CollapseIcon.png"
            sourceSize.height: 32
            sourceSize.width: 32
            width: 12
            height: 12
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }
            rotation: sideMenu.isCollapsed ? 180 : 0
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.hovered = true
            onExited: parent.hovered = false
            onClicked: sideMenu.isCollapsed = !sideMenu.isCollapsed
        }
    }

    // Column Display of Menu Items from menuModel
    Column {
        id: menuItems
        spacing: 5
        anchors {
            top: breakLineTop.bottom
            left: logo.left
            topMargin: 24
        }

        Repeater {
            id: menuRepeater
            model: ""

            Rectangle {
                width: sideMenu.isCollapsed ? 40 : 207
                height: 40
                radius: 10
                color: sideMenu.activeMenuItem === title ? sideMenu.red1 : hovered ? sideMenu.hoverColor : "#000"
                property bool hovered: false

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.hovered = true
                    onExited: parent.hovered = false
                    onClicked: sideMenu.activeMenuItem = title
                }

                Image {
                    source: model.icon
                    fillMode: Image.PreserveAspectFit
                    sourceSize.height: 32
                    sourceSize.width: 32
                    width: 20
                    height: 20
                    anchors {
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 10
                    }
                }

                Text {
                    text: model.title
                    visible: !sideMenu.isCollapsed
                    color: sideMenu.lightGrey
                    font.pixelSize: 16
                    anchors {
                        left: parent.left
                        leftMargin: 45
                        verticalCenter: parent.verticalCenter
                    }
                }
            }
        }
    }

    // Section Line
    Rectangle {
        id: breakLineBot
        border.color: sideMenu.lightGrey
        border.width: 1
        width: sideMenu.width
        height: 1
        anchors{
            bottom: solarCarLogo.top
            bottomMargin: 24
        }
    }

    // Solar Car Logo at the bottom
    Image {
        id: solarCarLogo
        source: sideMenu.isCollapsed ? "../images/SolarCarLogoShort.png" : "../images/SolarCarLogoLong.png"
        fillMode: Image.PreserveAspectFit
        sourceSize.width: 32
        sourceSize.height: 32
        width: sideMenu.isCollapsed ? 40 : 207

        anchors {
            left: logo.left
            bottom: sideMenu.bottom
            bottomMargin: 24
        }
    }
}
