#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string;


template<class T>
class Queue {
public:
    bool empty() {}
    T& front() {}
    const T& front() const {}
    void pop() {}
    void push(const T& item) {}
    size_t size() const {}
    string toString() const {}
};

int main(){
    Queue<string> names;

    names.push("Abinadi");
    names.push("Zeniff");
    names.push("Pahoran");
    names.push("Kishkuman");
    names.push("Nephi");
    names.push("Lehi");
    std::cout << names.toString() << endl;

    names.pop();
    names.pop();
    std::cout << names.toString() << endl;
    names.push("Teancum");
    std::cout << names.toString() << endl;

    return 0;
}
