#pragma once

#include <iosfwd>

class Counters {
public:
    void addAssignment();
    void addCompare();
    void addSwap();
    void addReading();

    void printToStream(std::ostream&) const;

private:
    unsigned _assignments = 0;
    unsigned _compares = 0;
    unsigned _swaps = 0;
    unsigned _readings = 0;
};

namespace std {
    std::ostream& operator<<(std::ostream&, const Counters&);
}
