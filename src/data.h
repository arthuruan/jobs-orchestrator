#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Data {
    private:
        int jobsNumber;  // number of jobs
        int serversNumber;  // number of servers
        int defaultCost;  // dafault cost
        vector<int> serversCapacity; // servers capacity
        vector< vector<int> > timeMatrix; // jobs time
        vector< vector<int> > costMatrix; // jobs cost

    public:
        Data();
        Data(string path);

        int getJobsNumber();
        int getServersNumber();
        int getDefaultCost();
        vector<int> getServersCapacity();
        vector< vector<int> > getTimeMatrix();
        vector< vector<int> > getCostMatrix();

        //print functions
        void printJobsNumber();
        void printServersNumber();
        void printDefaultCost();
        void printServersCapacity();
        void printTimeMatrix();
        void printCostMatrix();
};

#endif // DATA_H