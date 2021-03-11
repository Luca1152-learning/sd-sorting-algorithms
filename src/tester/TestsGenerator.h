#ifndef SORTARISD_TESTSGENERATOR_H
#define SORTARISD_TESTSGENERATOR_H


#include <vector>
#include <map>

using namespace std;

class TestsGenerator {
public:
    enum TestType {
        RANDOM_VALUES,
        ASCENDING_VALUES,
        DESCENDING_VALUES,
        IDENTICAL_VALUES,
        ASCENDING_SAW_VALUES,
        DESCENDING_SAW_VALUES
    };

    static string enumToString(TestType testType);

    static vector<int> generateTest(TestType testType, int size, int maxValue = 1000000);

private:
    static inline map<const TestType, const string> m_enumToString = {
            {RANDOM_VALUES,         "RANDOM VALUES"},
            {ASCENDING_VALUES,      "ASCENDING VALUES"},
            {DESCENDING_VALUES,     "DESCENDING VALUES"},
            {IDENTICAL_VALUES,      "IDENTICAL VALUES"},
            {ASCENDING_SAW_VALUES,  "ASCENDING SAW VALUES"},
            {DESCENDING_SAW_VALUES, "DESCENDING SAW VALUES"},
    };

    static vector<int> generateRandomValues(int size, int maxValue);

    static vector<int> generateAscendingValues(int size);

    static vector<int> generateDescendingValues(int size);

    static vector<int> generateIdenticalValues(int size, int value);

    static vector<int> generateAscendingSawValues(int size, int maxValue);

    static vector<int> generateDescendingSawValues(int size, int maxValue);
};


#endif //SORTARISD_TESTSGENERATOR_H
