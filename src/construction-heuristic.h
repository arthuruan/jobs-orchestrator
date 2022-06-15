#ifndef CONSTRUCTIONHEURISTIC_H
#define CONSTRUCTIONHEURISTIC_H
#include <iostream>
#include <vector>

using namespace std;

class ConstructionHeuristic {
    private:
        int jobsNumber;  // number of jobs
        int serversNumber;  // number of servers
        int defaultCost;  // dafault cost
        vector<int> serversTimeCapacity; // servers time capacity
        vector< vector<int> > timeMatrix; // jobs time
        vector< vector<int> > costMatrix; // jobs cost

        vector< vector<int> > timeVsCost; // jobs time vs cost

        vector< vector<int> > solution; // solution
        int notAllocatedJobs; // number of not allocated jobs

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

        vector< vector<int> > getTimeVsCost();

        vector< vector<int> > getSolution();
        int getNotAllocatedJobs();
};

#endif // CONSTRUCTIONHEURISTIC_H