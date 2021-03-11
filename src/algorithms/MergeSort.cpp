#include
<iostream>
#include
"MergeSort.h"

void MergeSort::sort(vector<int> &v) const {
mergeSort(v, 0, int(v.size()) - 1);
}

void MergeSort::mergeSort(vector<int> &values, int left, int right) {
if (left >= right) {
return;
    }

    int mid = (left + right) / 2;
    mergeSort(values, left, mid);
    mergeSort(values, mid + 1, right);
    merge(values, left, mid, right);
}

void MergeSort::merge(vector<int> &values, int left, int mid, int right) {
    int leftSize = mid - left + 1, rightSize = right - (mid + 1) + 1;
    vector<int> leftValues(leftSize), rightValues(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftValues[i] = values[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightValues[i] = values[mid + 1 + i];
    }

    int leftIndex = 0, rightIndex = 0, valuesIndex = left;
    while (leftIndex < leftSize and rightIndex < rightSize) {
        if (leftValues[leftIndex] <= rightValues[rightIndex]) {
            values[valuesIndex++] = leftValues[leftIndex++];
        } else {
            values[valuesIndex++] = rightValues[rightIndex++];
        }
    }

    while (leftIndex < leftSize) {
        values[valuesIndex++] = leftValues[leftIndex++];
    }
    while (rightIndex < rightSize) {
        values[valuesIndex++] = rightValues[rightIndex++];
    }
}
