#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {

    string line;
    ifstream inputFile("1.txt");

    int increases = 0;
    bool start = false;
    int last;

    vector<int> measurements = {};
    int measurement;

    if (inputFile.is_open())
    {

    while ( getline(inputFile, line) )
    {
        measurement = stoi(line);
        measurements.push_back(measurement);
    }

    for (int i = 1; i < (measurements.size() - 1); i++) {
        int curr = measurements[i] + measurements[i-1] + measurements[i+1];
        
        if (!start) {
            last = curr;
            start = true;
        } 
        if (curr > last) {
            increases++;
        }
        last = curr;

    }

    inputFile.close();
    }

    cout << increases;
}
