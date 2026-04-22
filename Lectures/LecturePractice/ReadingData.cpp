//
// Created by matth on 1/21/2026.
//
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int num = 4;
    cout << num << endl;
    string fileText;
    ifstream myFile("Names.txt");
    if (!myFile.is_open()) {
        cout << "Error! Can't find file. ";
    }
    while (getline(myFile,fileText)) {
        cout << fileText << endl;
    }
    myFile.close();
    return 0;
}