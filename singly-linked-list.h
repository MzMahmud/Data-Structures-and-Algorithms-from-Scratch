#ifndef __SINGLY_LINKED_LIST__

#define __SINGLY_LINKED_LIST__

#include <iostream>

template <class T> struct Node {
    T data;
    Node *next;

    Node() {}
    Node(T d, Node *n = nullptr) : data(d), next(n) {}
};

template <class T> class SinglyLinkedList {
  private:
    size_t m_size;
    Node<T> *m_head, *m_tail;

    // Sort Helper
    Node<T> *get_mid_prev(Node<T> *head) {
        Node<T> *slow, *fast, *mid_prev;
        slow = fast = head;
        while ((fast != nullptr) && (fast->next != nullptr)) {
            mid_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return mid_prev;
    }

    Node<T> *marged_accending(Node<T> *h1, Node<T> *h2) {
        Node<T> dummy_head;
        dummy_head.next = nullptr;

        Node<T> *marged_curr = &dummy_head;

        while ((h1 != nullptr) && (h2 != nullptr)) {
            Node<T> *to_add;
            if (h1->data < h2->data) {
                to_add = h1;
                h1 = h1->next;
            } else {
                to_add = h2;
                h2 = h2->next;
            }
            marged_curr->next = to_add;
            marged_curr = marged_curr->next;
        }
        marged_curr->next = (h1 != nullptr) ? h1 : h2;
        return dummy_head.next;
    }

    Node<T> *marge_sort(Node<T> *head) {
        // Base Case: null list or single element list
        if ((head == nullptr) || (head->next == nullptr))
            return head;

        Node<T> *mid_prev = get_mid_prev(head);

        // right - mid_prev->next  ..... NULL
        Node<T> *sorted_right = marge_sort(mid_prev->next);

        // left  - head ..... mid_prev
        mid_prev->next = nullptr;
        Node<T> *sorted_left = marge_sort(head);

        return marged_accending(sorted_left, sorted_right);
    }
    // ------Sort Helper------

    void free_list(Node<T> *head) {
        Node<T> *prev;
        while (head != nullptr) {
            prev = head;
            head = head->next;
            delete prev;
        }
    }

    void copy_from(const SinglyLinkedList<T> &other) {
        free_list(m_head);
        m_size = 0;
        m_head = m_tail = nullptr;

        Node<T> *h = other.m_head;
        while (h != nullptr) {
            this->push_back(h->data);
            h = h->next;
        }
    }

  public:
    SinglyLinkedList() : m_size(0), m_head(nullptr), m_tail(nullptr) {}

    SinglyLinkedList(const SinglyLinkedList<T> &other)
        : m_size(0), m_head(nullptr), m_tail(nullptr) {
        copy_from(other);
    }

    ~SinglyLinkedList() { free_list(m_head); }

    SinglyLinkedList<T> &operator=(const SinglyLinkedList<T> &other) {
        if (this == &other)
            return *this;
        copy_from(other);
        return *this;
    }

    bool is_empty() { return m_size == 0; }

    void push_front(T val) {
        m_size++;
        m_head = new Node<T>(val, m_head);
        if (m_size == 1)
            m_tail = m_head;
    }

    T pop_front() {
        if (m_head == nullptr)
            throw "Empty List!";

        Node<T> *old_head = m_head;
        m_head = m_head->next;

        T to_return = old_head->data;
        delete old_head;
        m_size--;

        if (m_size == 0)
            m_tail = m_head = nullptr;

        return to_return;
    }

    void push_back(T val) {
        m_size++;

        Node<T> *new_node = new Node<T>(val, nullptr);
        if (m_tail != nullptr)
            m_tail->next = new_node;

        m_tail = new_node;

        if (m_size == 1)
            m_head = m_tail;
    }

    void sort() { m_head = marge_sort(m_head); }

    void show_list(std::ostream &sout = std::cout) {
        Node<T> *head = m_head;
        while (head != nullptr) {
            sout << head->data << " -> ";
            head = head->next;
        }
        sout << std::endl;
    }
};

#endif // __SINGLY_LINKED_LIST__

/* TESTING CODE

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
*/