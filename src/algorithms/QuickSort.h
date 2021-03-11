#ifndef SORTARISD_QUICKSORT_H
#define SORTARISD_QUICKSORT_H


#include <random>
#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm {
public:
    QuickSort();

    void sort(vector<int> &values) const override;

    static void quickSort(vector<int> &values, int left, int right);

    static int partition(vector<int> &values, int left, int right);
};


#endif //SORTARISD_QUICKSORT_H
