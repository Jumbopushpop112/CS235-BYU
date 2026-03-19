#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char*argv[]) {
    string line;
    ifstream infile(argv[1]);
    if (!infile) {
        cout << "Error: can't find file " << argv[1] <<  endl;
        return 1;
    }
    int cityPopulation = 0;
    int cityYear = stoi(argv[2]);//the year the user is requesting
    int count = 0;
    string userCity = argv[3];
    while (getline(infile,line)) {
        stringstream ss(line);
        int year;
        int population;
        string cityName;
        while (ss >> cityName >> year >> population) {
            if ((year == cityYear) && (cityName == userCity)){
                cityPopulation += population;
                count++;
            }
        }
    }
    cout << static_cast<double>(cityPopulation)/count << endl;
}