#include "Counters.h"

#include <iostream>

void Counters::addAssignment()
{
    ++_assignments;
}

void Counters::addCompare()
{
    ++_compares;
}

void Counters::addSwap()
{
    ++_swaps;
}

void Counters::addReading()
{
    ++_readings;
}


void Counters::printToStream(std::ostream& stream) const
{
    std::cout.imbue(std::locale(""));
    stream << "readings=" << _readings
           << ", compares=" << _compares
           << ", assignments=" << _assignments
           << ", swaps=" << _swaps;
}

std::ostream& std::operator<<(std::ostream& stream, const Counters& counters)
{
    counters.printToStream(stream);
    return stream;
}
