#ifndef SORTARISD_COUNTINGSORT_H
#define SORTARISD_COUNTINGSORT_H


#include "SortingAlgorithm.h"

class CountingSort : public SortingAlgorithm {
public:
    void sort(vector<int> &values) const override;
};


#endif //SORTARISD_COUNTINGSORT_H
