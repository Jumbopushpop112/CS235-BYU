#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

int main(int argc, char * argv[]){
    ifstream file(argv[1]);
//    string line;
    string word;
    int number;
//    while(getline(file, line))
    while(file >> word >> number){
        for (int i = 0; i < number; i++){
            cout << word << " ";
        }
        cout << endl;
    }

    file.close();
    return 0;
}
