import QtQuick.Studio.Components
import QtQuick 2.15
import QtQuick.Controls 6.2

import "Components" 1.0
import "PacketViews" 1.0
import "Components/MenuModel.js" as MenuModel

Rectangle {
    id: win
    width: 900
    height: 900
    z: -20
    color: "#f6f9fb"

    property var menuModel: MenuModel.menuModel
    property string activeMenuItem: menuModel[0].title
    property var fields: menuModel[0].fields

    onActiveMenuItemChanged: {
        var item = menuModel.find(function(obj) { return obj.title === activeMenuItem })
        fields = item ? item.fields : []
    }

    SideMenu {
        id: menu
        z:3
        menuModel: win.menuModel
        activeMenuItem: win.activeMenuItem
        onActiveMenuItemChanged: win.activeMenuItem = activeMenuItem
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
    }

    Header {
        id: header
        z:2
        activePacket: win.activeMenuItem
        anchors {
            left: menu.right
            right: win.right
        }
    }

    ScrollView {
        anchors {
            left: menu.right
            top: header.bottom
            right: win.right
            bottom: win.bottom
            leftMargin: 24
            rightMargin: 24
            topMargin: 24
        }

        ScrollBar.vertical.policy: ScrollBar.AlwaysOff

        Flickable {
            id: flick
            contentWidth: width
            contentHeight: pageContent.height
            clip: true

            PageContent {
                z: 1
                id: pageContent
                fields: win.fields
            }
        }
    }


}
