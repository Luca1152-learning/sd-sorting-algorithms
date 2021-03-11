#include <iostream>
#include "QuickSort.h"

QuickSort::QuickSort() {
    srand(time(nullptr));
}

void QuickSort::sort(vector<int> &values) const {
    quickSort(values, 0, int(values.size()) - 1);
}

void QuickSort::quickSort(vector<int> &values, int left, int right) {
    if (left >= right) {
        return;
    }
    int partitionMid = partition(values, left, right);
    quickSort(values, left, partitionMid - 1);
    quickSort(values, partitionMid, right);
}

int QuickSort::partition(vector<int> &values, int left, int right) {
    swap(values[rand() % (right - left + 1) + left], values[right]);
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (values[j] <= values[right]) {
            i++;
            swap(values[i], values[j]);
        }
    }
    swap(values[i + 1], values[right]);
    return i + 1;
}
