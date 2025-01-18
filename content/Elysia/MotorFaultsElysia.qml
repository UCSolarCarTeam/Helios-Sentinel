import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0
import ".."

Item {
    width: 1092
    height: 1080

    FlagBox{
        title:"M0 Error Flags"
        flags:[
            {
                text: qsTr("M0 Motor Over Speed"),
                checked: motorFaults.MotorOverSpeedM0,
                onClicked: function(checked) {motorFaults.setMotorOverSpeedM0(checked)}
            },
            {
                text: qsTr("M0 DC Bus OVer Voltage"),
                checked: motorFaults.DcBusOverVoltageM0,
                onClicked:function(checked) { motorFaults.setDcBusOverVoltageM0(checked)}
            },
            {
                text: qsTr("M0 Software Over Current"),
                checked: motorFaults.SoftwareOverCurrentM0,
                onClicked: function(checked) {motorFaults.setSoftwareOverCurrentM0(checked)}
            },
            {
                text: qsTr("M0 Bad Motor Position HS"),
                checked: motorFaults.BadMotorPHSM0,
                onClicked: function(checked) { motorFaults.setBadMotorPHSM0(checked)}
            },
            {
                text: qsTr("M0 Watchdog Caused Last Reset"),
                checked: motorFaults.WatchdogCausedLastResetM0,
                onClicked: function(checked) {motorFaults.setWatchdogCausedLastResetM0(checked)}
            },
            {
                text: qsTr("M0 15V Rail Under Voltage Lock"),
                checked: motorFaults.RailUnderVoltageLockM0,
                onClicked: function(checked) {motorFaults.setRailUnderVoltageLockM0(checked)}
            },
            {
                text: qsTr("M0 Desaturation Fault"),
                checked: motorFaults.DesaturationFaultM0,
                onClicked: function(checked) {motorFaults.setDesaturationFaultM0(checked)}
            },
            {
                text: qsTr("M0 Config Read Error"),
                checked: motorFaults.ConfigReadErrorM0,
                onClicked:function(checked) {motorFaults.setConfigReadErrorM0(checked)}
            }
        ]
    }

    FlagBox{
        title:"M1 Error Flags"
        flags:[
            {
                text: qsTr("M1 Motor Over Speed"),
                checked: motorFaults.MotorOverSpeedM1,
                onClicked: function(checked) {motorFaults.setMotorOverSpeedM1(checked)}
            },
            {
                text: qsTr("M1 DC Bus OVer Voltage"),
                checked: motorFaults.DcBusOverVoltageM1,
                onClicked:function(checked) { motorFaults.setDcBusOverVoltageM1(checked)}
            },
            {
                text: qsTr("M1 Software Over Current"),
                checked: motorFaults.SoftwareOverCurrentM1,
                onClicked: function(checked) {motorFaults.setSoftwareOverCurrentM1(checked)}
            },
            {
                text: qsTr("M1 Bad Motor Position HS"),
                checked: motorFaults.BadMotorPHSM1,
                onClicked: function(checked) { motorFaults.setBadMotorPHSM1(checked)}
            },
            {
                text: qsTr("M1 Watchdog Caused Last Reset"),
                checked: motorFaults.WatchdogCausedLastResetM1,
                onClicked: function(checked) {motorFaults.setWatchdogCausedLastResetM1(checked)}
            },
            {
                text: qsTr("M1 15V Rail Under Voltage Lock"),
                checked: motorFaults.RailUnderVoltageLockM1,
                onClicked: function(checked) {motorFaults.setRailUnderVoltageLockM1(checked)}
            },
            {
                text: qsTr("M1 Desaturation Fault"),
                checked: motorFaults.DesaturationFaultM1,
                onClicked: function(checked) {motorFaults.setDesaturationFaultM1(checked)}
            },
            {
                text: qsTr("M1 Config Read Error"),
                checked: motorFaults.ConfigReadErrorM1,
                onClicked:function(checked) {motorFaults.setConfigReadErrorM1(checked)}
            }
        ]
    }
    FlagBox {
        title:"M0 Limit Flags"
        flags:[
            {
                text: qsTr("M0 Output Voltage PWM"),
                checked: motorFaults.OutputVoltagePWMM0,
                onClicked:function(checked){ motorFaults.setOutputVoltagePWMM0(checked)}
            },
            {
                text: qsTr("M0 Velocity"),
                checked: motorFaults.VelocityM0,
                onClicked: function(checked) {motorFaults.setVelocityM0(checked)}
            },
            {
                text: qsTr("M0 Motor Current "),
                checked: motorFaults.MotorCurrentM0,
                onClicked: function(checked){motorFaults.setMotorCurrentM0(checked)}
            },
            {
                text: qsTr("M0 Bus Current"),
                checked: motorFaults.BusCurrentM0,
                onClicked: function(checked) {motorFaults.setBusCurrentM0(checked)}
            },
            {
                text: qsTr("M0 Bus Voltage Upper"),
                checked: motorFaults.BusVoltageUpperM0,
                onClicked:function(checked) { motorFaults.setBusVoltageUpperM0(checked)}
            },
            {
                text: qsTr("M0 IPM or Motor Temperature"),
                checked: motorFaults.MotorTemperatureIPMM0,
                onClicked: function(checekd) {motorFaults.setMotorTemperatureIPMM0(checked)}
            },
            {
                text: qsTr("M0 Bus Voltage Lower"),
                checked: motorFaults.BusVoltageLowerM0,
                onClicked: function(checked) {motorFaults.setBusVoltageLowerM0(checked)}
            }

        ]
    }
    FlagBox {
        title:"M1 Limit Flags"
        flags:[
            {
                text: qsTr("M1 Output Voltage PWM"),
                checked: motorFaults.OutputVoltagePWMM1,
                onClicked:function(checked){ motorFaults.setOutputVoltagePWMM1(checked)}
            },
            {
                text: qsTr("M1 Velocity"),
                checked: motorFaults.VelocityM1,
                onClicked: function(checked) {motorFaults.setVelocityM1(checked)}
            },
            {
                text: qsTr("M1 Motor Current "),
                checked: motorFaults.MotorCurrentM1,
                onClicked: function(checked){motorFaults.setMotorCurrentM1(checked)}
            },
            {
                text: qsTr("M1 Bus Current"),
                checked: motorFaults.BusCurrentM1,
                onClicked: function(checked) {motorFaults.setBusCurrentM1(checked)}
            },
            {
                text: qsTr("M1 Bus Voltage Upper"),
                checked: motorFaults.BusVoltageUpperM1,
                onClicked:function(checked) { motorFaults.setBusVoltageUpperM1(checked)}
            },
            {
                text: qsTr("M1 IPM or Motor Temperature"),
                checked: motorFaults.MotorTemperatureIPMM1,
                onClicked: function(checekd) {motorFaults.setMotorTemperatureIPMM1(checked)}
            },
            {
                text: qsTr("M1 Bus Voltage Lower"),
                checked: motorFaults.BusVoltageLowerM1,
                onClicked: function(checked) {motorFaults.setBusVoltageLowerM1(checked)}
            }

        ]
    }

    IntSpinBox {
        text: qsTr("M0 CAN RX Error Count ")
        value: motorFaults.CANRXErrorCountM0
        onValueChanged: motorFaults.setCANRXErrorCountM0(value)
    }

    IntSpinBox{
        text: qsTr("M0 CAN TX Error Count ")
        value: motorFaults.CANTXErrorCountM0
        onValueChanged: motorFaults.setCANTXErrorCountM0(value)
    }

    IntSpinBox {
        text: qsTr("M1 CAN RX Error Count ")
        value: motorFaults.CANRXErrorCountM1
        onValueChanged: motorFaults.setCANRXErrorCountM1(value)
    }

    IntSpinBox{
        text: qsTr("M1 CAN TX Error Count ")
        value: motorFaults.CANTXErrorCountM1
        onValueChanged: motorFaults.setCANTXErrorCountM1(value)
    }

    BytePreview {
        id: bytePreview
        raw:  motorFaults.byteStreamStr
        encoded: motorFaults.encodedByteStreamStr
    }
}
