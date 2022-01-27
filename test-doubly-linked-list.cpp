#include "doubly-linked-list.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    DoublyLinkedList<string> doubly_linked_list;
    doubly_linked_list.print();
    doubly_linked_list.insert_at_tail("3");
    doubly_linked_list.print();
    doubly_linked_list.insert_at_tail("4");
    doubly_linked_list.print();
    doubly_linked_list.insert_at_head("1");
    doubly_linked_list.print();
    doubly_linked_list.insert_before_index(1, "2");
    doubly_linked_list.print();
    doubly_linked_list.insert_before_index(4, "5");
    doubly_linked_list.print();
    doubly_linked_list.insert_before_index(0, "0");

    cout << "iterate with iterator" << endl;
    for (DoublyLinkedList<string>::iterator it = doubly_linked_list.begin();
         it != doubly_linked_list.end(); ++it) {
        cout << *it << endl;
    }

    cout << "iterate with for each" << endl;
    for (string &s : doubly_linked_list) {
        s = s + "..";
        cout << s << endl;
    }

    doubly_linked_list.print();
    cout << "removed value= " << doubly_linked_list.remove_tail() << endl;
    doubly_linked_list.print();
    cout << "removed value= " << doubly_linked_list.remove_head() << endl;
    doubly_linked_list.print();
    cout << "removed value= " << doubly_linked_list.remove_index(0) << endl;
    doubly_linked_list.print();
    doubly_linked_list.insert_before_index(2, "-4");
    doubly_linked_list.print();
    cout << "removed value= " << doubly_linked_list.remove_index(2) << endl;
    doubly_linked_list.print();
    cout << "removed value= " << doubly_linked_list.remove_index(1) << endl;
    doubly_linked_list.print();
    cout << "removed value= " << doubly_linked_list.remove_index(1) << endl;
    doubly_linked_list.print();
    cout << "removed value= " << doubly_linked_list.remove_index(0) << endl;
    doubly_linked_list.print();
    doubly_linked_list.insert_before_index(0, "1");
    doubly_linked_list.print();
    doubly_linked_list.insert_before_index(0, "0");
    doubly_linked_list.print();
    doubly_linked_list.insert_before_index(2, "2");
    doubly_linked_list.print();
    return 0;
}
