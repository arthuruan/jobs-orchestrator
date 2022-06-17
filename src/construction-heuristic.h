#ifndef CONSTRUCTIONHEURISTIC_H
#define CONSTRUCTIONHEURISTIC_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ConstructionHeuristic {
    private:
        int jobsNumber;  // number of jobs
        int serversNumber;  // number of servers
        int defaultCost;  // dafault cost
        vector<int> serversTimeCapacity; // servers time capacity
        vector< vector<int> > timeMatrix; // jobs time
        vector< vector<int> > costMatrix; // jobs cost

        vector< vector<int> > solution; // solution
        vector<int> notAllocatedJobs; // number of not allocated jobs

    public:
        ConstructionHeuristic();
        ConstructionHeuristic(
            int jobsNumber,
            int serversNumber,
            int defaultCost,
            vector<int> serversTimeCapacity,
            vector< vector<int> > timeMatrix,
            vector< vector<int> > costMatrix
        );

        int getJobsNumber();
        int getServersNumber();
        int getDefaultCost();
        vector<int> getServersTimeCapacity();
        vector< vector<int> > getTimeMatrix();
        vector< vector<int> > getCostMatrix();

        vector< vector<int> > getSolution();
        vector<int> getNotAllocatedJobs();

        void printSolution();
};

#endif // CONSTRUCTIONHEURISTIC_H