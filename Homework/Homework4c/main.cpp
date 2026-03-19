//
// Created by matth on 3/11/2026.
//
#include <iostream>
using namespace std;
#include "Vector.h"
int main() {
    Vector<int> vec;
    vec.insert(5,0);
    vec.insert(6,1);
    for (int i = 0; i<vec.size(); i++) {
        cout << vec.at(i) << endl;
    }
    cout << "Hi" << endl;
}