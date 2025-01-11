#ifndef PROPERTYDEFINITION_H
#define PROPERTYDEFINITION_H
#include <QObject>
#include "util.h"

/**
 *  Defines Boolean,Int (Unsigned Int),Float  Packet Attribute Properties for linking to qml
 *  Creates Q_PROPERY with getter, setter, and signal, as well as the
 *  private class var (type name_)
 *
 *  Defines:
 *  public getter Name()
 *  public setter setName(type)
 *  private var Name_
 *  public slot: void setName(type i)
 *  signals: void NameChanged(type i
 *
 *  Note that name should be capilized in current state to follow
 *  best naming conventions
*/

#define DEFINE_PROPERTY_BOOL(name, position, offset) \
Q_SIGNALS:\
    void name##Changed(bool on);\
private:\
    bool name##_ = false; \
\
public Q_SLOTS: \
    void set##name(bool on){\
            byteStream_[position] += on ? offset:-offset;\
            name##_ = on; \
            updateByteStream(); \
        }; \
public: \
Q_PROPERTY(bool name READ name WRITE set##name NOTIFY name##Changed);\
bool name() const {return name##_;} \


#define DEFINE_PROPERTY_INT(type, name, position, size)\
Q_SIGNALS:\
    void name##Changed(type on);\
    private:\
    type name##_ = 0; \
\
    public Q_SLOTS: \
    void set##name(type value) { \
        QByteArray in = Util::formatInt(value,size);\
        byteStream_.replace(position, size, in);\
        name##_ = value;\
        updateByteStream();\
}\
    public: \
    Q_PROPERTY(type name READ name WRITE set##name NOTIFY name##Changed);\
    type name() const {return name##_;}



#define DEFINE_PROPERTY_FLOAT(type, name, position, size)\
Q_SIGNALS:\
    void name##Changed(type on);\
    private:\
    type name##_ = 0.0; \
\
    public Q_SLOTS: \
    void set##name(type value) { \
        QByteArray in = Util::formatFloat(value);\
        byteStream_.replace(position, size, in);\
        name##_ = value;\
        updateByteStream();\
}\
    public: \
    Q_PROPERTY(type name READ name WRITE set##name NOTIFY name##Changed);\
    type name() const {return name##_;}


#endif // PROPERTYDEFINITION_H
