#include "util.h"

Util::Util(QObject *parent)
    : QObject{parent}
{}

QByteArray Util::encodeByteStream(QByteArray bs) {
    QByteArray encodedByteStream(bs); // creates a copy of bs called encodedByteStream

    int cur = 0;
    int next = encodedByteStream.indexOf('\0', cur); // finds index of the first \0 starting from position cur

    // loop continues as long as there is a \0 in the byte stream
    while (next != -1) {
        char distance = next - cur;

        encodedByteStream[cur] = distance; // replaces byte at position cur with the calculate distance

        cur = next;
        next = encodedByteStream.indexOf('\0', cur + 1); // finds next \0
    }

    encodedByteStream.back() = '\0'; // sets last byte to \0

    return encodedByteStream;
}

QByteArray Util::generateChecksum(QByteArray bs, int bodyStartIndex, int bodyEndIndex){
    // ensure bodyEndIndex is greater than or equal to bodyStartIndex, if not, return empty array of bytes
    if (bodyEndIndex < bodyStartIndex) {
        return QByteArray(1, 0x00);
    }

    int length = bodyEndIndex - bodyStartIndex + 1;

    // extract the portion of interest from the byte array
    QByteArray portion = bs.mid(bodyStartIndex, length);

    quint16 checksum = qChecksum(portion.constData(), portion.size());

    // convert checksum to hexadeciaml QByteArray
    QByteArray checksumHex;

    checksumHex.append(static_cast<char>(checksum & 0xFF));
    checksumHex.append(static_cast<char>((checksum >> 8) & 0xFF));

    return checksumHex;
}

QByteArray Util::formatInt(int num, int bytes){
    QByteArray formatted;

    for(int i = 0; i < bytes; ++i) {
        formatted.append(static_cast<char>((num >> (8 * i)) & 0xFF));
    }

    return formatted;
}

QByteArray Util::formatFloat(float num){
    return QByteArray(1, 0x00);
}
