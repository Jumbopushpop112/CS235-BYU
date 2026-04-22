#include <iostream>
using std::cout, std::endl;

int main(int argc, char* argv[]) {
    int total = 0;
    for (int i = 1; i < argc; i++) {  // for i in range(1,argc):
        total += atoi(argv[i]);
    }

    cout << total << endl;
}