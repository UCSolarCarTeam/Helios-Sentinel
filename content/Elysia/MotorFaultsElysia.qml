import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0
import ".."

Item {
    width: 750
    height: 1000
    Column{
        spacing:20
        FlagBox{
            title:"M0 Error Flags"
            flags:[
                {
                    text: qsTr("M0 Motor Over Speed"),
                    checked: motorFaultsElysia.MotorOverSpeedM0,
                    onClicked: function(checked) {motorFaultsElysia.setMotorOverSpeedM0(checked)}
                },
                {
                    text: qsTr("M0 DC Bus OVer Voltage"),
                    checked: motorFaultsElysia.DcBusOverVoltageM0,
                    onClicked:function(checked) { motorFaultsElysia.setDcBusOverVoltageM0(checked)}
                },
                {
                    text: qsTr("M0 Software Over Current"),
                    checked: motorFaultsElysia.SoftwareOverCurrentM0,
                    onClicked: function(checked) {motorFaultsElysia.setSoftwareOverCurrentM0(checked)}
                },
                {
                    text: qsTr("M0 Bad Motor Position HS"),
                    checked: motorFaultsElysia.BadMotorPHSM0,
                    onClicked: function(checked) { motorFaultsElysia.setBadMotorPHSM0(checked)}
                },
                {
                    text: qsTr("M0 Watchdog Caused Last Reset"),
                    checked: motorFaultsElysia.WatchdogCausedLastResetM0,
                    onClicked: function(checked) {motorFaultsElysia.setWatchdogCausedLastResetM0(checked)}
                },
                {
                    text: qsTr("M0 15V Rail Under Voltage Lock"),
                    checked: motorFaultsElysia.RailUnderVoltageLockM0,
                    onClicked: function(checked) {motorFaultsElysia.setRailUnderVoltageLockM0(checked)}
                },
                {
                    text: qsTr("M0 Desaturation Fault"),
                    checked: motorFaultsElysia.DesaturationFaultM0,
                    onClicked: function(checked) {motorFaultsElysia.setDesaturationFaultM0(checked)}
                },
                {
                    text: qsTr("M0 Config Read Error"),
                    checked: motorFaultsElysia.ConfigReadErrorM0,
                    onClicked:function(checked) {motorFaultsElysia.setConfigReadErrorM0(checked)}
                }
            ]
        }
        FlagBox{
            title:"M1 Error Flags"
            flags:[
                {
                    text: qsTr("M1 Motor Over Speed"),
                    checked: motorFaultsElysia.MotorOverSpeedM1,
                    onClicked: function(checked) {motorFaultsElysia.setMotorOverSpeedM1(checked)}
                },
                {
                    text: qsTr("M1 DC Bus OVer Voltage"),
                    checked: motorFaultsElysia.DcBusOverVoltageM1,
                    onClicked:function(checked) { motorFaultsElysia.setDcBusOverVoltageM1(checked)}
                },
                {
                    text: qsTr("M1 Software Over Current"),
                    checked: motorFaultsElysia.SoftwareOverCurrentM1,
                    onClicked: function(checked) {motorFaultsElysia.setSoftwareOverCurrentM1(checked)}
                },
                {
                    text: qsTr("M1 Bad Motor Position HS"),
                    checked: motorFaultsElysia.BadMotorPHSM1,
                    onClicked: function(checked) { motorFaultsElysia.setBadMotorPHSM1(checked)}
                },
                {
                    text: qsTr("M1 Watchdog Caused Last Reset"),
                    checked: motorFaultsElysia.WatchdogCausedLastResetM1,
                    onClicked: function(checked) {motorFaultsElysia.setWatchdogCausedLastResetM1(checked)}
                },
                {
                    text: qsTr("M1 15V Rail Under Voltage Lock"),
                    checked: motorFaultsElysia.RailUnderVoltageLockM1,
                    onClicked: function(checked) {motorFaultsElysia.setRailUnderVoltageLockM1(checked)}
                },
                {
                    text: qsTr("M1 Desaturation Fault"),
                    checked: motorFaultsElysia.DesaturationFaultM1,
                    onClicked: function(checked) {motorFaultsElysia.setDesaturationFaultM1(checked)}
                },
                {
                    text: qsTr("M1 Config Read Error"),
                    checked: motorFaultsElysia.ConfigReadErrorM1,
                    onClicked:function(checked) {motorFaultsElysia.setConfigReadErrorM1(checked)}
                }
            ]
        }
        FlagBox {
            title:"M0 Limit Flags"
            flags:[
                {
                    text: qsTr("M0 Output Voltage PWM"),
                    checked: motorFaultsElysia.OutputVoltagePWMM0,
                    onClicked:function(checked){ motorFaultsElysia.setOutputVoltagePWMM0(checked)}
                },
                {
                    text: qsTr("M0 Velocity"),
                    checked: motorFaultsElysia.VelocityM0,
                    onClicked: function(checked) {motorFaultsElysia.setVelocityM0(checked)}
                },
                {
                    text: qsTr("M0 Motor Current "),
                    checked: motorFaultsElysia.MotorCurrentM0,
                    onClicked: function(checked){motorFaultsElysia.setMotorCurrentM0(checked)}
                },
                {
                    text: qsTr("M0 Bus Current"),
                    checked: motorFaultsElysia.BusCurrentM0,
                    onClicked: function(checked) {motorFaultsElysia.setBusCurrentM0(checked)}
                },
                {
                    text: qsTr("M0 Bus Voltage Upper"),
                    checked: motorFaultsElysia.BusVoltageUpperM0,
                    onClicked:function(checked) { motorFaultsElysia.setBusVoltageUpperM0(checked)}
                },
                {
                    text: qsTr("M0 IPM or Motor Temperature"),
                    checked: motorFaultsElysia.MotorTemperatureIPMM0,
                    onClicked: function(checekd) {motorFaultsElysia.setMotorTemperatureIPMM0(checked)}
                },
                {
                    text: qsTr("M0 Bus Voltage Lower"),
                    checked: motorFaultsElysia.BusVoltageLowerM0,
                    onClicked: function(checked) {motorFaultsElysia.setBusVoltageLowerM0(checked)}
                }

            ]
        }
        FlagBox {
            title:"M1 Limit Flags"
            flags:[
                {
                    text: qsTr("M1 Output Voltage PWM"),
                    checked: motorFaultsElysia.OutputVoltagePWMM1,
                    onClicked:function(checked){ motorFaultsElysia.setOutputVoltagePWMM1(checked)}
                },
                {
                    text: qsTr("M1 Velocity"),
                    checked: motorFaultsElysia.VelocityM1,
                    onClicked: function(checked) {motorFaultsElysia.setVelocityM1(checked)}
                },
                {
                    text: qsTr("M1 Motor Current "),
                    checked: motorFaultsElysia.MotorCurrentM1,
                    onClicked: function(checked){motorFaultsElysia.setMotorCurrentM1(checked)}
                },
                {
                    text: qsTr("M1 Bus Current"),
                    checked: motorFaultsElysia.BusCurrentM1,
                    onClicked: function(checked) {motorFaultsElysia.setBusCurrentM1(checked)}
                },
                {
                    text: qsTr("M1 Bus Voltage Upper"),
                    checked: motorFaultsElysia.BusVoltageUpperM1,
                    onClicked:function(checked) { motorFaultsElysia.setBusVoltageUpperM1(checked)}
                },
                {
                    text: qsTr("M1 IPM or Motor Temperature"),
                    checked: motorFaultsElysia.MotorTemperatureIPMM1,
                    onClicked: function(checekd) {motorFaultsElysia.setMotorTemperatureIPMM1(checked)}
                },
                {
                    text: qsTr("M1 Bus Voltage Lower"),
                    checked: motorFaultsElysia.BusVoltageLowerM1,
                    onClicked: function(checked) {motorFaultsElysia.setBusVoltageLowerM1(checked)}
                }

            ]
        }
        IntSpinBox {
            text: qsTr("M0 CAN RX Error Count ")
            value: motorFaultsElysia.CANRXErrorCountM0
            onValueChanged: motorFaultsElysia.setCANRXErrorCountM0(value)
        }

        IntSpinBox{
            text: qsTr("M0 CAN TX Error Count ")
            value: motorFaultsElysia.CANTXErrorCountM0
            onValueChanged: motorFaultsElysia.setCANTXErrorCountM0(value)
        }

        IntSpinBox {
            text: qsTr("M1 CAN RX Error Count ")
            value: motorFaultsElysia.CANRXErrorCountM1
            onValueChanged: motorFaultsElysia.setCANRXErrorCountM1(value)
        }

        IntSpinBox{
            text: qsTr("M1 CAN TX Error Count ")
            value: motorFaultsElysia.CANTXErrorCountM1
            onValueChanged: motorFaultsElysia.setCANTXErrorCountM1(value)
        }

        BytePreview {
            id: bytePreview
            raw:  motorFaultsElysia.byteStreamStr
            encoded: motorFaultsElysia.encodedByteStreamStr
        }
    }
}
