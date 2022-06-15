#include <iostream>
#include <string>
#include "data.h"
#include "construction-heuristic.h"

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

    // print data
    for (int i = 0; i < ch.getSolution().size(); i++) {
        for (int j = 0; j < ch.getSolution()[i].size(); j++) {
            cout << ch.getSolution()[i][j] << " ";
        }
        cout << " " <<endl;
    }

    cout << "notAllocated: " << ch.getNotAllocatedJobs() << endl;

    return 0;
}