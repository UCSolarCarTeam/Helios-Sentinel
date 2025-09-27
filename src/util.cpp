#include "util.h"

Util::Util(QObject *parent)
    : QObject{parent}
{}

QByteArray Util::encodeByteStream(QByteArray bs){
    return 0;
}

QByteArray Util::generateChecksum(QByteArray bs, int bodyStartIndex, int bodyEndIndex){
    return 0;
}

QByteArray Util::formatInt(int num, int bytes){
    return 0;
}

QByteArray Util::formatFloat(float num){
    return 0;
}
