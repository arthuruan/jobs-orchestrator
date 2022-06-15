#include <iostream>
#include <string>
#include "data.h"
#include "construction-heuristic.h"

using namespace std;

int main (void) {
    Data data = Data("./instances/n5m15A.txt");
    ConstructionHeuristic ch = ConstructionHeuristic(
        data.getN(),
        data.getM(),
        data.getP(),
        data.getB(),
        data.getTimeMatrix(),
        data.getCostMatrix()
    );

    // print data
    for (int i = 0; i < ch.getTimeVsCost().size(); i++) {
        for (int j = 0; j < ch.getTimeVsCost()[i].size(); j++) {
            cout << ch.getTimeVsCost()[i][j] << " ";
        }
        cout << " " <<endl;
    }

    return 0;
}