#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h> 
using namespace std;

int main() {

    string line;
    ifstream inputFile("3.txt");

    vector<int> freqs = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double lines = 0;

    int gamma = 0;
    int epsilon = 0;

    if (inputFile.is_open())
    {

    while ( getline(inputFile, line) )
    {
        lines += 1;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '1') {
                freqs[i] += 1;
            }
        }

    }

    inputFile.close();
    }

    for (int i = 0; i < freqs.size(); i++) {
        if (freqs[i] / lines < 0.5) {
            epsilon += pow(2, (freqs.size() - 1 - i));
        } else {
            gamma += pow(2, (freqs.size() - 1 - i));
        }
    }

    cout << gamma * epsilon;
}
