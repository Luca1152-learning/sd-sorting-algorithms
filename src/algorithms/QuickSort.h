#ifndef SORTARISD_QUICKSORT_H
#define SORTARISD_QUICKSORT_H


#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm {
public:
    void sort(vector<int> &v) const override;
};


#endif //SORTARISD_QUICKSORT_H
