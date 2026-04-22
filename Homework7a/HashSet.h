#pragma once
#include <vector>
#include <functional>
using namespace std;
constexpr int INITIAL_CAPACITY = 5;
constexpr float LOAD_FACTOR_RATIO = 0.75;
constexpr int GROW_FACTOR = 2;
template<class T>
class HashSet {
public:
    HashSet() : _table(new vector<T>[INITIAL_CAPACITY]), _size(0), _capacity(INITIAL_CAPACITY){}

    ~HashSet() {
        delete[] _table;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        if (contains(item)) {
            return false;
        }
        int idx = get_hash(item);
        _table[idx].push_back(item);
        _size++;
        grow();
        return true;
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        int index = get_hash(item);
        for (auto it = _table[index].begin(); it != _table[index].end(); it++) {
            if (item == *it) {
                _table[index].erase(it);
                _size--;
                return true;
            }
        }
        return false;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        int idx = get_hash(item);
        for (auto i : _table[idx]) {
            if (i == item) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        for (auto i=0; i < _capacity; i++) {
            _table[i].clear();
        }
        _size = 0;
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return _size;
    }
private:
    vector<T>* _table;
    int _size;
    int _capacity;

    int get_hash(const T& item) const{
        return hash<T>{}(item) % _capacity;
    }
    void grow() {
        if (static_cast<float>(_size) / static_cast<float>(_capacity) > LOAD_FACTOR_RATIO){
            vector<T>* old_table = _table;
            int old_capacity = _capacity;
            _capacity = _capacity * GROW_FACTOR +1;
            _table = new vector<T>[_capacity];
            _size = 0;
            for (int i = 0; i< old_capacity; i++) {
                for (auto t: old_table[i]) {
                    insert(t);
                }
            }
            delete [] old_table;
        }
    }
};

