#ifndef SORTARISD_SORTINGALGORITHM_H
#define SORTARISD_SORTINGALGORITHM_H

#include <vector>

using namespace std;

class SortingAlgorithm {
public:
    virtual void sort(vector<int> &values) const = 0;

};


#endif //SORTARISD_SORTINGALGORITHM_H
