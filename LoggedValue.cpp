#include "LoggedValue.h"

Counters* LoggedValueBase::_counters = nullptr;

void LoggedValueBase::setCounters(Counters& counters)
{
    _counters = &counters;
}

void LoggedValueBase::addAssignment()
{
    if (_counters)
        _counters->addAssignment();
}

void LoggedValueBase::addCompare()
{
    if (_counters)
        _counters->addCompare();
}

void LoggedValueBase::addSwap()
{
    if (_counters)
        _counters->addSwap();
}

void LoggedValueBase::addReading()
{
    if (_counters)
        _counters->addReading();
}
