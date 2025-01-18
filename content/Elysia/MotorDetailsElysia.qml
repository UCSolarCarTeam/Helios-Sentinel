
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0
import ".."


Item {
    property var motorDetailsElysia
    width: 660
    height: 620

    Text {
        id: text2
        x: 267
        y: 22
        text: qsTr("Motor " + motorDetailsElysia.motorNum + " Details")
        font.pixelSize: 20
    }

    FloatSpinBox{
          text: qsTr("Phase C Current")
          inputValue: motorDetailsElysia.PhaseCCurrent
          onInputValueChanged: motorDetailsElysia.setPhaseCCurrent(value)

    }
    FloatSpinBox{
          text: qsTr("Phase B Current")
          inputValue: mmotorDetailsElysia.PhaseBCurrent
          onInputValueChanged: motorDetailsElysia.setPhaseBCurrent(value)

    }
    FloatSpinBox{
        text:qsTr("Motor Voltage Real")
        inputValue: motorDetailsElysia.MotorVoltageReal
        onInputValueChanged: motorDetailsElysia.setMotorVoltageReal(value)
    }
    FloatSpinBox{
        text: qsTr("Motor Voltage Imaginary")
        inputValue: motorDetailsElysia.MotorVoltageImag
        onInputValueChanged:motorDetailsElysia.setMotorVoltageImag(value)
    }
    FloatSpinBox{
         text: qsTr("Motor Current Real")
         inputValue:motorDetailsElysia.MotorCurrentReal
         onInputValueChanged: motorDetailsElysia.setMotorCurrentReal(value)
    }
    FloatSpinBox{
        text: qsTr("Motor Current Imaginary")
        inputValue: motorDetailsElysia.MotorCurrentImag
        onInputValueChanged:  motorDetailsElysia.setMotorCurrentImag(value)

    }
    FloatSpinBox{
        text: qsTr("Black EMF")
        inputValue: motorDetailsElysia.BlackEMF
        onInputValueChanged: motorDetailsElysia.setBlackEMF(value)
    }
    FloatSpinBox{
        text: qsTr("15V Voltage Rail Supply")
        inputValue: motorDetailsElysia.VoltageRailSupply15
        onInputValueChanged: motorDetailsElysia.setVoltageRailSupply15(value)
    }

    FloatSpinBox {
        text: qsTr("3.3V Voltage Rail Supply")
        inputValue: motorDetailsElysia.VoltageRailSupply3
        onInputValueChanged:  motorDetailsElysia.setVoltageRailSupply3(value)
    }
    FloatSpinBox{
        text:qsTr("1.9V Voltage Rail Supply")
        inputValue:  motorDetailsElysia.VoltageRailSupply2
        onInputValueChanged:motorDetailsElysia.setVoltageRailSupply2(value)
    }
    FloatSpinBox{
        text: qsTr("Heat-sink Temperature")
        inputValue:motorDetailsElysia.HeatSinkTemp
        onInputValueChanged: motorDetailsElysia.setHeatSinkTemp(value)
    }
    FloatSpinBox {
        text: qsTr("Motor Temperature")
        inputValue: motorDetailsElysia.MotorTemp
        onInputValueChanged: motorDetailsElysia.setMotorTemp(value)

    }
    FloatSpinBox {
        text: qsTr("DSP Boaprd Tem")
        inputValue: motorDetailsElysia.DspBoardTemp
        onInputValueChanged: motorDetailsElysia.setDspBoardTemp(value)
    }
    FloatSpinBox{
        text:qsTr("DC Bus AmpHours")
        inputValue: motorDetailsElysia.DcBusAmpHours
        onInputValueChanged: motorDetailsElysia.setDcBusAmpHours(value)
    }
    FloatSpinBox {
        text: qsTr("DC Bus AmpHours")
        inputValue: motorDetailsElysia.DcBusAmpHours
        onInputValueChanged:motorDetailsElysia.setDcBusAmpHours(value)
    }
    FloatSpinBox {
        text: qsTr("Odometer")
        inputValue: motorDetailsElysia.Odometer
        onInputValueChanged: motorDetailsElysia.setOdometer(value)
    }
    FloatSpinBox {
        text: qsTr("Slip Speed")
        inputValue: : motorDetailsElysia.SlipSpeed
        onInputValueChanged: motorDetails.setSlipSpeed(value)
    }

    BytePreview {
        id: bytePreview
        raw:  motorDetailsElysia.byteStreamStr
        encoded:  motorDetailsElysia.encodedByteStreamStr
    }
}
