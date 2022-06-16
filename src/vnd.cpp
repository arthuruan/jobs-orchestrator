#include "vnd.h"
#include <vector>
#include <algorithm>
#include<algorithm> // for copy() and assign()
#include<iterator> // for back_inserter

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

void swapArray(vector<int> &vector1, int element1, vector<int> &vector2, int element2) {
    int temp;
    temp = vector1[element1];
    vector1[element1] = vector2[element2];
    vector2[element2] = temp;
}

VND::swapIndexes VND::validateSwap(vector<int> vector1, int element1, vector<int> vector2, int element2, int indexLine1, int indexLine2, int totalCost) {
    swapIndexes swapIndexes;

    int oldJob1 = vector1[element1];
    int oldJob2 = vector2[element2];

    swapArray(vector1, element1, vector2, element2);

    int newJob1 = vector1[element1];
    int newJob2 = vector2[element2];

    int server1TimeCapactity = serversTimeCapacity[indexLine1];
    int server2TimeCapactity = serversTimeCapacity[indexLine2];

    int timeServer1 = timeMatrix[indexLine1][element1];
    int timeServer2 = timeMatrix[indexLine2][element2];

    int currentCost = 0;

    if (timeServer1 < server1TimeCapactity && timeServer1 < server2TimeCapactity) {

        currentCost = totalCost - costMatrix[indexLine1][oldJob1] - costMatrix[indexLine2][oldJob2] + costMatrix[indexLine1][newJob1] + costMatrix[indexLine2][newJob2];

        if (currentCost < totalCost) {
            swapIndexes.serverIndex1 = indexLine1;
            swapIndexes.jobIndex1 = element1;
            swapIndexes.serverIndex2 = indexLine2;
            swapIndexes.jobIndex2 = element2;
            swapIndexes.cost = currentCost;
        } else {
            swapIndexes.serverIndex1 = -1;
            swapIndexes.jobIndex1 = -1;
            swapIndexes.serverIndex2 = -1;
            swapIndexes.jobIndex2 = -1;
            swapIndexes.cost = currentCost;
        }
    }
    return swapIndexes;
}

int VND::swap(int totalCost) {
    vector< vector<int> > aux;
    copy(solution.begin(), solution.end(), back_inserter(aux));

    swapIndexes bestIndexes;
    bestIndexes.serverIndex1 = -1;
    bestIndexes.jobIndex1 = -1;
    bestIndexes.serverIndex2 = -1;
    bestIndexes.jobIndex2 = -1;
    bestIndexes.cost = totalCost;

    for (int i = 0; i < aux.size(); i++) {
        for (int j = 0; j < aux[i].size(); j++) {
            if (i != aux[i].size() - 1) {
                for (int k = 0; k < aux[i + 1].size(); k++) {
                    swapIndexes currentIndexes = validateSwap(aux[i], j, aux[i + 1], k, i, i + 1, totalCost);
                    if (currentIndexes.cost < bestIndexes.cost) {
                        bestIndexes = currentIndexes;
                    }
                }
            }
        }
    }

    if (bestIndexes.serverIndex1 != -1) {
        swapArray(solution[bestIndexes.serverIndex1], bestIndexes.jobIndex1, solution[bestIndexes.serverIndex2], bestIndexes.jobIndex2);
    }

    return bestIndexes.cost;
}

int VND::insertionSort() {
    // TODO
    return 1;
}

void VND::execute(int r) {
    int k = 1;
    int totalCost = 200;
    int bestCost = totalCost;

    while(k <= r) {
        cout << "gain: " << gain << endl;
        switch (k) {
            case 1:
                bestCost = swap(bestCost);
                break;
            case 2:
                bestCost = insertionSort();
                break;
        }

        if (gain > totalCost) {
            k++;
        } else {
            k = 1;
        }
    }

}

