#ifndef SORTARISD_SORTINGALGORITHMSTESTER_H
#define SORTARISD_SORTINGALGORITHMSTESTER_H


#include "../algorithms/SortingAlgorithm.h"
#include "../algorithms/BubbleSort.h"
#include <unordered_map>

class SortingAlgorithmsTester {
public:
    static void testSortingAlgorithms();

private:
    static double testAlgorithmOnInputAndGetRunTime(const SortingAlgorithm &algorithm, const vector<int> &values);

    static double sortAndGetAlgorithmRunTime(const SortingAlgorithm &algorithm, vector<int> &values);

    static void testAlgorithmOnRandomValues(
            const SortingAlgorithm &algorithm, const vector<int> &maxValues, const vector<int> &sizes
    );

    static bool vectorsHaveSameValues(const vector<int> &valuesA, const vector<int> &valuesB);

    static unordered_map<int, int> getAppearancesCountMap(const vector<int> &values);
};


#endif //SORTARISD_SORTINGALGORITHMSTESTER_H
