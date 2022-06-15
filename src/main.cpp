#include <iostream>
#include <string>
#include "data.h"
#include "construction-heuristic.h"
#include "math-utility.h"

using namespace std;

int main (void) {
    Data data = Data("./instances/n5m15A.txt");
    ConstructionHeuristic ch = ConstructionHeuristic(
        data.getJobsNumber(),
        data.getServersNumber(),
        data.getDefaultCost(),
        data.getServersCapacity(),
        data.getTimeMatrix(),
        data.getCostMatrix()
    );
    MathUtility mu = MathUtility(
        ch.getNotAllocatedJobs(),
        ch.getDefaultCost(),
        data.getCostMatrix(),
        ch.getSolution()
    );

    // print data
    for (int i = 0; i < ch.getSolution().size(); i++) {
        for (int j = 0; j < ch.getSolution()[i].size(); j++) {
            cout << ch.getSolution()[i][j] << " ";
        }
        cout << " " <<endl;
    }

    // cout << "notAllocated: " << ch.getNotAllocatedJobs() << endl;


    cout << "Custo Total: " << mu.getTotalCost() << endl;

    return 0;
}