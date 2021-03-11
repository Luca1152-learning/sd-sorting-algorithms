#include <random>
#include <iostream>
#include "TestsGenerator.h"

vector<int> TestsGenerator::generateRandomValues(int size, int maxValue) {
    // Prerequisites
    random_device randomDevice;
    mt19937 generator(0);
    uniform_int_distribution<unsigned long long> distribution(0, maxValue);

    // Actually generate the vector
    vector<int> values(size);
    for (auto &value : values) {
        value = distribution(generator);
    }
    return values;
}

vector<int> TestsGenerator::generateAscendingValues(int size) {
    vector<int> values(size);
    for (int i = 0; i < size; i++) {
        values[i] = i;
    }
    return values;
}

vector<int> TestsGenerator::generateDescendingValues(int size) {
    vector<int> values(size);
    for (int i = 0; i < size; i++) {
        values[i] = size - i - 1;
    }
    return values;
}