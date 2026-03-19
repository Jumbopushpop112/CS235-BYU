#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(int argc, char const* argv[]) {
    priority_queue<string>items;
    while (true) {
        cout << "What do you want to do? ";
        string userChoice;
        getline(cin,userChoice);
        if (userChoice == "") {
            break;
        }
        else if (userChoice == "add") {
            //declare person string and push it to the queue
            string name;
            string priority;
            cout << "Name: ";
            getline(cin,name);
            cout << "Priority: ";
            getline(cin,priority);
            string person = "";
            if (stoi(priority) < 10) {
                person = "0" + priority + " - " + name;
            }else {
                person = priority + " - " + name;
            }
            items.push(person);
        }
        else if (userChoice == "take"){
            //queue is empty, so print to the user
            if (items.empty()) {
                cout << "There are no more people in line" << endl;
            }else {
                //print the top item of the list, and remove it so that the top item can be printed when the user types take again
                cout << items.top() << endl;;
                items.pop();
            }
        }
        else {
            cout << userChoice << " isn't a valid operation" << endl;
        }
    }
    return 0;
}
