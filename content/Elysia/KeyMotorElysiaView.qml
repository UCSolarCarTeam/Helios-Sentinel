import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0
import ".."
Item {
    id: keyMotor
    width: 820
    height: 370

    FlagBox {
        title:"M0"
        flags:[
            {
                text: qsTr("M0 Alive"),
                checked: keyMotorElysia.m0Alive,
                onClicked: function(checked) {keyMotorElysia.setM0Alive(checked)}
            }
        ]
    }

    FloatSpinBox{
        text: qstr("M0 Set Current")
        inputValue: keyMotorElysia.m0SetCurrent
        onInputValueChanged: keyMotorElysia.setM0SetCurrent(value)
    }
    FloatSpinBox {
        text: qsTr("M0 Set Velocity")
        inputValue: keyMotorElysia.m0SetVelocity
        onInputValueChanged: keyMotorElysia.setM0SetVelocity(value)
    }
    FloatSpinBox {
        text: qsTr("M0 Bus Current")
        inputValue: keyMotorElysia.m0BusCurrent
        onInputValueChanged: keyMotorElysia.setM0BusCurrent(value)
    }
    FloatSpinBox{
        text:qsTr("M0 Bus Voltage")
        inputValue: keyMotorElysia.m1BusVoltage
        onInputValueChanged: keyMotorElysia.setM0BusVoltage(value)
    }
    FloatSpinBox{
        text: qsTr("M0 Vehicle Velocity")
        inputValue:keyMotorElysia.m0VehicleVelocity
        onInputValueChanged: keyMotorElysia.setM0VehicleVelocity(value)
    }

    FlagBox {
        title:"M1"
        flags:[
            {
                text: qsTr("M1 Alive"),
                checked: keyMotorElysia.m0Alive,
                onClicked: function(checked) {keyMotorElysia.setM1Alive(checked)}
            }
        ]
    }

    FloatSpinBox{
        text: qstr("M1 Set Current")
        inputValue: keyMotorElysia.m0SetCurrent
        onInputValueChanged: keyMotorElysia.setM0SetCurrent(value)
    }
    FloatSpinBox {
        text: qsTr("M1 Set Velocity")
        inputValue: keyMotorElysia.m0SetVelocity
        onInputValueChanged: keyMotorElysia.setM0SetVelocity(value)
    }
    FloatSpinBox {
        text: qsTr("M1 Bus Current")
        inputValue: keyMotorElysia.m0BusCurrent
        onInputValueChanged: keyMotorElysia.setM0BusCurrent(value)
    }
    FloatSpinBox{
        text:qsTr("M1 Bus Voltage")
        inputValue: keyMotorElysia.m1BusVoltage
        onInputValueChanged: keyMotorElysia.setM0BusVoltage(value)
    }
    FloatSpinBox{
        text: qsTr("M1 Vehicle Velocity")
        inputValue:keyMotorElysia.m0VehicleVelocity
        onInputValueChanged: keyMotorElysia.setM0VehicleVelocity(value)

    }

}
