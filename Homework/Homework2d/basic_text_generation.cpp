// :)
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unordered_map<string, vector<string>> groupWords(ifstream& in) {
    unordered_map<string, vector<string>> words;
    string prev = "";
    string curr;
    while (in >> curr) {
        // do something with curr and prev
        words[prev].push_back(curr);
        prev = curr;
    }
    return words;
}

void generateText(unordered_map<string, vector<string>>& items, string startingWord, int numEmitWords, ostream& out) {
    string prev = startingWord;
    for (int i = 0; i<numEmitWords; i++) {
        //grab random value and print it out when generation text. Continue until the amount of words has been generated
        int index = rand() % items[prev].size();
        string cur = items[prev][index];
        out << cur << " ";
        prev = cur;
    }
    cout << endl;
}
int main(int argc, char*argv[]) {
    ifstream file(argv[1]);
    //set a seed so the values are different each time when randomly generated
    srand(static_cast<unsigned int>(time(0)));
    int wordEmitCount = stoi(argv[2]);
    unordered_map<string, vector<string>>items = groupWords(file);
    generateText(items,"",wordEmitCount,cout);
    return 0;
}
