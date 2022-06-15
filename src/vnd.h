#ifndef VND_H
#define VND_H
#include <iostream>
#include <vector>

using namespace std;

class VND {
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
        VND();
        VND(
            int jobsNumber,
            int serversNumber,
            int defaultCost,
            vector<int> serversTimeCapacity,
            vector< vector<int> > timeMatrix,
            vector< vector<int> > costMatrix,
            vector< vector<int> > solution,
            vector<int> notAllocatedJobs
        );

        void execute(int r);
        int swap(); // TODO
        int insertionSort(); // TODO
};

#endif // VND_H