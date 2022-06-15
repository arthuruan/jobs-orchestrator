#include "construction-heuristic.h"
#include <vector>

using namespace std;

ConstructionHeuristic::ConstructionHeuristic(
    int n,
    int m,
    int p,
    vector<int> b,
    vector< vector<int> > timeMatrix,
    vector< vector<int> > costMatrix
) {
    this->n = n;
    this->m = m;
    this->p = p;
    this->b = b;
    this->timeMatrix = timeMatrix;
    this->costMatrix = costMatrix;

    // calculate avarege vector of time and cost
    for (int i = 0; i < m; i++) {
        vector<int> timeVsCost;
        for (int j = 0; j < n; j++) {
            timeVsCost.push_back((timeMatrix[i][j] + costMatrix[i][j]) / 2);
        }
        this->timeVsCost.push_back(timeVsCost);
    }
}


int ConstructionHeuristic::getN() {
    return n;
}

int ConstructionHeuristic::getM() {
    return m;
}

int ConstructionHeuristic::getP() {
    return p;
}

vector<int> ConstructionHeuristic::getB() {
    return b;
}

vector< vector<int> > ConstructionHeuristic::getTimeMatrix() {
    return timeMatrix;
}


vector< vector<int> > ConstructionHeuristic::getCostMatrix() {
    return costMatrix;
}

vector< vector<int> > ConstructionHeuristic::getTimeVsCost() {
    return timeVsCost;
}
