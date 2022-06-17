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

        struct swapIndexes {
            int serverIndex1, serverIndex2, jobIndex1, jobIndex2, cost;
        };

        struct reInsertionIndexes {
            int serverIndex1, serverIndex2, jobIndex1, cost;
        };

        void execute(int r);
        int swap(int totalCost);
        int reInsertion(int totalCost); // TODO
        swapIndexes validateSwap(vector<int> vector1, int element1, vector<int> vector2, int element2, int indexLine1, int indexLine2, int totalCost);
        reInsertionIndexes validateReInsertion(vector<int> vector1, int element1, vector<int> vector2, int indexLine1, int indexLine2, int totalCost);

        vector< vector<int> > getSolution();
        vector<int> getNotAllocatedJobs();

        void printSolution();
};

#endif // VND_H