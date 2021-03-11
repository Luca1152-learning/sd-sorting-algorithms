#ifndef SORTARISD_MERGESORT_H
#define SORTARISD_MERGESORT_H


#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm {
public:
    void sort(vector<int> &v) const override;

private:
    static void mergeSort(vector<int> &values, int left, int right);

    static void merge(vector<int> &values, int left, int mid, int right);
};


#endif //SORTARISD_MERGESORT_H
