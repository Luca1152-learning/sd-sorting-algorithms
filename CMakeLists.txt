cmake_minimum_required(VERSION 3.17)
project(SortariSD)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortariSD src/main.cpp src/tester/SortingAlgorithmsTester.cpp src/tester/SortingAlgorithmsTester.h src/algorithms/SortingAlgorithm.h src/algorithms/QuickSort.cpp src/algorithms/QuickSort.h src/algorithms/BubbleSort.cpp src/algorithms/BubbleSort.h src/algorithms/BubbleSort.cpp src/algorithms/BubbleSort.h src/tester/TestsGenerator.cpp src/tester/TestsGenerator.h src/algorithms/CountingSort.cpp src/algorithms/CountingSort.h)