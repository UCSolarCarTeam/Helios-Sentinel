#include "util.h"

Util::Util(QObject *parent)
    : QObject{parent}
{}

QByteArray Util::encodeByteStream(QByteArray bs){
    QByteArray encoded(bs);
    int lastIndex = 0;
    int nextIndex = encoded.indexOf('\0', lastIndex);

    while (nextIndex != -1) {
        char distance = nextIndex - lastIndex;
        //qDebug() << "ENCODING: Index" << lastIndex << "with" << QString::number(distance);
        encoded[lastIndex] = distance;

        lastIndex = nextIndex; // Move to the next byte after the null byte
        nextIndex = encoded.indexOf('\0', lastIndex+1);
    }

    // Set the last byte to 0x00
    encoded.back() = '\0';

    //qDebug() << "ENCODED: " << encoded;

    return encoded;
}

QByteArray Util::generateChecksum(QByteArray bs, int bodyStartIndex, int bodyEndIndex){
    quint16 checksum = qChecksum(bs.mid(bodyStartIndex,bodyEndIndex));
    QByteArray checksumHex(reinterpret_cast<const char*>(&checksum), sizeof(checksum));
    //qDebug() << "First element of checksumArray: " << QString::number(static_cast<unsigned char>(checksumHex.at(0)), 16);
    return checksumHex;
}
