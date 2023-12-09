#pragma once

#include "Counters.h"

#include <utility>

class LoggedValueBase {
public:
    static void setCounters(Counters&);

protected:
    static void addAssignment();
    static void addCompare();
    static void addSwap();
    static void addReading();

private:
    static Counters* _counters;
};


template <typename ValueType>
class LoggedValue : public LoggedValueBase {
public:
    LoggedValue(ValueType initial = ValueType())
        : _value(std::move(initial))
    {
        addAssignment();
    }

    explicit LoggedValue(const LoggedValue& other)
        : LoggedValue(ValueType(other))
    {
    }

    LoggedValue& operator=(const LoggedValue& other)
    {
        addAssignment();
        _value = ValueType(other);
        return *this;
    }

    operator ValueType() const
    {
        addReading();
        return _value;
    }

    bool operator<(const LoggedValue& other) const
    {
        addCompare();
        return ValueType(*this) < ValueType(other);
    }

    bool operator>(const LoggedValue& other) const = delete;

    void swap(LoggedValue& other)
    {
        addSwap();
        std::swap(_value, other._value);
    }

private:
    static Counters& _counters;
    ValueType _value;
};
