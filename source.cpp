#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List mylist;
    mylist.headPush(10);
    mylist.display();
    cout << endl;

    mylist.headPush(40);
    mylist.display();
    cout << endl;

    mylist.tailPush(15);
    mylist.display();
    cout << endl;

    mylist.tailPush(20);
    mylist.display();
    cout << endl;

    cout << "Head pop: " << mylist.headPop() << endl;
    mylist.display();

    cout << "Tail pop: " << mylist.tailPop() << endl;
    mylist.display();

    mylist.deleteNode(10);
    mylist.display();

    cout << "Is 15 in list? " << (mylist.isInList(15) ? "Yes" : "No") << endl;
    cout << "Is 99 in list? " << (mylist.isInList(99) ? "Yes" : "No") << endl;

    return 0;
}