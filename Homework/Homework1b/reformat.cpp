#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char*argv[]) {
    string line;
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    //read all the lines in the file
    while (getline(infile,line)) {
        stringstream ss(line);
        string name;
        string surname;
        int points;
        double factor;
        //using ss, we can get each part of the line and do the appropriate measures with it
        while (ss >> name >> surname >> points >> factor) {
            outfile << surname << ", " << name << ": " << points * factor << endl;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}