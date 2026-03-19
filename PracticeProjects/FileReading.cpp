#include <iostream>
#include <fstream>
using namespace std;
int main() {
    string fileText;
    ifstream myFile("Stuff.txt");
    while (getline(myFile,fileText)) {
        cout << fileText << endl;
    }
    myFile.close();
    return 0;
}
