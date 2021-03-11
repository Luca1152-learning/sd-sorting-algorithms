#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include "SortingAlgorithmsTester.h"
#include "TestsGenerator.h"
#include "../algorithms/CountingSort.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/QuickSort.h"
#include "../algorithms/RadixSort.h"

using namespace std;
using namespace std::chrono;
using namespace std::string_literals;

void SortingAlgorithmsTester::testSortingAlgorithms() {
    // Test the algorithms on randomly generated vectors
    testAlgorithmOnRandomValues(
            BubbleSort(),
            {1000, 1000000, 1000000000}, {1000, 5000, 10000, 50000, 100000, 200000, 300000}
    );
    testAlgorithmOnRandomValues(
            CountingSort(),
            {1000, 1000000, 1000000000},
            {1000, 5000, 10000, 50000, 100000, 200000, 300000, 500000, 1000000});
    testAlgorithmOnRandomValues(
            MergeSort(),
            {1000, 1000000, 1000000000},
            {1000, 5000, 10000, 50000, 100000, 200000, 300000, 500000, 1000000});
    testAlgorithmOnRandomValues(
            QuickSort(),
            {1000, 1000000, 1000000000},
            {1000, 5000, 10000, 50000, 100000, 200000, 300000, 500000, 1000000}
    );
    testAlgorithmOnRandomValues(
            RadixSort(),
            {1000, 1000000, 1000000000},
            {1000, 5000, 10000, 50000, 100000, 200000, 300000, 500000, 1000000}
    );
}

void SortingAlgorithmsTester::testAlgorithmOnRandomValues(
        const SortingAlgorithm &algorithm,
        const vector<int> &maxValues, const vector<int> &sizes
) {
    for (auto maxValue : maxValues) {
        for (auto size : sizes) {
            vector<int> values = TestsGenerator::generateRandomValues(size, maxValue, 0);
            double time = testAlgorithmOnInputAndGetRunTime(algorithm, values);

            cout << fixed << setprecision(3) << typeid(algorithm).name()
                 << " algorithm - random values (maxValue=" << maxValue << ", size=" << size << "): " << time << "s\n";
            cout.flush();
        }
    }
}

double SortingAlgorithmsTester::testAlgorithmOnInputAndGetRunTime(
        const SortingAlgorithm &algorithm, const vector<int> &values
) {
    vector<int> sortedValues(values);
    double sortingTime = sortAndGetAlgorithmRunTime(algorithm, sortedValues);

    if (not is_sorted(sortedValues.begin(), sortedValues.end()) or not vectorsHaveSameValues(values, sortedValues)) {
        throw logic_error("The sorting algorithm " + string(typeid(algorithm).name()) + " had an incorrect output.");
    }

    return sortingTime;
}

double SortingAlgorithmsTester::sortAndGetAlgorithmRunTime(const SortingAlgorithm &algorithm, vector<int> &values) {
    auto start = high_resolution_clock::now();
    algorithm.sort(values);
    return (float) duration_cast<nanoseconds>(high_resolution_clock::now() - start).count() / 1e9;
}

bool SortingAlgorithmsTester::vectorsHaveSameValues(const vector<int> &valuesA, const vector<int> &valuesB) {
    if (valuesA.size() != valuesB.size()) {
        return false;
    }

    // Create maps with the number of appearances for each element in the two vectors
    auto mapA = getAppearancesCountMap(valuesA), mapB = getAppearancesCountMap(valuesB);

    // The two vectors don't have the same values if the number of appearances for one element differs
    for (auto &pair : mapA) {
        if (mapB[pair.first] != pair.second) {
            return false;
        }
    }

    return true;
}

unordered_map<int, int> SortingAlgorithmsTester::getAppearancesCountMap(const vector<int> &values) {
    unordered_map<int, int> map;
    for (auto &value : values) {
        if (map.count(value) == 0) {
            map.insert({value, 1});
        } else {
            map[value]++;
        }
    }
    return map;
}