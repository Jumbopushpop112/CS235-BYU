#pragma once
#include <iostream>
using namespace std;
template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;
        Node(T v) : next(nullptr), value(v) {}
    };
    Node *head;
    size_t _size;

    SLList(): head(nullptr), _size(0){}

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return head;
    }

    void push_back(T item) {
        // implement push_back here
        Node* newNode =  new Node(item);
        if (head != nullptr) {
            Node* pointer = head;
            while (pointer->next != nullptr) {
                pointer = pointer->next;
            }
            pointer->next = newNode;
            _size++;
        }else {
            head = newNode;
            _size++;
        }
    }

    void pop_back() {
        // implement pop_back here
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            _size--;
        }
        if (head != nullptr) {
            Node* pointer = head;
            while (pointer->next->next != nullptr) {
                pointer = pointer->next;
            }
            delete pointer->next;
            pointer->next = nullptr;
            _size--;
        }
    }

    void push_front(T item) {
        // implement push_front here
        if (head != nullptr) {
            Node* newNode =  new Node(item);
            newNode->next = head;
            head = newNode;
            _size++;
        }else {
            head = new Node(item);
            _size++;
        }
    }

    void pop_front() {
        // implement pop_front here
        if (head != nullptr) {
            Node* newNode = head;
            head = head->next;
            delete newNode;
            newNode = nullptr;
            _size--;
        }
    }
    const T& front() const {
        // implement front here
        if (head != nullptr) {
            return head->value;
        }

    }

    int size() const {
        return _size;
    }

    void clear() {
        Node* current = head;
        //check if the set is already empty
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        _size = 0;
    }
};
