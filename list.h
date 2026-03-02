#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Node {
public:
    T info;
    Node<T>* next;
    Node<T>* prev;
    Node(T el, Node<T>* n = nullptr, Node<T>* p = nullptr)
        : info(el), next(n), prev(p) {}
};

template <class T>
class List {
public:
    List() : head(nullptr), tail(nullptr) {}
    ~List();

    bool isEmpty() const { return head == nullptr; }

    void headPush(T el);   // Add element to front
    void tailPush(T el);   // Add element to tail
    T headPop();           // Remove and return front
    T tailPop();           // Remove and return tail
    void deleteNode(T el); // Delete a particular value
    bool isInList(T el);   // Check if value exists
    void display();        // Print list

private:
    Node<T>* head;
    Node<T>* tail;
};

template <class T>
List<T>::~List() {
    while (!isEmpty()) {
        headPop();
    }
}

template <class T>
void List<T>::headPush(T el) {
    Node<T>* new_node = new Node<T>(el, head, nullptr);
    if (head) head->prev = new_node;
    head = new_node;
    if (!tail) tail = head;
}

template <class T>
void List<T>::tailPush(T el) {
    Node<T>* new_node = new Node<T>(el, nullptr, tail);
    if (tail) tail->next = new_node;
    tail = new_node;
    if (!head) head = tail;
}

template <class T>
T List<T>::headPop() {
    if (!head) throw runtime_error("Empty list");
    Node<T>* tmp = head;
    T val = tmp->info;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete tmp;
    return val;
}

template <class T>
T List<T>::tailPop() {
    if (!tail) throw runtime_error("Empty list");
    Node<T>* tmp = tail;
    T val = tmp->info;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete tmp;
    return val;
}

template <class T>
void List<T>::deleteNode(T el) {
    Node<T>* cur = head;
    while (cur) {
        if (cur->info == el) {
            if (cur->prev) cur->prev->next = cur->next;
            else head = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            else tail = cur->prev;
            delete cur;
            return;
        }
        cur = cur->next;
    }
}

template <class T>
bool List<T>::isInList(T el) {
    Node<T>* cur = head;
    while (cur) {
        if (cur->info == el) return true;
        cur = cur->next;
    }
    return false;
}

template <class T>
void List<T>::display() {
    Node<T>* cur = head;
    while (cur) {
        cout << cur->info << " ";
        cur = cur->next;
    }
    cout << endl;
}

#endif
