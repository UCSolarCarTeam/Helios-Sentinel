#include "util.h"

Util::Util(QObject *parent)
    : QObject{parent}
{}

QByteArray Util::encodeByteStream(QByteArray bs){
    return QByteArray(1, 0x00);
}

QByteArray Util::generateChecksum(QByteArray bs, int bodyStartIndex, int bodyEndIndex){

    return QByteArray(1, 0x00);
}

QByteArray Util::formatInt(int num, int bytes){
    return QByteArray(1, 0x00);
}

QByteArray Util::formatFloat(float num){
    return QByteArray(1, 0x00);
}
