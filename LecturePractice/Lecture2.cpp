//
// Created by matth on 1/14/2026.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
    int n = 1;
    const double pi = 3.14159265;
    double number = 1.45678;
    //static cast operator
    cout << number;
    printf("%d\n", n);
    printf("%f\n", pi);
    cout << "Hello world" << endl;
    //sum command line arguments
    int total = 0;
    for (int i = 1; i<argc; i++) {
        total += stoi(argv[i]);
    }
    cout << total << endl;
    size_t val = stoi(argv[1]);
    size_t threshold = stoi(argv[2]);
    cout << "val is" << val << endl;
    while (val > threshold) {
        cout << val << " is too big" << endl;
        int divisor = rand() % 10;
        cout << "Let's divide it by " << divisor << endl;
        val = val / divisor;
        cout << "Val is now " << val << endl;

    }
    //
    /*
     * string.size() - gets the size of the string 
     *
     */
    return 0;
}