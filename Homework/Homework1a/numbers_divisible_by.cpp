// :D
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    int start = stoi(argv[1]);
    int end = stoi(argv[2]);
    int divisor = stoi(argv[3]);
    //iterate in increasing order if start is less than the end value
    if (start < end) {
        for (int i = start; i <= end; i++) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }
    //iterate in decreasing order if start value than or equal to the end value
    if (start >= end) {
        for (int i = start; i >= end; i--) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }
}
