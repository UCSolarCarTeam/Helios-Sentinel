#ifndef SETTING_H
#define SETTING_H

#include <QObject>

class Setting : public QObject
{
    Q_OBJECT
public:
    explicit Setting(QObject *parent = nullptr);
    Q_PROPERTY(bool getIsElysia READ getIsElysia NOTIFY isElysiaChanged FINAL)

    bool getIsElysia() const {return isElysia_;};

signals:
    void isElysiaChanged(bool on);

public slots:
    void setIsElysia(bool value) {
        isElysia_ = value;
        emit isElysiaChanged(isElysia_);
    };

private:
    bool isElysia_ = false;
};

#endif // SETTING_H
