#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
template<class T>
class DLList {
public:
    // **Important**
    // Normally you would make the Node struct PRIVATE
    // but for this assignment it is important to keep it 
    // PUBLIC
    // Also, the declaration of Node needs to come 
    // before everything else in the class, so leave it here
    // at the beginning.
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v, Node * next = nullptr, Node * prev = nullptr) : prev(prev), next(next), value(v) {}
    };

private:
    // Put your private fields/methods here
    Node * _head;
    Node * _tail;
    size_t _size;

public:
    DLList(): _size(0), _head(nullptr), _tail(nullptr)  {}

    ~DLList(){
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        //return first value
        return _head;
    }

    void push_front(T item) {
        // implement push_front here
        Node * newNode = new Node(item, _head);
        //set the previous element to be our new node
        if (_size != 0) {
            _head->prev = newNode;
        }else {
            _tail = newNode;
        }
        _head = newNode;
        _size++;
    }
    void push_back(T item) {
        // implement push_back here
        Node * newNode = new Node(item, nullptr, _tail);
        //newNode is in the end, and set our tail equal to that
        if (_tail) {
            _tail->next = newNode;
        }else {
            _head = newNode;
        }
        _tail = newNode;
        _size++;
    }
    void insert(T item, int position) {
        // implement insert here
        if (position < 0 or position > _size) {
            throw out_of_range("Index Error!");
        }
        if (position == _size) {
            push_back(item);
        }
        else if (position == 0) {
            push_front(item);
        }else {
            Node * ptr = _head;
            for (int i = 0; i<position; i++) {
                ptr = ptr->next;
            }
            Node * newItem = new Node(item, ptr, ptr->prev);
            ptr->prev = newItem;
            newItem->prev->next = newItem;
            _size++;
        }
    }

    void pop_front() {
        // implement pop_front her
        Node* newNode = _head;
        _head = _head->next;
        if (_head) {
            _head->prev = nullptr;
        }else {
            _tail = nullptr;
        }
        delete newNode;
        _size--;
    }
    void pop_back() {
        if (!_tail) {
           return;
        }
        Node * newNode = _tail;
        _tail = _tail->prev;
        if (_tail) {
            _tail->next = nullptr;
        }else {
            _head = nullptr;
        }
        delete newNode;
        _size--;
    }
    void remove(int position) {
        // implement remove here
        if (position < 0 or position >= _size) {

        }
        if (position == 0) {
            pop_front();
        }
        else if (position == _size - 1) {
            pop_back();
        }else {
            Node * ptr = _head;
            for (int i = 0; i<position; i++) {
                ptr = ptr->next;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            _size--;
            delete ptr;
        }
    }

    const T& front() const {
        // implement front here
        //return first value
        if (_head == nullptr) {
            throw out_of_range("Index error");
        }
        return _head->value;
    }
    const T& back() const {
        // implement back here
        //return last value
        if (_tail == nullptr) {
            throw out_of_range("Index error");
        }
        return _tail->value;
    }
    const T& at(int index) const {
        //check indexes first
        // implement at here
        if (index < 0) {
            throw out_of_range("Index error");
        }
        Node* current = _head;
        int i = 0;
        //loop through each value and keep track using an iterator, else throw an out of bounds error
        while (current) {
            if (i == index) {
                return current->value;
            }
            current = current->next;
            i++;
        }
        throw out_of_range("Index error");
    }

    bool contains(const T& item) const {
        // implement contains here
        //loop through each element, if it equals item, return true, else return false (it's not included)
        Node* current = _head;
        while (current) {
            if (current->value == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const {
        // implement size here
        return _size;
    }

    void clear() {
        // implement clear here
        Node* current = _head;
        //loop through each node and delete it
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        //result variables because we made it to the end and have deleted everything
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }
};
