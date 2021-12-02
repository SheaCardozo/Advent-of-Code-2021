#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    string line;
    ifstream inputFile("1.txt");

    int increases = 0;
    bool start = false;
    int last;

    int measurement;

    if (inputFile.is_open())
    {

    while ( getline(inputFile, line) )
    {
        measurement = stoi(line);
        if (!start) {
            last = measurement;
            start = true;
        } 
        if (measurement > last) {
            increases++;
        }
        last = measurement;
    }

    inputFile.close();
    }

    cout << increases;
}
