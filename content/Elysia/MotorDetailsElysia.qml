import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Studio.Components 1.0
import ".."


Item {
    width: 550
    height: 650

    Row{

        spacing:5
        Column {

            spacing: 20
            IntSpinBox{
                id: spinBox
                text: qsTr("Motor Number")
                value: motorDetailsElysia.motorNum
                onValueChanged: motorDetailsElysia.setMotorNum(value)
            }
            Text {
                id: text2
                text: qsTr("Motor " + motorDetailsElysia.motorNum + " Details")
                font.pixelSize: 20
            }

            FloatSpinBox{
                  text: qsTr("Phase C Current")
                  inputValue: motorDetailsElysia.PhaseCCurrent
                  onInputValueChanged: motorDetailsElysia.setPhaseCCurrent(inputValue)

            }
            FloatSpinBox{
                  text: qsTr("Phase B Current")
                  inputValue: motorDetailsElysia.PhaseBCurrent
                  onInputValueChanged: motorDetailsElysia.setPhaseBCurrent(inputValue)

            }
            FloatSpinBox{
                text:qsTr("Motor Voltage Real")
                inputValue: motorDetailsElysia.MotorVoltageReal
                onInputValueChanged: motorDetailsElysia.setMotorVoltageReal(inputValue)
            }
            FloatSpinBox{
                text: qsTr("Motor Voltage Imaginary")
                inputValue: motorDetailsElysia.MotorVoltageImag
                onInputValueChanged:motorDetailsElysia.setMotorVoltageImag(inputValue)
            }
            FloatSpinBox{
                 text: qsTr("Motor Current Real")
                 inputValue:motorDetailsElysia.MotorCurrentReal
                 onInputValueChanged: motorDetailsElysia.setMotorCurrentReal(inputValue)
            }
            FloatSpinBox{
                text: qsTr("Motor Current Imaginary")
                inputValue: motorDetailsElysia.MotorCurrentImag
                onInputValueChanged:  motorDetailsElysia.setMotorCurrentImag(inputValue)

            }
            FloatSpinBox{
                text: qsTr("Black EMF")
                inputValue: motorDetailsElysia.BlackEMF
                onInputValueChanged: motorDetailsElysia.setBlackEMF(inputValue)
            }
            FloatSpinBox{
                text: qsTr("15V Voltage Rail Supply")
                inputValue: motorDetailsElysia.VoltageRailSupply15
                onInputValueChanged: motorDetailsElysia.setVoltageRailSupply15(inputValue)
            }
        }

        Column{
            spacing:20
            FloatSpinBox {
                text: qsTr("3.3V Voltage Rail Supply")
                inputValue: motorDetailsElysia.VoltageRailSupply3
                onInputValueChanged:  motorDetailsElysia.setVoltageRailSupply3(inputValue)
            }
            FloatSpinBox{
                text:qsTr("1.9V Voltage Rail Supply")
                inputValue:  motorDetailsElysia.VoltageRailSupply2
                onInputValueChanged:motorDetailsElysia.setVoltageRailSupply2(inputValue)
            }
            FloatSpinBox{
                text: qsTr("Heat-sink Temperature")
                inputValue:motorDetailsElysia.HeatSinkTemp
                onInputValueChanged: motorDetailsElysia.setHeatSinkTemp(inputValue)
            }
            FloatSpinBox {
                text: qsTr("Motor Temperature")
                inputValue: motorDetailsElysia.MotorTemp
                onInputValueChanged: motorDetailsElysia.setMotorTemp(inputValue)

            }
            FloatSpinBox {
                text: qsTr("DSP Boaprd Tem")
                inputValue: motorDetailsElysia.DspBoardTemp
                onInputValueChanged: motorDetailsElysia.setDspBoardTemp(inputValue)
            }
            FloatSpinBox{
                text:qsTr("DC Bus AmpHours")
                inputValue: motorDetailsElysia.DcBusAmpHours
                onInputValueChanged: motorDetailsElysia.setDcBusAmpHours(inputValue)
            }
            FloatSpinBox {
                text: qsTr("DC Bus AmpHours")
                inputValue: motorDetailsElysia.DcBusAmpHours
                onInputValueChanged:motorDetailsElysia.setDcBusAmpHours(inputValue)
            }
            FloatSpinBox {
                text: qsTr("Odometer")
                inputValue: motorDetailsElysia.Odometer
                onInputValueChanged: motorDetailsElysia.setOdometer(inputValue)
            }
            FloatSpinBox {
                text: qsTr("Slip Speed")
                inputValue: motorDetailsElysia.SlipSpeed
                onInputValueChanged: motorDetails.setSlipSpeed(inputValue)
            }
        }
    }

}
