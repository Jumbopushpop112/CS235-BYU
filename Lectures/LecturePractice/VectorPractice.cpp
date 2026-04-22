//
// Created by matth on 2/2/2026.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    set<int> nums;
    nums.insert(5);
    nums.insert(10);
    nums.insert(15);
    for (int curNum: nums) {
        cout << curNum << endl;
    }
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    vector<string> groceries = {};
    string userGrocery;
    cout << "Add something to your grocery list: ";
    while (getline(cin, userGrocery)) {
        if (userGrocery.empty()) {
            break;
        }
        groceries.push_back(userGrocery);
        cout << "Add something to your grocery list: ";
    }
    cout << "Your grocery list" << endl;
    bool isFound = false;
    for (auto item: groceries) {
        if (item == "bacon") {
            isFound = true;
        }
        cout << item << endl;
    }
    if (isFound) {
        cout << "Item found in list" << endl;
    }


}