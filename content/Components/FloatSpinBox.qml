import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: floatSpinBox
    width: text1.implicitWidth + spinBox.width + spinBox.anchors.leftMargin
    height: 25
    anchors.right: parent.right
    anchors.rightMargin: 0

    property int min : -2147483648
    property int max: 2147483647
    property bool isCustomRange: min !== -2147483648 || max !== 2147483647
    property int decimals: 1
    readonly property int decimalFactor: Math.pow(10, decimals)
    property real inputValue: 0.0
    property alias text: text1.text
    signal inputValueUpdated(real newValue)

    function decimalToInt(decimal) {
        return decimal * decimalFactor
    }

    Text {
        id: text1
        y: 4
        font.pixelSize: 14
    }

    SpinBox {
        id: spinBox
        width: 110
        height: 25
        font.pixelSize: 12
        from: isCustomRange ? min * decimalFactor : min
        to: isCustomRange? max * decimalFactor : max
        editable: true
        bottomPadding: 1
        topPadding: 1
        spacing: 5
        wheelEnabled: false
        rightPadding: 25
        leftPadding: 25
        anchors.left: text1.right
        anchors.leftMargin: 10

        validator: DoubleValidator {
            decimals: floatSpinBox.decimals
            notation: DoubleValidator.StandardNotation
        }

        textFromValue: function(value, locale) {
            return Number(value / floatSpinBox.decimalFactor).toLocaleString(locale, 'f', floatSpinBox.decimals)
        }

        valueFromText: function(text, locale) {
            return Math.round(Number.fromLocaleString(locale, text) * floatSpinBox.decimalFactor)
        }

        value: decimalToInt(floatSpinBox.inputValue)
        stepSize: decimalToInt(0.5)
        onValueChanged: {
            floatSpinBox.inputValue = value / floatSpinBox.decimalFactor
            floatSpinBox.inputValueUpdated(floatSpinBox.inputValue)
        }
    }
    
}
