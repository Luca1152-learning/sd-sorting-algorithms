#ifndef SORTARISD_BUBBLESORT_H
#define SORTARISD_BUBBLESORT_H


#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm {
public:
    void sort(vector<int> &v) const override;
};


#endif //SORTARISD_BUBBLESORT_H
