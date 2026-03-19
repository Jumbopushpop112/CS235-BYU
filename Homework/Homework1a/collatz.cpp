// :)
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    int n = stoi(argv[1]);
    while (n != 1) {
        cout << n << endl;
        //if n is even, divide it by 2
        if (n % 2 == 0){
            n = n/2;
        }
        //if n is odd, multiply it by 3 and add 1
        else {
            n = 3 * n + 1;
        }
    }
    cout << n << endl;
}
