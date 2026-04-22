#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<string>cars;
    priority_queue<string>names;
    cars.push("Mazda");
    cars.push("Toyota");
    cars.push("Ford");
    cout << cars.top() << endl;
    //empty() - returns true if empty
    //front() - returns object at front without removing it
    //pop() - removes items at the front of the queue
    names.push("Lehi");
    names.push("Nephi");
    names.push("Moses");
    while (!names.empty()) {
        cout << names.top() << endl;
        names.pop();
    }

    return 0;
}