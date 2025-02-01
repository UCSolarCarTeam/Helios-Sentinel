// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import SentinelModule

Window {
    width: 575
    height: 700

    maximumWidth: 575

    visible: true
    title: "Sentinel"

    Loader {
        id: toolWinLoader
        source: "Window.qml"
        anchors.fill: parent
    }


}

