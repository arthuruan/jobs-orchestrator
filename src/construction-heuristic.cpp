#include "construction-heuristic.h"
#include <vector>
#include <algorithm>

using namespace std;

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
    int timeUsed = 0;
    vector<int> notAllocatedJobs;
    vector<int> serverSolution;
    bool areServersFull = false;

    // TODO: improve it
    for (int i = 0; i < jobsNumber; i++) {
        int timeServerCapacity = serversTimeCapacity[indexServer];

        int currentTimeUsed = timeUsed + timeMatrix[indexServer][i];

        if (areServersFull) {
            notAllocatedJobs.push_back(i);
        } else {
            if (currentTimeUsed < timeServerCapacity) {
                serverSolution.push_back(i);
                timeUsed += currentTimeUsed;
            } else {
                this->solution.push_back(serverSolution);

                if (indexServer == serversNumber - 1) {
                    areServersFull = true;
                } else {
                    indexServer++;
                }

                serverSolution.clear();
                serverSolution.push_back(i);
                timeUsed = 0;

                timeUsed += timeMatrix[indexServer][i];
            }
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