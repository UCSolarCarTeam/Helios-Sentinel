#include "Setting.h"

Setting::Setting(QObject *parent)
    : QObject{parent}
{
    bool isElysia() {return isElysia_;}

    void setIsElysia(bool value) {
        isElysia_ = value;
        emit isElysiaChanged(isElysia_);
    };
}
