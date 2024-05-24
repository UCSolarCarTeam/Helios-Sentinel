#ifndef UTIL_H
#define UTIL_H

#include <QObject>

class Util : public QObject
{
    Q_OBJECT
public:
    explicit Util(QObject *parent = nullptr);

    static QByteArray encodeByteStream(QByteArray bs);
    static QByteArray generateChecksum(QByteArray bs, int bodyStartIndex, int bodyEndIndex);
    static QByteArray formatInt(int num, int bytes);

signals:
};

#endif // UTIL_H
