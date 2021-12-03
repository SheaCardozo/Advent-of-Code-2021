#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h> 
using namespace std;

int main() {

    string line;
    ifstream inputFile("3.txt");

    vector<string> oxrecords;
    vector<string> corecords;

    string ox = "";
    string co = "";

    if (inputFile.is_open())
    {

        while ( getline(inputFile, line) )
        {
            oxrecords.push_back(line);
            corecords.push_back(line);
        }

        inputFile.close();
    }

    for (int i = 0; i < 13; i++) {
        int ox_no = 0;
        int co_no = 0;

        if (oxrecords.size() == 1){
            ox = oxrecords[0];
        } else {

            for (string record: oxrecords){
                if (record[i] == '1') {
                    ox_no += 1.0;
                }
            }

            if ((1.0 * ox_no) / oxrecords.size() >= 0.5) {
                ox_no = 1;
            } else {
                ox_no = 0;
            }

            vector<string> new_oxrecords;

            for (string record: oxrecords){
                if (record[i] - '0' == ox_no) {
                    new_oxrecords.push_back(record);
                }
            }
            
            oxrecords = new_oxrecords;
        }


        if (corecords.size() == 1){
            co = corecords[0];
        } else {
            for (string record: corecords){
                if (record[i] == '1') {
                    co_no += 1.0;
                }
            }

            if ((1.0 * co_no) / corecords.size() < 0.5) {
                co_no = 1;
            } else {
                co_no = 0;
            }

            
            vector<string> new_corecords;

            for (string record: corecords){
                if (record[i] - '0' == co_no) {
                    new_corecords.push_back(record);
                }
            }

            corecords = new_corecords;
        }
    }

    int oxn = 0;
    int con = 0;

    for (int i = 0; i < ox.size(); i++) {
        oxn += (ox[i] - '0') * pow(2, ox.size() - 1 - i);
        con += (co[i] - '0') * pow(2, ox.size() - 1 - i);
    }

    cout << oxn * con;
}
