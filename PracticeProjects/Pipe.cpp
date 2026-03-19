//
// Created by matth on 1/26/2026.
//
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char*argv[]) {
    string line;
    while (getline(cin, line)) {
        cout << line << endl; // prints each line from stdin
    }
}