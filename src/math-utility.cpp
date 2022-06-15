#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "math-utility.h"
#include <vector>

using namespace std;

MathUtility::MathUtility(
  int notAllocatedJob,
  int defaultCost,
  vector< vector<int> > costMatrix,
  vector< vector<int> > solution
  ) {
  this->costMatrix = costMatrix;
  this->solution = solution;
  this->defaultCost = defaultCost;

  int total_cost = 0;

  for (int i = 0; i < solution.size(); i++) {
    for (int j = 0; j < solution[i].size(); j++) {
      cout << "SERVIDOR: " << i + 1 << endl;
      cout << "Job: " << solution[i][j] << " ";
      cout << endl;
      if(costMatrix.size() > i) {
        cout << "Custo: " << costMatrix[i][solution[i][j]] << endl;
        cout << endl;

        total_cost += costMatrix[i][solution[i][j]];
      }    
    } 
  }

  total_cost += (defaultCost * notAllocatedJob);
  this->total_cost = total_cost;
}

int MathUtility::getTotalCost() {
  return total_cost;
}



