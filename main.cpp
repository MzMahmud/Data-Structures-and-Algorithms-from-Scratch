// #include "dynamic-array.h"
#include "singly-linked-list.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    // SinglyLinkedList<int> list;
    // list.push_front(1);
    // list.push_front(2);
    // list.push_front(3);
    // list.push_front(4);
    // list.push_back(1);
    // list.push_front(5);
    // list.push_back(2);
    // list.push_back(3);
    // list.push_back(4);

    // list.push_front(6);

    SinglyLinkedList<string> list;

    list.push_front("moaz");
    list.push_front("moon");
    list.push_back("maish");
    list.push_back("farshi");

    list.show_list(cout);

    SinglyLinkedList<string> list1;
    list1 = list;
    SinglyLinkedList<string> list2 = list;
    SinglyLinkedList<string> list3(list);

    // while (!list.is_empty()) {
    //     cout << list.pop_front() << endl;
    // }
    list1.push_back("list1");

    list2.push_back("list2");

    list3.pop_front();
    list3.push_back("list3");

    list.sort();
    list.show_list(cout);
    list1.show_list(cout);
    list2.show_list(cout);
    list3.show_list(cout);

    return 0;
}