import QtQuick 2.15
import QtQuick.Controls 2.15

SpinBox {
    property int decimals: 1
    readonly property int decimalFactor: Math.pow(10, decimals)

    function decimalToInt(decimal) {
        return decimal * decimalFactor
    }
    from:-2147483648
    to:2147483647
    editable:true

    validator: DoubleValidator {
        decimals: spinBox.decimals
        notation: DoubleValidator.StandardNotation
    }

    textFromValue: function(value, locale) {
        return Number(value / decimalFactor).toLocaleString(locale, 'f',1)
    }

    valueFromText: function(text, locale) {
        return Math.round(Number.fromLocaleString(locale, text) * decimalFactor)
    }
}

