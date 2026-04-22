#include <iostream>
using std::cout, std::endl;
//Using 4 as an example
//4 + 3 + 2 + 1 - exits
int sumto(int x) {
    if (x == 1) {
        return 1;
    }
    else if (x < 0) {
        return x + sumto(x+1);
    }
    else {
        return x + sumto(x-1);
    }
}


int main(int argc, char* argv[]) {
    cout << sumto(atoi(argv[1])) << endl;
}