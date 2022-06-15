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

Data::Data(string path_param) {
    string info;
    int line_number = 0;

    ifstream myfile(path_param);

    if (myfile.is_open()) {
        while (getline (myfile,info)) {
            if (line_number == 0) {
                n = stoi(info);
            }
            if (line_number == 1) {
                m = stoi(info);
            }
            if (line_number == 2) {
                p = stoi(info);
            }
            if (line_number == 4) {
                simple_tokenizer(info, b);
            }
            if (line_number > 5 && line_number < m + 6) {
                vector<int> line;
                simple_tokenizer(info, line);
                time.push_back(line);
            }
            if (line_number > m + 6 && line_number < m + 7 + n) {
                vector<int> line;
                simple_tokenizer(info, line);
                cost.push_back(line);
            }

            line_number++;
        }

        myfile.close();
    } else cout << "Unable to open file in path" << path_param;
}


int Data::getN() {
    return n;
}

int Data::getM() {
    return m;
}

int Data::getP() {
    return p;
}

vector<int> Data::getB() {
    return b;
}

vector< vector<int> > Data::getTime() {
    return time;
}


vector< vector<int> > Data::getCost() {
    return cost;
}
