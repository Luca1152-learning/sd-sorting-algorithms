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
#include "../algorithms/CppSort.h"

using namespace std;
using namespace std::chrono;
using namespace std::string_literals;

void SortingAlgorithmsTester::testSortingAlgorithms() {
    vector<SortingAlgorithm *> algorithmsToTest = {
            new CppSort(), new QuickSort(), new MergeSort(), new RadixSort(), new CountingSort(), new BubbleSort()
    };
    vector<TestsGenerator::TestType> testTypes = {
            TestsGenerator::TestType::RANDOM_VALUES, TestsGenerator::TestType::ASCENDING_VALUES,
            TestsGenerator::TestType::DESCENDING_VALUES, TestsGenerator::TestType::IDENTICAL_VALUES,
            TestsGenerator::TestType::ASCENDING_SAW_VALUES, TestsGenerator::TestType::DESCENDING_SAW_VALUES
    };
    vector<int> sizesToTest = {1000, 5000, 10000, 50000, 100000, 200000, 300000, 500000, 1000000};

    for (auto &algorithm : algorithmsToTest) {
        for (auto &testType: testTypes) {
            auto maxValues = (testType == TestsGenerator::TestType::RANDOM_VALUES) ?
                             vector<int>{1000, 1000000, 1000000000} : vector<int>{1000000};
            for (auto maxValue : maxValues) {
                for (auto size : sizesToTest) {
                    // Test each algorithm (except Bubble Sort) repeatedly
                    int testsCount = (algorithm != algorithmsToTest.back()) ? 10 : 1;

                    vector<double> times(testsCount);
                    for (int testNumber = 0; testNumber < testsCount; testNumber++) {
                        vector<int> values = TestsGenerator::generateTest(testType, size, maxValue);
                        times[testNumber] = testAlgorithmOnInputAndGetRunTime(*algorithm, values);
                    }

                    double avgTime = accumulate(times.begin(), times.end(), 0.0) / times.size();
                    cout << TestsGenerator::enumToString(testType) << " - "
                         << fixed << setprecision(3) << typeid(*algorithm).name()
                         << " algorithm (maxValue=" << maxValue << ", size=" << size << ") - " << avgTime << "s";
                    if (testsCount != 1) {
                        cout << " avg. (" << testsCount << " tests)";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            cout << "\n\n";
        }
    }

    for (auto &algorithm : algorithmsToTest) {
        delete algorithm;
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
    return (double) duration_cast<nanoseconds>(high_resolution_clock::now() - start).count() / 1e9;
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