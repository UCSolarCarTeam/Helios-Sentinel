import QtQuick 2.15
import QtQuick.Controls 2.15

import "../Components"

Item {
    width: 550
    height: 875
    x: 0
    y: 0
    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Motor Details Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Row {
            spacing: 20

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Tritium ID"
                    value: motorDetails.TritiumId
                    onValueChanged: motorDetails.setTritiumId(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Serial Number"
                    value: motorDetails.SerialNumber
                    onValueChanged: motorDetails.setSerialNumber(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Limit Flags"
                    value: motorDetails.LimitFlags
                    onValueChanged: motorDetails.setLimitFlags(value)
                }

                IntSpinBox {
                    text: "Error Flags"
                    value: motorDetails.ErrorFlags
                    onValueChanged: motorDetails.setErrorFlags(value)
                }

                IntSpinBox {
                    text: "Active Motor"
                    value: motorDetails.ActiveMotor
                    onValueChanged: motorDetails.setActiveMotor(value)
                }

                IntSpinBox {
                    text: "Tx Error Count"
                    value: motorDetails.TxErrorCount
                    onValueChanged: motorDetails.setTxErrorCount(value)
                    max: 255
                }           

                IntSpinBox {
                    text: "Rx Error Count"
                    value: motorDetails.RxErrorCount
                    onValueChanged: motorDetails.setRxErrorCount(value)
                    max: 255
                }

                IntSpinBox {
                    text: "Bus Voltage"
                    value: motorDetails.BusVoltage
                    onValueChanged: motorDetails.setBusVoltage(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Bus Current"
                    value: motorDetails.BusCurrent
                    onValueChanged: motorDetails.setBusCurrent(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Motor Velocity"
                    value: motorDetails.MotorVelocity
                    onValueChanged: motorDetails.setMotorVelocity(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Vehicle Velocity"
                    value: motorDetails.VehicleVelocity
                    onValueChanged: motorDetails.setVehicleVelocity(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Phase Current B"
                    value: motorDetails.PhaseCurrentB
                    onValueChanged: motorDetails.setPhaseCurrentB(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Phase Current C"
                    value: motorDetails.PhaseCurrentC
                    onValueChanged: motorDetails.setPhaseCurrentC(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Vq"
                    value: motorDetails.Vq
                    onValueChanged: motorDetails.setVq(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Vd"
                    value: motorDetails.Vd
                    onValueChanged: motorDetails.setVd(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Iq"
                    value: motorDetails.Iq
                    onValueChanged: motorDetails.setIq(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Id"
                    value: motorDetails.Id
                    onValueChanged: motorDetails.setId(value)
                    max: 2147483647
                }
            }

            Column {
                spacing: 20

                IntSpinBox {
                    text: "Bemfq"
                    value: motorDetails.Bemfq
                    onValueChanged: motorDetails.setBemfq(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Bemfd"
                    value: motorDetails.Bemfd
                    onValueChanged: motorDetails.setBemfd(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Supply 15V"
                    value: motorDetails.Supply15V
                    onValueChanged: motorDetails.setSupply15V(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Supply 1V9"
                    value: motorDetails.Supply1V9
                    onValueChanged: motorDetails.setSupply1V9(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Supply 3V3"
                    value: motorDetails.Supply3V3
                    onValueChanged: motorDetails.setSupply3V3(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Reserved 0A0"
                    value: motorDetails.Reserved0A0
                    onValueChanged: motorDetails.setReserved0A0(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Reserved 0A1"
                    value: motorDetails.Reserved0A1
                    onValueChanged: motorDetails.setReserved0A1(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Motor Temp"
                    value: motorDetails.MotorTemp
                    onValueChanged: motorDetails.setMotorTemp(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Heatsink Temp"
                    value: motorDetails.HeatsinkTemp
                    onValueChanged: motorDetails.setHeatsinkTemp(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Dsp Board Temp"
                    value: motorDetails.DspBoardTemp
                    onValueChanged: motorDetails.setDspBoardTemp(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Reserved Dsp Board Temp"
                    value: motorDetails.ReservedDspBoardTemp
                    onValueChanged: motorDetails.setReservedDspBoardTemp(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Reserved 0D0"
                    value: motorDetails.Reserved0D0
                    onValueChanged: motorDetails.setReserved0D0(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Reserved 0D1"
                    value: motorDetails.Reserved0D1
                    onValueChanged: motorDetails.setReserved0D1(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Odometer"
                    value: motorDetails.Odometer
                    onValueChanged: motorDetails.setOdometer(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "DC Bus Ah"
                    value: motorDetails.DCBusAh
                    onValueChanged: motorDetails.setDCBusAh(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Slip Speed"
                    value: motorDetails.SlipSpeed
                    onValueChanged: motorDetails.setSlipSpeed(value)
                    max: 2147483647
                }

                IntSpinBox {
                    text: "Reserved Slip Speed"
                    value: motorDetails.ReservedSlipSpeed
                    onValueChanged: motorDetails.setReservedSlipSpeed(value)
                    max: 2147483647
                }
            }
        }
    }
}
