// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import SentinelModule
<<<<<<< HEAD

=======
>>>>>>> 3ecbc76 (Modified project to be recognized as Sentinel and made import for QML component be called SentinelModule rather then ViscommTester. Deleted file that didn't seem required and was more auto generated when loading ViscommTester.qmlProject)
Window {
    width: mainScreen.width
    height: mainScreen.height

    maximumWidth: 575

    visible: true
    title: "Sentinel"

    Screen01 {
        id: mainScreen
        Text {
            id: label
        }
    }

}

