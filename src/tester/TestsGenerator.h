#ifndef SORTARISD_TESTSGENERATOR_H
#define SORTARISD_TESTSGENERATOR_H


#include <vector>

using namespace std;

class TestsGenerator {
public:
    static vector<int> generateRandomValues(int size, int maxAbsValue, int seed);
};


#endif //SORTARISD_TESTSGENERATOR_H
