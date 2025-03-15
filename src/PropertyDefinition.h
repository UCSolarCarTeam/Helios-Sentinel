#ifndef PROPERTYDEFINITION_H
#define PROPERTYDEFINITION_H
#include <QObject>
#include "util.h"


/**
 * Defines a Boolean Packet Attribute Property for QML integration.
 * Generates a Q_PROPERTY with a getter, setter, and signal for state tracking.
 * 
 * Parameters:
 * name - The property name, used to generate the getter, setter, and signal.
 * position - The byte index in byteStream_ where the property’s value is stored.
 * mask - A bitmask used to toggle a specific bit within the byte.
 * 
 * Functionality:
 * - Provides a getter (`name()`) to return the current value.
 * - Provides a setter (`setName(bool on)`) that modifies the specific bit at `position` using `mask`.
 * - Emits a signal (`name##Changed(bool)`) when the property changes.
 * - Calls `updateByteStream()` after modifying `byteStream_`.
 * - Defines a private boolean member (`name##_`) initialized to `false`.
 *
**/
#define DEFINE_BOOL(name, position, mask) \
Q_SIGNALS:\
    void name##Changed(bool on);\
private:\
    bool name##_ = false; \
\
public Q_SLOTS: \
    void set##name(bool on){\
            byteStream_[position] = on ? (byteStream_[position] | mask) : (byteStream_[position] & ~mask); \
            name##_ = on; \
            updateByteStream(); \
        }; \
public: \
Q_PROPERTY(bool name READ name WRITE set##name NOTIFY name##Changed);\
bool name() const {return name##_;}


/**
 * Defines int,unsigned char, unsigned int or short Packet Attribute Properties for linking of qml
 * Creates Q_PROPERTY with getter,setter, and signal.
 *
 * Parameters:
 * type - the expected type of this attribute parameter
 * name - The name of the property. This will be used to generate the getter, setter, and signal names.
 * position - The index of the byte in byteStream_ where the property’s value is stored.
 * size - The expected byte size of the type(ex int = 4).
 *
 * Defines:
 * public getter = name() which returns the current value of the private member variable
 * public setter setName(type value) which updates the specific bit in byteStream_ at the given position using the position and size.
 * private type name_ with default value of 0
 *
**/
#define DEFINE_WHOLE_NUMBER(type, name, position, size)\
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


/**
 * Defines float Packet Attribute Properties for linking ot qml
 * Creates Q_PROPERTY with getter,setter, and signal.
 *
 * Parameters:
 * type - the expected type of this Attribute parameter
 * name - The name of the property. This will be used to generate the getter, setter, and signal names.
 * position - The index of the byte in byteStream_ where the property’s value is stored.
 * size - The expected byte size of the type.
 *
 * Defines:
 * public getter = name() which returns the current value of the private member variable
 * public setter setName(bool on) which updates the specific bit in byteStream_ at the given position using the position and size.
 * private type name_ with default value of 0.0
 *
**/
#define DEFINE_FLOAT(type, name, position, size)\
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
