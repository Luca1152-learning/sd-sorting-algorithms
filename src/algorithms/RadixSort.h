#ifndef SORTARISD_RADIXSORT_H
#define SORTARISD_RADIXSORT_H


#include "SortingAlgorithm.h"

class RadixSort : public SortingAlgorithm {
public:
    void sort(vector<int> &values) const override;

    static void bucketSort(vector<int> &values, int bitIndex);

    static int getBitAtIndex(int value, int index);
};


#endif //SORTARISD_RADIXSORT_H
