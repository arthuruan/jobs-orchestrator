#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

int main (void) {
    Data data = Data("./instances/n5m15A.txt");


    // TODO: remove it. [AR]
    cout << data.getN() << endl;
    cout << data.getM() << endl;
    cout << data.getP() << endl;
    for (int i = 0; i < data.getB().size(); i++) {
        cout << data.getB()[i] << " ";
    }
    cout << " " <<endl;

    // list time
    for (int i = 0; i < data.getTime().size(); i++) {
        for (int j = 0; j < data.getTime()[i].size(); j++) {
            cout << data.getTime()[i][j] << " ";
        }
        cout << " " <<endl;
    }

    cout << " " <<endl <<endl;

    // list cost
    for (int i = 0; i < data.getCost().size(); i++) {
        for (int j = 0; j < data.getCost()[i].size(); j++) {
            cout << data.getCost()[i][j] << " ";
        }
        cout << " " <<endl;
    }

    return 0;
}