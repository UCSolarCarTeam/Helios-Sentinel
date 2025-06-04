import QtQuick 2.15

Item {
    width: 550
    height: 1250

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20

        Text {
            text: "Contactors Packet"
            font.family: "Verdana"
            font.bold: true
        }

        Column {
            spacing: 20

            /** COMMON CONTACTOR */
            FlagBox {
                title: "Common"
                flags: [
                    {
                        text: "Precharger Closed",
                        checked: contactors.CommonIsPrechargerClosed,
                        onClicked: function(checked) { contactors.setCommonIsPrechargerClosed(checked) }
                    },
                    {
                        text: "Precharger Closing",
                        checked: contactors.CommonIsPrechargerClosing,
                        onClicked: function(checked) { contactors.setCommonIsPrechargerClosing(checked) }
                    },
                    {
                        text: "Precharger Error",
                        checked: contactors.CommonPrechargerError,
                        onClicked: function(checked) { contactors.setCommonPrechargerError(checked) }
                    },
                    {
                        text: "Contactor Closed",
                        checked: contactors.CommonIsContactorClosed,
                        onClicked: function(checked) { contactors.setCommonIsContactorClosed(checked) }
                    },
                    {
                        text: "Contactor Closing",
                        checked: contactors.CommonIsContactorClosing,
                        onClicked: function(checked) { contactors.setCommonIsContactorClosing(checked) }
                    },
                    {
                        text: "Contactor Error",
                        checked: contactors.CommonContactorError,
                        onClicked: function(checked) { contactors.setCommonContactorError(checked) }
                    },
                    {
                        text: "Contactor Opening Error",
                        checked: contactors.CommonContactorOpeningError,
                        onClicked: function(checked) { contactors.setCommonContactorOpeningError(checked) }
                    }
                ]
            }

            Row {
                spacing: 20
                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Line Current"
                        value: contactors.CommonLineCurrent
                        onValueChanged: contactors.setCommonLineCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
                
                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Charge Current"
                        value: contactors.CommonChargeCurrent
                        onValueChanged: contactors.setCommonChargeCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
            }

            /** MOTOR CONTACTOR */
            FlagBox {
                title: "Motor"
                flags: [
                    {
                        text: "Precharger Closed",
                        checked: contactors.MotorIsPrechargerClosed,
                        onClicked: function(checked) { contactors.setMotorIsPrechargerClosed(checked) }
                    },
                    {
                        text: "Precharger Closing",
                        checked: contactors.MotorIsPrechargerClosing,
                        onClicked: function(checked) { contactors.setMotorIsPrechargerClosing(checked) }
                    },
                    {
                        text: "Precharger Error",
                        checked: contactors.MotorPrechargerError,
                        onClicked: function(checked) { contactors.setMotorPrechargerError(checked) }
                    },
                    {
                        text: "Contactor Closed",
                        checked: contactors.MotorIsContactorClosed,
                        onClicked: function(checked) { contactors.setMotorIsContactorClosed(checked) }
                    },
                    {
                        text: "Contactor Closing",
                        checked: contactors.MotorIsContactorClosing,
                        onClicked: function(checked) { contactors.setMotorIsContactorClosing(checked) }
                    },
                    {
                        text: "Contactor Error",
                        checked: contactors.MotorContactorError,
                        onClicked: function(checked) { contactors.setMotorContactorError(checked) }
                    },
                    {
                        text: "BPS Error",
                        checked: contactors.MotorBpsError,
                        onClicked: function(checked) { contactors.setMotorBpsError(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Line Current"
                        value: contactors.MotorLineCurrent
                        onValueChanged: contactors.setMotorLineCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
                
                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Charge Current"
                        value: contactors.MotorChargeCurrent
                        onValueChanged: contactors.setMotorChargeCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
            }

            /** ARRAY CONTACTOR */
            FlagBox {
                title: "Array"
                flags: [
                    {
                        text: "Precharger Closed",
                        checked: contactors.ArrayIsPrechargerClosed,
                        onClicked: function(checked) { contactors.setArrayIsPrechargerClosed(checked) }
                    },
                    {
                        text: "Precharger Closing",
                        checked: contactors.ArrayIsPrechargerClosing,
                        onClicked: function(checked) { contactors.setArrayIsPrechargerClosing(checked) }
                    },
                    {
                        text: "Precharger Error",
                        checked: contactors.ArrayPrechargerError,
                        onClicked: function(checked) { contactors.setArrayPrechargerError(checked) }
                    },
                    {
                        text: "Contactor Closed",
                        checked: contactors.ArrayIsContactorClosed,
                        onClicked: function(checked) { contactors.setArrayIsContactorClosed(checked) }
                    },
                    {
                        text: "Contactor Closing",
                        checked: contactors.ArrayIsContactorClosing,
                        onClicked: function(checked) { contactors.setArrayIsContactorClosing(checked) }
                    },
                    {
                        text: "Contactor Error",
                        checked: contactors.ArrayContactorError,
                        onClicked: function(checked) { contactors.setArrayContactorError(checked) }
                    },
                    {
                        text: "BPS Error",
                        checked: contactors.ArrayBpsError,
                        onClicked: function(checked) { contactors.setArrayBpsError(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Line Current"
                        value: contactors.ArrayLineCurrent
                        onValueChanged: contactors.setArrayLineCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
                
                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Charge Current"
                        value: contactors.ArrayChargeCurrent
                        onValueChanged: contactors.setArrayChargeCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
            }

            /** LV CONTACTOR */
            FlagBox {
                title: "LV"
                flags: [
                    {
                        text: "Precharger Closed",
                        checked: contactors.LvIsPrechargerClosed,
                        onClicked: function(checked) { contactors.setLvIsPrechargerClosed(checked) }
                    },
                    {
                        text: "Precharger Closing",
                        checked: contactors.LvIsPrechargerClosing,
                        onClicked: function(checked) { contactors.setLvIsPrechargerClosing(checked) }
                    },
                    {
                        text: "Precharger Error",
                        checked: contactors.LvPrechargerError,
                        onClicked: function(checked) { contactors.setLvPrechargerError(checked) }
                    },
                    {
                        text: "Contactor Closed",
                        checked: contactors.LvIsContactorClosed,
                        onClicked: function(checked) { contactors.setLvIsContactorClosed(checked) }
                    },
                    {
                        text: "Contactor Closing",
                        checked: contactors.LvIsContactorClosing,
                        onClicked: function(checked) { contactors.setLvIsContactorClosing(checked) }
                    },
                    {
                        text: "Contactor Error",
                        checked: contactors.LvContactorError,
                        onClicked: function(checked) { contactors.setLvContactorError(checked) }
                    },
                    {
                        text: "BPS Error",
                        checked: contactors.LvBpsError,
                        onClicked: function(checked) { contactors.setLvBpsError(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Line Current"
                        value: contactors.LvLineCurrent
                        onValueChanged: contactors.setLvLineCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
                
                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Charge Current"
                        value: contactors.LvChargeCurrent
                        onValueChanged: contactors.setLvChargeCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
            }

            /** CHARGE CONTACTOR */
            FlagBox {
                title: "Charge"
                flags: [
                    {
                        text: "Precharger Closed",
                        checked: contactors.ChargeIsPrechargerClosed,
                        onClicked: function(checked) { contactors.setChargeIsPrechargerClosed(checked) }
                    },
                    {
                        text: "Precharger Closing",
                        checked: contactors.ChargeIsPrechargerClosing,
                        onClicked: function(checked) { contactors.setChargeIsPrechargerClosing(checked) }
                    },
                    {
                        text: "Precharger Error",
                        checked: contactors.ChargePrechargerError,
                        onClicked: function(checked) { contactors.setChargePrechargerError(checked) }
                    },
                    {
                        text: "Contactor Closed",
                        checked: contactors.ChargeIsContactorClosed,
                        onClicked: function(checked) { contactors.setChargeIsContactorClosed(checked) }
                    },
                    {
                        text: "Contactor Closing",
                        checked: contactors.ChargeIsContactorClosing,
                        onClicked: function(checked) { contactors.setChargeIsContactorClosing(checked) }
                    },
                    {
                        text: "Contactor Error",
                        checked: contactors.ChargeContactorError,
                        onClicked: function(checked) { contactors.setChargeContactorError(checked) }
                    },
                    {
                        text: "BPS Error",
                        checked: contactors.ChargeBpsError,
                        onClicked: function(checked) { contactors.setChargeBpsError(checked) }
                    }
                ]
            }

            Row {
                spacing: 20

                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Line Current"
                        value: contactors.ChargeLineCurrent
                        onValueChanged: contactors.setChargeLineCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
                
                Column {
                    spacing: 20

                    IntSpinBox {
                        text: "Charge Current"
                        value: contactors.ChargeChargeCurrent
                        onValueChanged: contactors.setChargeChargeCurrent(value)
                        min: 0
                        max: 4095
                    }
                }
            }
        }
    }
}
