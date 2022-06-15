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

    if (myfile.is_open()) {
        while (getline (myfile,info)) {
            if (line_number == 0) {
                jobsNumber = stoi(info);
            }
            if (line_number == 1) {
                serversNumber = stoi(info);
            }
            if (line_number == 2) {
                defaultCost = stoi(info);
            }
            if (line_number == 4) {
                simple_tokenizer(info, serversCapacity);
            }
            if (line_number > 5 && line_number < serversNumber + 6) {
                vector<int> line;
                simple_tokenizer(info, line);
                timeMatrix.push_back(line);
            }
            // TODO: refact this
            if (line_number > serversNumber + 6 && line_number < serversNumber + 7 + jobsNumber) {
                vector<int> line;
                simple_tokenizer(info, line);
                costMatrix.push_back(line);
            }

            line_number++;
        }

        myfile.close();
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
