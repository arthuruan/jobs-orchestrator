#include <iostream>
#include <string>
#include "data.h"
#include "construction-heuristic.h"
#include "math-utility.h"
#include "vnd.h"

using namespace std;

int main (void) {
    Data data = Data("./instances/n60m10.txt");

    data.printJobsNumber();
    data.printServersNumber();
    data.printDefaultCost();
    cout << endl;
    data.printServersCapacity();
    cout << endl;
    data.printTimeMatrix();
    cout << endl;
    data.printCostMatrix();

    ConstructionHeuristic ch = ConstructionHeuristic(
        data.getJobsNumber(),
        data.getServersNumber(),
        data.getDefaultCost(),
        data.getServersCapacity(),
        data.getTimeMatrix(),
        data.getCostMatrix()
    );
    VND vnd = VND(
        data.getJobsNumber(),
        data.getServersNumber(),
        data.getDefaultCost(),
        data.getServersCapacity(),
        data.getTimeMatrix(),
        data.getCostMatrix(),
        ch.getSolution(),
        ch.getNotAllocatedJobs()
    );

    vnd.execute(2);

    // MathUtility mu = MathUtility(
    //     ch.getNotAllocatedJobs(),
    //     ch.getDefaultCost(),
    //     data.getCostMatrix(),
    //     ch.getSolution()
    // );

    // print data
    // for (int i = 0; i < ch.getSolution().size(); i++) {
    //     for (int j = 0; j < ch.getSolution()[i].size(); j++) {
    //         cout << ch.getSolution()[i][j] << " ";
    //     }
    //     cout << " " <<endl;
    // }

    // cout << "notAllocated: " << ch.getNotAllocatedJobs() << endl;
    // cout << "Custo Total: " << mu.getTotalCost() << endl;

    return 0;
}