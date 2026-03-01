#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T info;
    Node* next;
    Node* prev;
    Node(T el, Node* n = nullptr, Node* p = nullptr)
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
    void display() ;
    void sort();           // Sort linked list
    void unique();         // Remove duplicates

private:
    Node<T>* head;
    Node<T>* tail;
};
#endif
