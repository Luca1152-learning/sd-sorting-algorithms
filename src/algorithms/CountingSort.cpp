#include "CountingSort.h"

void CountingSort::sort(vector<int> &values) const {
    auto minMaxPair = minmax_element(begin(values), end(values));
    int minValue = *minMaxPair.first, maxValue = *minMaxPair.second;

    if (minValue < 0) {
        throw runtime_error("The Counting Sort algorithm can't sort negative elements.");
    }

    vector<int> count(maxValue + 1);
    for (auto value : values) {
        count[value] += 1;
    }

    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count[i]; j++) {
            values[index++] = i;
        }
    }
}
