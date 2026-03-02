#include <iostream>
#include "list.h"
using namespace std;

template <class T >
List<T>::~List()
{
    while (!isEmpty())
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}
template <class T>
T List<T>::headPush(T el)
{
    Node *new_node = new Node(el);
    if (isEmpty())
    {
        head = tail = new_node;
    } else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
template <class T>
T List<T>::tailPush(T el)
{
    Node *new_node = new Node(el);
    if (isEmpty())
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
template <class T>
T List<T>::headPop()
{
    if (isEmpty())
        return -1;

    int num = head->info;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    return num;
}
template <class T>
T List<T>::tailPop()
{
    if (isEmpty())
        return -1;

    T num = tail->info;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    return num;
}
template <class T>
T List<T>::deleteNode(T el)
{
    if (isEmpty())
        return;

    Node *temp = head;
    while (temp != nullptr && temp->info != el)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
        return;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;
        
delete temp;
}
template <class T>
T List<T>::isInList(T el)
{
    Node *current = head;

    while (current != 0)
    {
        if (current->info == el)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
template <class T>
T List<T>::swapvalue(T& variable1, T& variable2)
{
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}
template <class T>
T List<T>::sort() {
    for (Node<T>* i = head; i; i = i->next) {
        Node<T>* minNode = i;
        for (Node<T>* j = i->next; j; j = j->next) {
            if (j->info < minNode->info) minNode = j;
        }
        swap(i->info, minNode->info);
    }
}

template <class T>
T List<T>::unique() {
    for (Node<T>* i = head; i; i = i->next) {
        Node<T>* j = i->next;
        while (j) {
            if (j->info == i->info) {
                Node<T>* duplicate = j;
                j = j->next;
                deleteNode(duplicate->info);
            } else {
                j = j->next;
            }
        }
    }
}


template <class T>
T List<T>::display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->info;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}