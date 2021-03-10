#ifndef SORTARISD_SORTINGALGORITHMSTESTER_H
#define SORTARISD_SORTINGALGORITHMSTESTER_H


#include "../algorithms/SortingAlgorithm.h"
#include "../algorithms/BubbleSort.h"

class SortingAlgorithmsTester {
public:
    static void testSortingAlgorithms();

private:
    static double testAlgorithmOnInput(const SortingAlgorithm &algorithm, const vector<int> &values);

    static double getAlgorithmRunTime(const SortingAlgorithm &algorithm, vector<int> v);

    static void testAlgorithmOnRandomValues(
            const SortingAlgorithm &algorithm, const vector<int> &maxValues, const vector<int> &sizes
    );
};


#endif //SORTARISD_SORTINGALGORITHMSTESTER_H
