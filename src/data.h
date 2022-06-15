#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Data {
    private:
        int n;  // number of jobs
        int m;  // number of servers
        int p;  // dafault cost
        vector<int> b; // servers capacity
        vector< vector<int> > timeMatrix; // jobs time
        vector< vector<int> > costMatrix; // jobs cost

    public:
        Data();
        Data(string path);

        int getN();
        int getM();
        int getP();
        vector<int> getB();
        vector< vector<int> > getTimeMatrix();
        vector< vector<int> > getCostMatrix();
};

#endif // DATA_H