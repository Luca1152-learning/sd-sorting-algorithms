#include <random>
#include "TestsGenerator.h"

vector<int> TestsGenerator::generateRandomValues(int size, int maxValue, int seed) {
    // Prerequisites
    random_device randomDevice;
    mt19937 generator(seed);
    uniform_int_distribution<unsigned long long> distribution(0, maxValue);

    // Actually generate the vector
    vector<int> values(size);
    for (auto &value : values) {
        value = distribution(generator);
    }
    return values;
}
