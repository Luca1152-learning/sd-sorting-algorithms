#ifndef SORTARISD_SORTINGALGORITHMSTESTER_H
#define SORTARISD_SORTINGALGORITHMSTESTER_H


#include "../algorithms/SortingAlgorithm.h"
#include "../algorithms/BubbleSort.h"
#include <unordered_map>

class SortingAlgorithmsTester {
public:
    static void testSortingAlgorithms();

private:
    // Random values
    static void testAlgorithmsOnRandomValues();

    static void testAlgorithmOnRandomValues(
            const SortingAlgorithm &algorithm, const vector<int> &maxValues, const vector<int> &sizes
    );

    // Ascending values
    static void testAlgorithmsOnAscendingValues();

    static void testAlgorithmOnAscendingValues(const SortingAlgorithm &algorithm, const vector<int> &sizes);

    // Descending values
    static void testAlgorithmsOnDescendingValues();

    static void testAlgorithmOnDescendingValues(const SortingAlgorithm &algorithm, const vector<int> &sizes);

    // Identical values
    static void testAlgorithmsOnIdenticalValues();

    static void testAlgorithmOnIdenticalValues(const SortingAlgorithm &algorithm, const vector<int> &sizes);

    // Ascending saw values
    static void testAlgorithmsOnAscendingSawValues();

    static void testAlgorithmOnAscendingSawValues(const SortingAlgorithm &algorithm, const vector<int> &sizes);

    // Descending saw values
    static void testAlgorithmsOnDescendingSawValues();

    static void testAlgorithmOnDescendingSawValues(const SortingAlgorithm &algorithm, const vector<int> &sizes);

    // Tester's logic
    static double testAlgorithmOnInputAndGetRunTime(const SortingAlgorithm &algorithm, const vector<int> &values);

    static double sortAndGetAlgorithmRunTime(const SortingAlgorithm &algorithm, vector<int> &values);

    static bool vectorsHaveSameValues(const vector<int> &valuesA, const vector<int> &valuesB);

    static unordered_map<int, int> getAppearancesCountMap(const vector<int> &values);
};


#endif //SORTARISD_SORTINGALGORITHMSTESTER_H
