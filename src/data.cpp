#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "data.h"
#include <vector>

using namespace std;

void simple_tokenizer(string s, vector<int> &token) {
    stringstream ss(s);
    string word;
    while (ss >> word) {
        token.push_back(stoi(word));
    }
}

Data::Data(string pathParam) {
    string info;
    int line_number = 0;

    ifstream myfile(pathParam);

    int aux;

    if (myfile.is_open()) {
        while (myfile.good()) {
            myfile >> jobsNumber;
            myfile >> serversNumber;
            myfile >> defaultCost;

            for(int i = 0; i < serversNumber; i++){
                myfile >> aux;
                serversCapacity.push_back(aux);
            }
            vector<int> line;

            for(int i = 0; i < serversNumber; i++){
                for(int j = 0; j < jobsNumber; j++){
                    myfile >> aux;
                    line.push_back(aux);
                }
                timeMatrix.push_back(line);
                line.clear();
            }

            line.clear();

            for(int i = 0; i < serversNumber; i++){
                for(int j = 0; j < jobsNumber; j++){
                    myfile >> aux;
                    line.push_back(aux);
                }
                costMatrix.push_back(line);
                line.clear();
            }
        }
    } else cout << "Unable to open file in path" << pathParam;
}


int Data::getJobsNumber() {
    return jobsNumber;
}

int Data::getServersNumber() {
    return serversNumber;
}

int Data::getDefaultCost() {
    return defaultCost;
}

vector<int> Data::getServersCapacity() {
    return serversCapacity;
}

vector< vector<int> > Data::getTimeMatrix() {
    return timeMatrix;
}


vector< vector<int> > Data::getCostMatrix() {
    return costMatrix;
}

void Data::printJobsNumber() {
    cout << jobsNumber << endl;
}

void Data::printServersNumber() {
    cout << serversNumber << endl;
}

void Data::printDefaultCost() {
    cout << defaultCost << endl;
}

void Data::printServersCapacity() {
    for(int i = 0; i < serversNumber; i++){
        cout << serversCapacity[i] << " ";
    }
    cout << endl;
}

void Data::printTimeMatrix() {
    for(int i = 0; i < serversNumber; i++){
        for(int j = 0; j < jobsNumber; j++){
            cout << timeMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Data::printCostMatrix() {
    for(int i = 0; i < serversNumber; i++){
        for(int j = 0; j < jobsNumber; j++){
            cout << costMatrix[i][j] << " ";
        }
        cout << endl;
    }
}