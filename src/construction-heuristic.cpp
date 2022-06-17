#include "construction-heuristic.h"
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortArr(vector<int> vect, int n) {
    vector<int> sortedIndexesVect;
    // Vector to store element
    // with respective present index
    vector<pair<int, int> > vp;
  
    // Inserting element in pair vector
    // to keep track of previous indexes
    for (int i = 0; i < n; ++i) {
        vp.push_back(make_pair(vect[i], i));
    }
  
    // Sorting pair vector
    sort(vp.begin(), vp.end());
  
    // push just the index of element
    for (int i = 0; i < vp.size(); i++) {
        sortedIndexesVect.push_back(vp[i].second);
    }

    return sortedIndexesVect;
}

bool contains(vector< vector<int> > vec, const int & elem) {
    bool result = false;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == elem) {
                result = true;
                break;
            }
        }
        if (result) {
            break;
        }
    }
    return result;
}

ConstructionHeuristic::ConstructionHeuristic(
    int jobsNumber,
    int serversNumber,
    int defaultCost,
    vector<int> serversTimeCapacity,
    vector< vector<int> > timeMatrix,
    vector< vector<int> > costMatrix
) {
    this->jobsNumber = jobsNumber;
    this->serversNumber = serversNumber;
    this->defaultCost = defaultCost;
    this->serversTimeCapacity = serversTimeCapacity;
    this->timeMatrix = timeMatrix;
    this->costMatrix = costMatrix;

    int indexServer = 0;

    vector<int> notAllocatedJobs;
    vector<int> serverSolution;
    bool areServersFull = false;

    int timeUsed = 0;

    for (int i = 0; i < jobsNumber; i++) {
        int timeServerCapacity = serversTimeCapacity[indexServer];

        vector<int> lineSolution;
        vector<int> sortedLineIndexes;

        lineSolution = timeMatrix[indexServer];

        sortedLineIndexes = sortArr(lineSolution, lineSolution.size());


        for (int j = 0; j < sortedLineIndexes.size(); j++) {
            int aux = timeUsed + timeMatrix[indexServer][sortedLineIndexes[j]];

            if (aux <= timeServerCapacity) {
                bool isAlreadyIn = contains(this->solution, sortedLineIndexes[j]);
                
                if (!isAlreadyIn) {
                    serverSolution.push_back(sortedLineIndexes[j]);
                    timeUsed += timeMatrix[indexServer][sortedLineIndexes[j]];
                }
            }
        }

        timeUsed = 0;

        this->solution.push_back(serverSolution);
        serverSolution.clear();

        // end of the matrix
        if (indexServer == serversNumber - 1) {
            break;
        } else {
            indexServer++;
        }
    }

    for (int i = 0; i < jobsNumber; i++) {
        if (!contains(this->solution, i)) {
            notAllocatedJobs.push_back(i);
        }
    }

    this->notAllocatedJobs = notAllocatedJobs;
}


int ConstructionHeuristic::getJobsNumber() {
    return jobsNumber;
}

int ConstructionHeuristic::getServersNumber() {
    return serversNumber;
}

int ConstructionHeuristic::getDefaultCost() {
    return defaultCost;
}

vector<int> ConstructionHeuristic::getServersTimeCapacity() {
    return serversTimeCapacity;
}

vector< vector<int> > ConstructionHeuristic::getTimeMatrix() {
    return timeMatrix;
}


vector< vector<int> > ConstructionHeuristic::getCostMatrix() {
    return costMatrix;
}

vector< vector<int> > ConstructionHeuristic::getSolution() {
    return solution;
}

vector<int> ConstructionHeuristic::getNotAllocatedJobs() {
    return notAllocatedJobs;
}

void ConstructionHeuristic::printSolution() {
    for(int i = 0; i < solution.size(); i++){
        for(int j = 0; j < solution[i].size(); j++){
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}