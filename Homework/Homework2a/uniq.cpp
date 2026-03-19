#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code here
    //read arguments from cin
    set<string> lines;
    if (argc == 1) {
        string line;
        while (getline(cin,line)) {
            if (line == "") {
                break;
            }
            if (lines.insert(line).second == true) {
                cout << line << endl;
            }
        }
    }
    //read arguments from file
    else {
        ifstream inFile(argv[1]);
        while (!inFile.eof()) {
            string line;
            getline(inFile,line);
            //check to see if we should add it!
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            if (lines.insert(line).second == true) {
                cout << line << endl;
            }
        }
        inFile.close();
    }
    return 0;
}
