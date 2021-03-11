#include <random>
#include <iostream>
#include "TestsGenerator.h"

vector<int> TestsGenerator::generateRandomValues(int size, int maxValue) {
    // Prerequisites
    random_device randomDevice;
    mt19937 generator(0); // The seed is constant to keep the same random values between tests
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

vector<int> TestsGenerator::generateIdenticalValues(int size, int value) {
    vector<int> values(size);
    for (int i = 0; i < size; i++) {
        values[i] = value;
    }
    return values;
}

vector<int> TestsGenerator::generateAscendingSawValues(int size, int maxValue) {
    vector<int> values = generateRandomValues(size, maxValue);
    sort(values.begin() + 0 * size / 4, values.begin() + 1 * size / 4);
    sort(values.begin() + 1 * size / 4, values.begin() + 2 * size / 4);
    sort(values.begin() + 2 * size / 4, values.begin() + 3 * size / 4);
    sort(values.begin() + 3 * size / 4, values.begin() + 4 * size / 4);
    return values;
}

vector<int> TestsGenerator::generateDescendingSawValues(int size, int maxValue) {
    vector<int> values = generateRandomValues(size, maxValue);
    sort(values.begin() + 0 * size / 4, values.begin() + 1 * size / 4, greater<int>());
    sort(values.begin() + 1 * size / 4, values.begin() + 2 * size / 4, greater<int>());
    sort(values.begin() + 2 * size / 4, values.begin() + 3 * size / 4, greater<int>());
    sort(values.begin() + 3 * size / 4, values.begin() + 4 * size / 4, greater<int>());
    return values;
}