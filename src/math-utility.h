#ifndef MATHUTILITY_H
#define MATHUTILITY_H
#include <iostream>
#include <vector>

using namespace std;

class MathUtility {
  private:
    int total_cost;  // total of costs
    int defaultCost;  // dafault cost
    vector<int> notAllocatedJobs;  // number of not allocated jobs
    vector< vector<int> > costMatrix;  // jobs cost
    vector< vector<int> > solution;  // solution

  public:
    MathUtility();
    MathUtility(
      vector<int> notAllocatedJob,
      int defaultCost,
      vector< vector<int> > costMatrix,
      vector< vector<int> > solution
    );

    int getTotalCost();
};

#endif // MATHUTILITY_H