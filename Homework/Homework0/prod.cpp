#include <iostream>
#include <string>
using namespace std;
//g++ prod.cpp -o prod <-- Note to self, I must use this to update my code and to make it executable
int main(int argc, char* argv[]){
    //We assume that the user has put in two numbers, but in case they forget one, we display the following error, and code exits
    if (argc != 3) {
        cout << "prod requires 2 arguments" << endl;
        return 1;
    }
    double a = stod(argv[1]);
    double b = stod(argv[2]);
    cout << a << " * " << b << " = " << a * b << endl;
    return 0;
}