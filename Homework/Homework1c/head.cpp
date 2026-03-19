#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char const* argv[]) {
    // Write your code here
    string line;
    int numLines = 10;
    int count = 0;
    //no number of lines file, print 10
    if (argc == 1) {
        while (count < numLines && getline(cin,line)) {
            cout << line << endl;
            count++;
        }
        return 0;
    }
    if (argc == 2) {
        //ok, we have two options is it a number of a file?
        string lines = argv[1];
        if (lines[0] == '-') {
            numLines = stoi(argv[1]) * -1;
            while (count < numLines && getline(cin,line)) {
                cout << line << endl;
                count++;
            }
        }else {
            //we have a file
            ifstream inFile(argv[1]);
            if (!inFile) {
                cout << "ERROR: can't open " << argv[1] << endl;
                return 1;
            }
            while (count < numLines && getline(inFile, line)) {
                cout << line << endl;
                count++;
            }
        }
    }
    //3 arguments and process correctly
     if (argc == 3) {
         numLines = stoi(argv[1]) * -1;
         ifstream inFile(argv[2]);
         if (!inFile) {
             cout << "ERROR: can't open " << argv[2] << endl;
             return 1;
         }
         while (count < numLines && getline(inFile, line)) {
             cout << line << endl;
             count++;
         }
     }
    return 0;
}
