#include "RadixSort.h"

void RadixSort::sort(vector<int> &values) const {
    for (int bitIndex = 0; bitIndex < sizeof(values[0]) * 8; bitIndex++) {
        bucketSort(values, bitIndex);
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