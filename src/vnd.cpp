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

struct bestIndexes {
    int serverIndex1;
    int serverIndex2;
    int jobIndex1;
    int jobIndex2;
};

bool VND::validateSwap(vector<int> vector1, int element1, vector<int> vector2, int element2, int indexLine1, int indexLine2, int totalCost) {

    bestIndexes bestIndexes;

    int oldJob1 = vector1[element1];
    int oldJob2 = vector2[element2];

    swapArray(vector1, element1, vector2, element2);

    int newJob1 = vector1[element1];
    int newJob2 = vector2[element2];

    cout << "oldJob1: " << oldJob1 << " oldJob2: " << oldJob2 << endl;
    cout << "newJob1: " << newJob1 << " newJob2: " << newJob2 << endl;

    int server1TimeCapactity = serversTimeCapacity[indexLine1];
    int server2TimeCapactity = serversTimeCapacity[indexLine2];

    int timeServer1 = timeMatrix[indexLine1][element1];
    int timeServer2 = timeMatrix[indexLine2][element2];

    int currentCost = 0;

    if (timeServer1 < server1TimeCapactity && timeServer1 < server2TimeCapactity) {

        currentCost = totalCost - costMatrix[indexLine1][oldJob1] - costMatrix[indexLine2][oldJob2] + costMatrix[indexLine1][newJob1] + costMatrix[indexLine2][newJob2];

        if (currentCost < totalCost) {
            cout << "better cost: " <<  currentCost << endl;
        } else {
            cout << "worse cost: " <<  currentCost << endl;
        }

        return true;
    }
    return false;
}

int VND::swap(int totalCost) {
    // TODO
    vector< vector<int> > aux;
    copy(solution.begin(), solution.end(), back_inserter(aux));

    // for (int i = 0; i < solution.size(); i++) {
    //     for (int j = 0; j < solution[i].size(); j++) {
    //         cout << solution[i][j] << " ";
    //     }
    //     cout << " " <<endl;
    // }

    int bestCost = totalCost;

    for (int i = 0; i < aux.size(); i++) {
        for (int j = 0; j < aux[i].size(); j++) {
            // cout << aux[i][j] << " ";
            if (i != aux[i].size() - 1) {
                for (int k = 0; k < aux[i + 1].size(); k++) {
                    // cout << aux[i + 1][k] << " ";
                    bool isValid = validateSwap(aux[i], j, aux[i + 1], k, i, i + 1, totalCost);
                    if (isValid) {
                        // swapArray(aux[i], j, aux[i + 1], k);

                        // int oldJob1 = solution[i][j];
                        // int oldJob2 = solution[i + 1][k];

                        // int newJob1 = aux[i][j];
                        // int newJob2 = aux[i + 1][k];

                        // bestCost = bestCost - costMatrix[i][oldJob1] - costMatrix[i + 1][oldJob2] + costMatrix[i][newJob1] + costMatrix[i + 1][newJob2];

                        // // cout << "oldJob1: " << oldJob1 << " oldJob2: " << oldJob2 << endl;
                        // // cout << "newJob1: " << newJob1 << " newJob2: " << newJob2 << endl;

                        // cout << "total time:" << totalCost <<endl;
                        // cout << "total time aux:" << bestCost <<endl;

                        // cout << "----------------------------------------------------" << endl;

                    }

                }
            }
        }
        // cout << " " <<endl;
    }

    cout << "bestCost: " << bestCost << endl;
    cout << "totalCost: " << totalCost << endl;


    // for (int i = 0; i < aux.size(); i++) {
    //     for (int j = 0; j < aux[i].size(); j++) {
    //         cout << aux[i][j] << " ";
    //     }
    //     cout << " " <<endl;
    // }

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
                gain = swap(200);
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

