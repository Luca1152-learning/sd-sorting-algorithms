#include <random>
#include "TestsGenerator.h"

vector<int> TestsGenerator::generateRandomValues(int size, int maxAbsValue, int seed) {
    // Prerequisites
    std::random_device randomDevice;
    std::mt19937 generator(seed);
    std::uniform_int_distribution<unsigned long long> distribution(-maxAbsValue, maxAbsValue);

    // Actually generate the vector
    vector<int> values(size);
    for (auto &value : values) {
        value = distribution(generator);
    }
    return values;
}
