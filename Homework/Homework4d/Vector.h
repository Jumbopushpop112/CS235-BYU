#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <string>
#define INITIAL_CAPACITY 1
#define GROWTH_RATE 2
using namespace std;
template<class T>
class Vector {
public:
    Vector(): _size(0), _capacity(INITIAL_CAPACITY), _array(new T[INITIAL_CAPACITY]) {}
    ~Vector() {
        delete[]_array;
    }
    class Iterator {
        T* current;
    public:
        Iterator(T*const& node): current(node) {}
        T& operator*() {
            // implement operator* here
            return *current;
        }

        Iterator& operator++() {
            // implement operator++ here
            ++current;
            return *this;

        }

        bool operator==(const Iterator& other) const {
            // implement operator== here
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            // implement operator!= here
            return current != other.current;
        }
    };

    Iterator begin() {
        // implement begin here
        return Iterator(_array);
    }

    Iterator end() {
        // implement end here
        return Iterator(_array + _size);
    }

    // paste in your methods from the vector assignment
    void push_back(T const& item) {
        // implement push_back here
        if (_size == _capacity) {
            grow();
        }
        _array[_size++] = item;
    }

    void pop_back() {
        // implement pop_back here
        if (_size > 0) {
            _size--;
        }

    }

    void insert(T const& item, size_t position) {
        // implement insert here
        if (position > _size) {
            return;
        }
        if (_size == _capacity) {
            grow();
        }
        if (_size == 0) {
            push_back(item);
        }else {
            for (size_t pos = _size; pos > position; pos--) {
                _array[pos] = _array[pos - 1];
            }
            _array[position] = item;
            _size++;
        }
    }

    void remove(size_t position) {
        // implement remove here
        if (position >= _size) {
            return;
        }
        for (size_t pos = position; pos < _size-1; pos++) {
            _array[pos] = _array[pos+1];
        }
        _size--;
    }

    T& operator[](size_t index) {
        // implement operator[] here
        if (index >= _size) {
            throw out_of_range("Index Error");
        }
        return _array[index];
    }

    T& at(size_t index) {
        // implement at here
        if (index >= _size) {
            throw out_of_range("Index Error");
        }else {
            return _array[index];
        }
    }

    size_t size() const {
        // implement size here
        return _size;
    }

    void clear() {
        // implement clear here
        _size = 0;
    }
private:
    T* _array; //array variable
    size_t _size; //number of elements
    size_t _capacity; //current size of the array
    void grow() {
        _capacity *= GROWTH_RATE;
        T* temp = new T[_capacity];
        for (int i = 0; i<_size; i++) {
            temp[i] = _array[i];
        }
        delete []_array;
        _array = temp;
    }
};

