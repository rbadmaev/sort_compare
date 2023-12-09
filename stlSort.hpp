#pragma once

#include <algorithm>
#include <vector>

template <typename ValueT>
void stlSort(std::vector<ValueT>& data)
{
    std::sort(data.begin(), data.end());
}
