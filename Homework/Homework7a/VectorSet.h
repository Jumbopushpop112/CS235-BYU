#pragma once
#include <cstdlib>
#include <vector>
using namespace std;
template<class T>

class VectorSet {
    vector<T> items;
public:
    bool contains(T item) const {
        // implement contains here
        for (int i = 0; i<items.size(); i++) {
            if (items[i] == item) {
                return true;
            }
        }
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        if (contains(item)) {
            return false;
        }
        items.push_back(item);
        return true;
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        for (auto iter = items.begin(); iter != items.end();) {
            if (*iter == item) {
                items.erase(iter);
                return true;
            }else {
                ++iter;
            }
        }
        // return true if item is removed and false if item wasn't in the set
        return false;
    }

    size_t size() const {
        // implement size here
        return items.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        return items.empty();
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        items.clear();
        // remove all items from the set
    }
};

