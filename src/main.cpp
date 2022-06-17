#include <iostream>
#include <iomanip>
#include <string>
#include "data.h"
#include "construction-heuristic.h"
#include "math-utility.h"
#include "vnd.h"

using namespace std;

int main (void) {
    clock_t start, end;

    // Recording the starting clock tick.
    start = clock();

     Data data = Data("./instances/n5m15A.txt"); 
    // Data data = Data("./instances/n5m15B.txt");
    // Data data = Data("./instances/n25m5A.txt"); 
    // Data data = Data("./instances/n30m5A.txt"); 
    // Data data = Data("./instances/n60m10.txt"); 
    //Data data = Data("./instances/n60m10A.txt"); 

    // Print Data
    data.printJobsNumber();
    data.printServersNumber();
    data.printDefaultCost();
    cout << endl;
    data.printServersCapacity();
    cout << endl;
    data.printTimeMatrix();
    cout << endl;
    data.printCostMatrix();
    cout << endl;

    ConstructionHeuristic ch = ConstructionHeuristic(
        data.getJobsNumber(),
        data.getServersNumber(),
        data.getDefaultCost(),
        data.getServersCapacity(),
        data.getTimeMatrix(),
        data.getCostMatrix()
    );

    // VND vnd = VND(
    //     data.getJobsNumber(),
    //     data.getServersNumber(),
    //     data.getDefaultCost(),
    //     data.getServersCapacity(),
    //     data.getTimeMatrix(),
    //     data.getCostMatrix(),
    //     ch.getSolution(),
    //     ch.getNotAllocatedJobs()
    // );

    // vnd.execute(2);

    MathUtility mu = MathUtility(
        ch.getNotAllocatedJobs(),
        ch.getDefaultCost(),
        data.getCostMatrix(),
        ch.getSolution()
    );

    // cout << "notAllocated: " << ch.getNotAllocatedJobs() << endl;
    cout << "Custo Total: " << mu.getTotalCost() << endl;

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execução do peograma: " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}