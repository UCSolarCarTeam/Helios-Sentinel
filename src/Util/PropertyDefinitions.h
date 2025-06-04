#ifndef PROPERTYDEFINITIONS_H
#define PROPERTYDEFINITIONS_H

#define DEFINE_PROPERTY(type, name, id)                                     \
Q_PROPERTY(type name READ get##name WRITE set##name NOTIFY name##Changed)   \
public:                                                                     \
    type get##name() const { return name##_; }                              \
public Q_SLOTS:                                                             \
    void set##name(type value){                                             \
        name##_ = value;                                                    \
    }                                                                       \
    void send##name##Message(){                                             \
        sendCanMessage(id, name##_);                                        \
    }                                                                       \
Q_SIGNALS:                                                                  \
    void name##Changed(type newValue);                                      \
private:                                                                    \
    type name##_ = 0;


#define SUB_PROPERTY(type, name, parent, mask, offset)                                      \
Q_PROPERTY(type name READ get##name WRITE set##name NOTIFY name##Changed)                   \
public:                                                                                     \
    type get##name() const { return name##_; }                                              \
public Q_SLOTS:                                                                             \
    void set##name(type value) {                                                            \
        name##_ = value;                                                                    \
        constexpr int parsedOffset = (sizeof(parent##_) * 8 - offset - sizeof(type) * 8);   \
        if constexpr (std::is_same<type, float>::value){                                    \
            uint32_t ieee;                                                                  \
            std::memcpy(&ieee, &value, sizeof(float));                                      \
            parent##_ &= ~mask;                                                             \
            parent##_ |= (static_cast<decltype(parent##_)>(ieee) << parsedOffset);          \
        } else if constexpr (std::is_same<type, bool>::value){                              \
            if(value) parent##_ |= mask;                                                    \
            else parent##_ &= ~mask;                                                        \
        } else{                                                                             \
            parent##_ = (parent##_ & ~(mask << parsedOffset)) |                             \
                        (static_cast<decltype(parent##_)>(value) << parsedOffset);          \
        }                                                                                   \
    }                                                                                       \
Q_SIGNALS:                                                                                  \
    void name##Changed(type newValue);                                                      \
private:                                                                                    \
    type name##_ = 0;


#endif // PROPERTYDEFINITIONS_H
