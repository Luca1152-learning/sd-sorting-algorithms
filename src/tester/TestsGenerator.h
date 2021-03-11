#ifndef SORTARISD_TESTSGENERATOR_H
#define SORTARISD_TESTSGENERATOR_H


#include <vector>

using namespace std;

class TestsGenerator {
public:
    static vector<int> generateRandomValues(int size, int maxValue);

    static vector<int> generateAscendingValues(int size);

    static vector<int> generateDescendingValues(int size);

    static vector<int> generateIdenticalValues(int size, int value = 1000000);

    static vector<int> generateAscendingSawValues(int size, int maxValue = 1000000);

    static vector<int> generateDescendingSawValues(int size, int maxValue = 1000000);
};


#endif //SORTARISD_TESTSGENERATOR_H
