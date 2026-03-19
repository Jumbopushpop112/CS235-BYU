//  :)
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    list<string> operators = {"add","divide","multiply","subtract","mod"};
    string userOperator;
    cout << "operation: ";
    getline(cin,userOperator);
    //when the user enters a blank string, it quites
    while (userOperator != "") {
        //check if the command is in the list
        if (find(operators.begin(),operators.end(), userOperator) == operators.end()) {
            cout << userOperator << " isn't a valid operation" << endl;
        }else {
            //process the operators and perform the appropriate operator
            string leftOperandStr;
            string rightOperandStr;
            cout << "left operand: ";
            getline(cin, leftOperandStr);
            int leftOperand = stoi(leftOperandStr);
            cout << "right operand: ";
            getline(cin, rightOperandStr);
            int rightOperand = stoi(rightOperandStr);
            if (userOperator == "add") {
                cout << leftOperand + rightOperand << endl;
            }
            else if (userOperator == "divide") {
                cout << leftOperand / rightOperand << endl;
            }
            else if (userOperator == "multiply") {
                cout << leftOperand * rightOperand << endl;
            }
            else if (userOperator == "subtract") {
                cout << leftOperand - rightOperand << endl;
            }
            else if (userOperator == "mod"){
                cout << leftOperand % rightOperand << endl;
            }
        }
        //continue asking the user for an operator
        cout << "operation: ";
        getline(cin, userOperator);
    }
    return 0;

}