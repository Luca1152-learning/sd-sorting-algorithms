#include "RadixSort.h"

void RadixSort::sort(vector<int> &values) const {
    int msbIndex = sizeof(values[0]) * 8 - 1;
    for (int bitIndex = 0; bitIndex <= msbIndex; bitIndex++) {
        bucketSort(values, bitIndex);
    }
    if (getBitAtIndex(values.back(), msbIndex) == 1) {
        throw logic_error("Vectors with negative values aren't supported by RadixSort.");
    }
}

void RadixSort::bucketSort(vector<int> &values, int bitIndex) {
    vector<vector<int>> buckets(2);
    for (auto value : values) {
        buckets[getBitAtIndex(value, bitIndex)].push_back(value);
    }
    int valuesIndex = 0;
    for (auto bucket : buckets) {
        for (auto bucketValue : bucket) {
            values[valuesIndex++] = bucketValue;
        }
    }
}

int RadixSort::getBitAtIndex(int value, int index) {
    return ((value & (1 << index)) ? 1 : 0);
}