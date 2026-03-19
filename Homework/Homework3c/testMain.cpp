//
// Created by matth on 2/24/2026.
//
#include "insertion_sort.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> array = {3, 7, -5, 10, 1};
    sort(array);
    for (const auto& item : array) {
           cout << item << " ";
    }
    cout << endl;
    return 0;
}