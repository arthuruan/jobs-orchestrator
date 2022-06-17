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

    // uncomment to test the data class

    // Data data = Data("./instances/n5m15A.txt"); 
    // Data data = Data("./instances/n5m15B.txt");
    // Data data = Data("./instances/n25m5A.txt"); 
    // Data data = Data("./instances/n30m5A.txt"); 
    // Data data = Data("./instances/n60m10.txt");
    Data data = Data("./instances/n60m10A.txt"); 

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
    
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Constructiion Heuristic Solution: " << endl;
    ch.printSolution();
    cout << "----------------------------------------" << endl;
    MathUtility muCh = MathUtility(
        ch.getNotAllocatedJobs(),
        ch.getDefaultCost(),
        data.getCostMatrix(),
        ch.getSolution()
    );

    cout << "Constructiion Heuristic Cost: " << muCh.getTotalCost() << endl;
    cout << "----------------------------------------" << endl;

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

    cout << "VND Solution: " << endl;
    vnd.printSolution();
    cout << "----------------------------------------" << endl;
    MathUtility muVnd = MathUtility(
        vnd.getNotAllocatedJobs(),
        data.getDefaultCost(),
        data.getCostMatrix(),
        vnd.getSolution()
    );

    cout << "VND Cost: " << muVnd.getTotalCost() << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is: " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}