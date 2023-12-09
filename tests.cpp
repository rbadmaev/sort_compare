#include "LoggedValue.h"
#include "bubbleSort.hpp"
#include "stlSort.hpp"

#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using Int = LoggedValue<int>;
using sortInt = std::function<void(std::vector<Int>&)>;

template <typename T>
std::ostream& operator<<(std::ostream& stream, std::vector<T> vector)
{
    for (auto value : vector) {
        stream << value << ",";
    }

    return stream;
}


bool testForInt(std::string_view testName,
                std::string_view sortName,
                const std::vector<Int>& data,
                sortInt sort)
{
    auto tested = data;
    Counters testedCounters;
    LoggedValueBase::setCounters(testedCounters);
    sort(tested);
    std::cout << "\n"
              << sortName << ": " << testedCounters << "\n";

    const bool success = std::is_sorted(tested.begin(), tested.end());
    if (!success) {
        std::cout << "data: " << data << "\n";
        std::cout << "sorted: " << tested << "\n";
    }

    std::cout << testName << " for " << sortName << ": " << (success ? "SUCCESS" : "FAILED") << std::endl;
    return success;
}


int randInt(int min = 0, int max = 1000)
{
    static thread_local auto engine = std::default_random_engine{std::random_device{}()};
    std::uniform_int_distribution<int> dis(min, max);
    return dis(engine);
}

std::vector<Int> generateData(size_t size)
{
    std::vector<Int> data;
    data.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        data.emplace_back(randInt(0, size * 100));
    }

    return data;
}

bool inplaceForSize(std::string_view sortName, const std::vector<Int>& data, sortInt sort)
{
    return testForInt("Inplace sort of size " + std::to_string(data.size()),
                      sortName,
                      data,
                      sort);
}


int main(int argc, char const* argv[])
{
    bool success = true;

    const std::vector<size_t> sizes = {10, 100, 1000, 10000};
    for (const auto size : sizes) {
        std::cout << "\n=================== " << size << " ========================";
        const auto data = generateData(size);
        success &= inplaceForSize("Bubble sort", data, bubbleSort<Int>);
        success &= inplaceForSize("Bubble stop sort", data, bubbleStopSort<Int>);
        success &= inplaceForSize("STL sort", data, stlSort<Int>);
    }

    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
