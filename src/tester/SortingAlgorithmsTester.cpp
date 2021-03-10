#include <iostream>
#include "SortingAlgorithmsTester.h"
#include "TestsGenerator.h"

using namespace std;
using namespace std::chrono;

void SortingAlgorithmsTester::testSortingAlgorithms() {
    // Test the algorithms on randomly generated vectors
    testAlgorithmOnRandomValues(
            BubbleSort(),
            {1000, 1000000, 1000000000}, {1000, 5000, 10000, 50000, 100000, 200000, 300000}
    );
}

void SortingAlgorithmsTester::testAlgorithmOnRandomValues(
        const SortingAlgorithm &algorithm,
        const vector<int> &maxValues, const vector<int> &sizes
) {
    for (auto maxValue : maxValues) {
        for (auto size : sizes) {
            vector<int> values = TestsGenerator::generateRandomValues(size, maxValue, 0);
            double time = testAlgorithmOnInput(algorithm, values);
            cout << typeid(algorithm).name() << " algorithm - random values (size=" << size << ", maxValue=" << maxValue
                 << "): " << time << "s\n";
            cout.flush();
        }
    }
}

double SortingAlgorithmsTester::testAlgorithmOnInput(const SortingAlgorithm &algorithm, const vector<int> &values) {
    double sorting_time = getAlgorithmRunTime(algorithm, values);
    return sorting_time;
}

double SortingAlgorithmsTester::getAlgorithmRunTime(const SortingAlgorithm &algorithm, vector<int> v) {
    auto start = high_resolution_clock::now();
    algorithm.sort(v);
    return (float) duration_cast<nanoseconds>(high_resolution_clock::now() - start).count() / 1e9;
}



