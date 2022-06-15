#include "vnd.h"
#include <vector>
#include <algorithm>

using namespace std;

VND::VND(
    int jobsNumber,
    int serversNumber,
    int defaultCost,
    vector<int> serversTimeCapacity,
    vector< vector<int> > timeMatrix,
    vector< vector<int> > costMatrix,
    vector< vector<int> > solution,
    vector<int> notAllocatedJobs
) {
    this->jobsNumber = jobsNumber;
    this->serversNumber = serversNumber;
    this->defaultCost = defaultCost;
    this->serversTimeCapacity = serversTimeCapacity;
    this->timeMatrix = timeMatrix;
    this->costMatrix = costMatrix;
    this->solution = solution;
    this->notAllocatedJobs = notAllocatedJobs;
}

int VND::swap() {
    // TODO
    return 1;
}

int VND::insertionSort() {
    // TODO
    return 1;
}

void VND::execute(int r) {
    int k = 1;
    int gain = 0;

    while(k <= r) {
        switch (k) {
            case 1:
                gain = swap();
                break;
            case 2:
                gain = insertionSort();
                break;
            default:
                break;
        }

        if (gain > 0) {
            k++;
        } else {
            k = 1;
        }
    }

}

