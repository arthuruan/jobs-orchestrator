#include "vnd.h"
#include <vector>
#include <algorithm>
#include<algorithm>
#include<iterator>

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

int calculateLineTime(vector<int> vec, int serverNumber, vector< vector<int> > timeMatrixParam) {
    int time = 0;
    for (int i = 0; i < vec.size(); i++) {
        time += timeMatrixParam[serverNumber][vec[i]];
    }
    return time;
}

int calculateTotalCost(
    vector< vector<int> >solutionParam,
    vector< vector<int> > costMatrixParam,
    vector<int> notAllocatedJobParam,
    int defaultCost
) {
    int totalCost = 0;
    for (int i = 0; i < solutionParam.size(); i++) {
        for (int j = 0; j < solutionParam[i].size(); j++) {
            totalCost += costMatrixParam[i][solutionParam[i][j]];
        }
    }

    return totalCost + defaultCost * notAllocatedJobParam.size();
}

VND::swapIndexes VND::validateSwap(vector<int> vector1, int element1, vector<int> vector2, int element2, int indexLine1, int indexLine2, int totalCost) {
    swapIndexes swapIndexes;

    swapIndexes.serverIndex1 = -1;
    swapIndexes.jobIndex1 = -1;
    swapIndexes.serverIndex2 = -1;
    swapIndexes.jobIndex2 = -1;
    swapIndexes.cost = totalCost;

    int oldJob1 = vector1[element1];
    int oldJob2 = vector2[element2];

    swapArray(vector1, element1, vector2, element2);

    int newJob1 = vector1[element1];
    int newJob2 = vector2[element2];

    int server1TimeCapactity = serversTimeCapacity[indexLine1];
    int server2TimeCapactity = serversTimeCapacity[indexLine2];

    int timeServer1 = calculateLineTime(vector1, indexLine1, timeMatrix);
    int timeServer2 = calculateLineTime(vector2, indexLine2, timeMatrix);

    int currentCost = 0;

    if (timeServer1 <= server1TimeCapactity && timeServer1 <= server2TimeCapactity) {
        currentCost = totalCost - costMatrix[indexLine1][oldJob1] - costMatrix[indexLine2][oldJob2] + costMatrix[indexLine1][newJob1] + costMatrix[indexLine2][newJob2];

        swapIndexes.serverIndex1 = indexLine1;
        swapIndexes.jobIndex1 = element1;
        swapIndexes.serverIndex2 = indexLine2;
        swapIndexes.jobIndex2 = element2;
        swapIndexes.cost = currentCost;
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

void reInsertionArray(vector<int> &vector1, int element1, vector<int> &vector2) {
    int temp;
    temp = vector1[element1];

    vector<int>::iterator it;
    it = vector1.begin();
    
    vector1.erase(it + element1);
    vector2.push_back(temp);
}

VND::reInsertionIndexes VND::validateReInsertion(vector<int> vector1, int element1, vector<int> vector2, int indexLine1, int indexLine2, int totalCost) {
    reInsertionIndexes reInsertionIndexes;

    reInsertionIndexes.serverIndex1 = -1;
    reInsertionIndexes.jobIndex1 = -1;
    reInsertionIndexes.serverIndex2 = -1;
    reInsertionIndexes.cost = totalCost;

    reInsertionArray(vector1, element1, vector2);

    int nextServerTimeCapactity = serversTimeCapacity[indexLine2];

    int elementTimeSize = calculateLineTime(vector2, indexLine2, timeMatrix);

    int currentCost = 0;

    if (elementTimeSize <= nextServerTimeCapactity) {
        currentCost = totalCost - costMatrix[indexLine1][element1] + costMatrix[indexLine2][element1];

        if (currentCost < totalCost) {
            reInsertionIndexes.serverIndex1 = indexLine1;
            reInsertionIndexes.jobIndex1 = element1;
            reInsertionIndexes.serverIndex2 = indexLine2;
            reInsertionIndexes.cost = currentCost;
        }
    }
    return reInsertionIndexes;
}

int VND::reInsertion(int totalCost) {
    vector< vector<int> > aux;
    copy(solution.begin(), solution.end(), back_inserter(aux));

    reInsertionIndexes bestIndexes;
    bestIndexes.serverIndex1 = -1;
    bestIndexes.jobIndex1 = -1;
    bestIndexes.serverIndex2 = -1;
    bestIndexes.cost = totalCost;

    for (int i = 0; i < aux.size(); i++) { //passa nos servidores
        for (int j = 0; j < aux[i].size(); j++) {  //passa nos jobs
            for (int k = i+1; k < aux.size(); k++) {
                reInsertionIndexes currentIndexes = validateReInsertion(aux[i], j, aux[k], i, k, totalCost);
                if (currentIndexes.cost < bestIndexes.cost) {
                    bestIndexes = currentIndexes;
                }
            }
        }
    }

    if (bestIndexes.serverIndex1 != -1) {
        reInsertionArray(solution[bestIndexes.serverIndex1], bestIndexes.jobIndex1, solution[bestIndexes.serverIndex2]);
    }

    return bestIndexes.cost;
}

void VND::execute(int r) {
    int k = 1;
    int bestCost = calculateTotalCost(
        solution,
        costMatrix,
        notAllocatedJobs,
        defaultCost
    );
    int currentCost = bestCost;

    while(k <= r) {
        switch (k) {
            case 1:
                currentCost = reInsertion(bestCost);
                break;
            case 2:
                currentCost = swap(bestCost);
                break;
        }

        if (currentCost >= bestCost) {
            k++;
        } else {
            bestCost = currentCost;
            k = 1;
        }
    }
}

vector< vector<int> > VND::getSolution() {
    return solution;
}

vector<int> VND::getNotAllocatedJobs() {
    return notAllocatedJobs;
}

void VND::printSolution() {
    for(int i = 0; i < solution.size(); i++){
        for(int j = 0; j < solution[i].size(); j++){
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}