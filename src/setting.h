#ifndef SETTING_H
#define SETTING_H

#include <QObject>

class Setting : public QObject
{
    Q_OBJECT
public:
    explicit Setting(QObject *parent = nullptr);
    Q_PROPERTY(bool isElysia READ isElysia WRITE setIsElysia NOTIFY isElysiaChanged FINAL)

    bool isElysia() const {return isElysia_;}

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
