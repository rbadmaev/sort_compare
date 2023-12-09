#pragma once

#include <vector>

template <typename ValueT>
void bubbleSort(std::vector<ValueT>& data)
{
    for (size_t i = 0; i < data.size() - 1; ++i) {
        for (size_t j = 1; j < data.size() - i; ++j) {
            if (data[j] < data[j - 1]) {
                std::swap(data[j - 1], data[j]);
            }
        }
    }
}

template <typename ValueT>
void bubbleStopSort(std::vector<ValueT>& data)
{
    for (size_t i = 0; i < data.size() - 1; ++i) {
        bool isSorted = true;
        for (size_t j = 1; j < data.size() - i; ++j) {
            if (data[j] < data[j - 1]) {
                isSorted = false;
                std::swap(data[j - 1], data[j]);
            }
        }

        if (isSorted)
            return;
    }
}
