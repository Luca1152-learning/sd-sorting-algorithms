#ifndef SORTARISD_SORTINGALGORITHMSTESTER_H
#define SORTARISD_SORTINGALGORITHMSTESTER_H


#include "../algorithms/SortingAlgorithm.h"
#include "../algorithms/BubbleSort.h"
#include <unordered_map>

class SortingAlgorithmsTester {
public:
    static void testSortingAlgorithms();

private:
    static void testAlgorithmsOnRandomValues();

    static void testAlgorithmOnRandomValues(
            const SortingAlgorithm &algorithm, const vector<int> &maxValues, const vector<int> &sizes
    );

    static void testAlgorithmsOnAscendingValues();

    static void testAlgorithmOnAscendingValues(const SortingAlgorithm &algorithm, const vector<int> &sizes);

    static void testAlgorithmsOnDescendingValues();

    static void testAlgorithmOnDescendingValues(const SortingAlgorithm &algorithm, const vector<int> &sizes);

    static double testAlgorithmOnInputAndGetRunTime(const SortingAlgorithm &algorithm, const vector<int> &values);

    static double sortAndGetAlgorithmRunTime(const SortingAlgorithm &algorithm, vector<int> &values);

    static bool vectorsHaveSameValues(const vector<int> &valuesA, const vector<int> &valuesB);

    static unordered_map<int, int> getAppearancesCountMap(const vector<int> &values);
};


#endif //SORTARISD_SORTINGALGORITHMSTESTER_H
