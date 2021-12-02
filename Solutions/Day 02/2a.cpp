#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    string line;
    ifstream inputFile("2.txt");

    int posx = 0;
    int posy = 0;

    if (inputFile.is_open())
    {

    while ( getline(inputFile, line) )
    {
        char dir = line[0];
        int units = line.back() - '0';
        
        if (dir == 'f') {
            posx += units;
        } else if (dir == 'd') {
            posy += units;
        } else if (dir == 'u') {
            posy -= units;
        }
    }

    inputFile.close();
    }

    cout << (posx * posy);
}
