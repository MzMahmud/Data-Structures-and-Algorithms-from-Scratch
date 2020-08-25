#ifndef __SINGLY_LINKED_LIST__

#define __SINGLY_LINKED_LIST__

#include <iostream>

template <class T> class SinglyLinkedList {
  private:
    struct Node {
        T data;
        Node *next;

        Node() {}
        Node(T d, Node *n = nullptr) : data(d), next(n) {}
    };

    size_t m_size;
    Node *m_head, *m_tail;

    // Sort Helper
    Node *get_mid_prev(Node *head) {
        Node *slow, *fast, *mid_prev;
        slow = fast = head;
        while ((fast != nullptr) && (fast->next != nullptr)) {
            mid_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return mid_prev;
    }

    Node *marged_accending(Node *h1, Node *h2) {
        Node dummy_head;
        dummy_head.next = nullptr;

        Node *marged_curr = &dummy_head;

        while ((h1 != nullptr) && (h2 != nullptr)) {
            Node *to_add;
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

    Node *marge_sort(Node *head) {
        // Base Case: null list or single element list
        if ((head == nullptr) || (head->next == nullptr))
            return head;

        Node *mid_prev = get_mid_prev(head);

        // right - mid_prev->next  ..... NULL
        Node *sorted_right = marge_sort(mid_prev->next);

        // left  - head ..... mid_prev
        mid_prev->next = nullptr;
        Node *sorted_left = marge_sort(head);

        return marged_accending(sorted_left, sorted_right);
    }
    // ------Sort Helper------

    void free_list(Node *head) {
        Node *prev;
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

        Node *h = other.m_head;
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

    void clear() {
        free_list(m_head);
        m_size = 0;
        m_head = m_tail = nullptr;
    }

    SinglyLinkedList<T> &operator=(const SinglyLinkedList<T> &other) {
        if (this == &other)
            return *this;
        copy_from(other);
        return *this;
    }

    bool is_empty() { return m_size == 0; }

    size_t size() { return m_size; }

    T front() { return m_head->data; }
    T back() { return m_tail->data; }

    void push_front(T val) {
        m_size++;
        m_head = new Node(val, m_head);
        if (m_size == 1)
            m_tail = m_head;
    }

    T pop_front() {
        if (m_head == nullptr)
            throw "Empty List!";

        Node *old_head = m_head;
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

        Node *new_node = new Node(val, nullptr);
        if (m_tail != nullptr)
            m_tail->next = new_node;

        m_tail = new_node;

        if (m_size == 1)
            m_head = m_tail;
    }

    void sort() { m_head = marge_sort(m_head); }

    void show_list(std::ostream &sout = std::cout) {
        Node *head = m_head;
        while (head != nullptr) {
            sout << head->data << " -> ";
            head = head->next;
        }
        sout << std::endl;
    }
};

#endif // __SINGLY_LINKED_LIST__