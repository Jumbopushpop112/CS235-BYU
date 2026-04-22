#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::ostringstream;


template<class T>
class Stack {
public:
    bool empty() {
        return m_self.empty();
    }
    T& top() {
        return m_self.at(m_self.size()-1);
    }
    const T& top() const {
        return m_self.at(m_self.size()-1);
    }
    void pop() {
        m_self.pop_back();
    }
    void push(const T& item) {
        m_self.push_back(item);
    }
    size_t size() const {
        return m_self.size();
    }
    string toString() const {
        ostringstream os;
        os << "TOP OF STACK\n";
        for (size_t i = m_self.size()-1; i>=0; i--){
            os << m_self.at(i) << endl;
        }
        os << "BOTTOM OF STACK\n";
        return os.str();
    }
private:
    vector<T> m_self;
};

int main(){
    Stack<string> names;

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
