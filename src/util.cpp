#include "util.h"
#include  <QByteArrayView>
#include <QtCore/qglobal.h>

Util::Util(QObject *parent)
    : QObject{parent}
{}

QByteArray Util::encodeByteStream(QByteArray bs) {
    if (bs.isEmpty()) {
        return bs;
    }
    int firstZeroIndex = bs.indexOf(0x00, 1);
    if (firstZeroIndex != -1) {
        bs[0] = firstZeroIndex;
    } else {
        return bs;
    }
    int currentIndex = firstZeroIndex;
    while (true) {
        int nextZeroIndex = bs.indexOf(0x00, currentIndex + 1);
        if (nextZeroIndex == -1) {
            break;
        }
        bs[currentIndex] = nextZeroIndex - currentIndex;
        currentIndex = nextZeroIndex;
    }
    return bs;
}



QByteArray Util::generateChecksum(QByteArray bs, int bodyStartIndex, int bodyEndIndex){
    if(bodyStartIndex < 0 || bodyStartIndex > bodyEndIndex || bodyStartIndex >= bs.size()){
        return QByteArray(); //Returs empty QByteArray due to any invalid indices
    }
    // quint16 checkSum = qChecksum(bs.constData() + bodyStartIndex, section_length);
    // If use the above approach I get a "Warning" ->  ‘quint16 qChecksum(const char*, qsizetype, Qt::ChecksumType)’
    // is deprecated: Use the QByteArrayView overload. [-Wdeprecated-declarations]‘quint16 qChecksum(const char*, qsizetype, Qt::ChecksumType)’ is deprecated: Use the QByteArrayView overload. [-Wdeprecated-declarations]
    int section_length = bodyEndIndex - bodyStartIndex + 1;
    QByteArrayView view(bs.constData() + bodyStartIndex, section_length);
    quint16 checkSum = qChecksum(view);
    QByteArray checkSumArray;
    checkSumArray.append(static_cast<char>((checkSum >> 8) & 0xFF));
    checkSumArray.append(static_cast<char>(checkSum & 0xFF));

    return checkSumArray;
    // return QByteArray(1, 0x00);
}

QByteArray Util::formatInt(int num, int bytes){
    QByteArray byteArray(bytes, 0);
    for(int i = 0; i <  bytes; i++){
        byteArray[i] =  static_cast<char>((num >> (i * 8)) & 0xFF);
    }
    return byteArray;
    // return QByteArray(1, 0x00);
}

QByteArray Util::formatFloat(float num){
    QByteArray byteArray(sizeof(float),0);
    const char* rawBytes = reinterpret_cast<const char*>(&num);
    for(int i = 0; i<sizeof(float);i++){
        byteArray[i] = rawBytes[i];
    }
    return  byteArray;
       // return QByteArray(1, 0x00);
}
