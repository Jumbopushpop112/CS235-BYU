//  :-)
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char*argv[]) {
    string line;
    string longestLine;
    int maxLength = 0;
    ifstream inFile(argv[1]);
    //continue reading the file
    while (getline(inFile,line)) {
        stringstream ss(line);
        string word;
        int wordCount = 0;
        //increment the amount of words per line
        while (ss >> word) {
            wordCount++;
        }
        //keep track of the length of the longest line. if the lines after have more words, keep updating it
        //once the loop finishes, we will find the longest word
        if (wordCount > maxLength) {
            maxLength = wordCount;
            longestLine = line;
        }
    }
    cout << longestLine << endl;
}