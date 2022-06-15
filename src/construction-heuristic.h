#ifndef CONSTRUCTIONHEURISTIC_H
#define CONSTRUCTIONHEURISTIC_H
#include <iostream>
#include <vector>

using namespace std;

class ConstructionHeuristic {
    private:
        int n;  // number of jobs
        int m;  // number of servers
        int p;  // dafault cost
        vector<int> b; // servers capacity
        vector< vector<int> > timeMatrix; // jobs time
        vector< vector<int> > costMatrix; // jobs cost

        vector< vector<int> > timeVsCost; // jobs time vs cost

        vector< vector<string> > solution; // solution

        int totalCost;
        int totalTime;

    public:
        ConstructionHeuristic();
        ConstructionHeuristic(
            int n,
            int m,
            int p,
            vector<int> b,
            vector< vector<int> > timeMatrix,
            vector< vector<int> > costMatrix
        );

        int getN();
        int getM();
        int getP();
        vector<int> getB();
        vector< vector<int> > getTimeMatrix();
        vector< vector<int> > getCostMatrix();
        vector< vector<int> > getTimeVsCost();

};

#endif // CONSTRUCTIONHEURISTIC_H