#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <map>
using std::map;

#include <sstream>
using std::stringstream;


string encode(string const& in, map<char, char> const& cipher) {
    stringstream result;
    for (size_t i = 0; i < in.length(); i++) {
        auto c = cipher.find(in[i]);
        if (c == cipher.end()) {
            result << in[i];
        } else {
            result << c->second;
        }
    }
    return result.str();
}

map<char,char> generateRotationCipher(int offset){
    map<char, char> rCipher;
    for (int i = 0; i < 26; i++) {
        rCipher['a' + i] = 'a' + (i+offset)%26;
        rCipher['A' + i] = 'A' + (i+offset)%26;
    }
    return rCipher;
}

map<char,char> reverseCipher(const map<char,char> & original){
    map<char, char> rehpic;
    for (auto &key_value_pair : original) {
        rehpic[key_value_pair.second] = key_value_pair.first;
    }
    return rehpic;
}

int main(){
    // simple substitution cipher
    map<char, char> cipher;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string scramble = "xyzijkafgwlmnohuvbcdepqrst";

//    for (size_t i = 0; i < alphabet.length(); i++) {
//        cipher[alphabet[i]] = scramble[i];
//        cipher[alphabet[i]-'a'+'A'] = scramble[i]-'a'+'A';
//    }

//      for (auto& entry : cipher) {
//          cout << entry.first << " -> " << entry.second << "; ";
//      }
//      cout << endl;

//     string phrase = "Hello, my name is Inigo Montoya.";
//     cout << phrase << endl;
//     cout << encode(phrase, cipher) << endl;

//      auto rot13 = generateRotationCipher(13);
//      for (auto& entry : rot13) {
//          cout << entry.first << " -> " << entry.second << "; ";
//      }
//      cout << endl;
//      cout << encode("Hello, my name is Inigo Montoya.", rot13) << endl;
//      cout << encode("Hello, my name is Inigo Montoya.", generateRotationCipher(10)) << endl;

    string message = "I think maps are the coolest thing since sliced bread. 🍞";
    cout << message << endl;

    cipher = generateRotationCipher(3);
    string secret_message = encode(message, cipher);
    cout << secret_message << endl;

    auto rehpic = reverseCipher(cipher);
    string message_restored = encode(secret_message, rehpic);
    cout << message_restored << endl;


    return 0;
}