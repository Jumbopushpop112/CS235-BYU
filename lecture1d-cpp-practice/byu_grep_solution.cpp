#include <iostream>
using std::istream, std::cin, std::cout, std::cerr, std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string, std::getline;


bool substr_at(string const& text, size_t pos, string const& pattern) {
    for (size_t i = 0; i < pattern.length(); i++) {
        if (text[pos + i] != pattern[i]) {
            return false;
        }
    }
    return true;
}

bool str_contains(string const& text, string const& pattern) {
    for (size_t i = 0; i < text.length() - pattern.length(); i++) {
        if (substr_at(text, i, pattern)) {
            return true;
        }
    }
    return false;
}

void search(string const& pattern, istream& input) {
    string line;
    while (getline(input, line)) {
        if (str_contains(line, pattern)) {
            cout << line << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Must provide a pattern" << endl;
        exit(1);
    }

    string pattern = argv[1];

    if (argc < 3) {
        // Use STDIN
        search(pattern, cin);

    } else {
        ifstream input_file(argv[2]);
        if (!input_file.is_open()) {
            cerr << "Unable to open file: " << argv[2] << endl;
            exit(2);
        }

        search(pattern, input_file);
    }

}