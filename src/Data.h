#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Data {
    private:
        string result;
        int n;  // number of jobs
        int m;  // number of servers
        int p;  // dafault cost
        vector<int> b; // servers capacity
        vector<int> x; // servers capacity
        vector< vector<int> > time; // jobs time
        vector< vector<int> > cost; // jobs cost

    public:
        Data();
        Data(string path);

        int getN();
        int getM();
        int getP();
        vector<int> getB();
        vector< vector<int> > getTime();
        vector< vector<int> > getCost();
};

#endif // DATA_H