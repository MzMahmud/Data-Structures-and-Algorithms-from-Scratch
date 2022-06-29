#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__

#include <iostream>
#include <string>

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node *prev, *next;

        Node(const T &value, Node *prev, Node *next)
                : value(value), prev(prev), next(next) {}

        Node(const T &value) : Node(value, nullptr, nullptr) {}
    };

    Node *head, *tail;
    size_t length;

    Node *get_node(int index) {
        if (index < 0 || index > length) {
            return nullptr;
        }
        int curr_index = 0;
        Node *curr_node = head;
        while (curr_index < index) {
            curr_node = curr_node->next;
            ++curr_index;
        }
        return curr_node;
    }

public:
    DoublyLinkedList() {
        head = tail = nullptr;
        length = 0;
    }

    void insert_at_head(const T &value) {
        Node *new_node = new Node(value);
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        ++length;
    }

    T remove_head() {
        if (head == nullptr) {
            throw std::string("can not remove from head of an empty list");
        }
        Node *removed_node_ptr = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        T removed_value = removed_node_ptr->value;
        delete removed_node_ptr;
        --length;
        return removed_value;
    }

    void insert_at_tail(const T &value) {
        Node *new_node = new Node(value);
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ++length;
    }

    T remove_tail() {
        if (tail == nullptr) {
            throw std::string("can not remove from tail of an empty list");
        }
        Node *removed_node = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        T removed_value = removed_node->value;
        delete removed_node;
        --length;
        return removed_value;
    }

    T get(int index) {
        Node *node = get_node(index);
        if (node == nullptr) {
            throw std::string("no element found at index=") + std::to_string(index);
        }
        return node->value;
    }

    void insert_before_index(int index, const T &value) {
        if (length <= index) {
            insert_at_tail(value);
            return;
        }
        if (index == 0) {
            insert_at_head(value);
            return;
        }
        Node *node = get_node(index);
        if (node == nullptr) {
            return;
        }
        Node *new_node = new Node(value, node->prev, node);
        node->prev->next = new_node;
        node->prev = new_node;
        ++length;
    }

    T remove_index(int index) {
        if (index == 0) {
            return remove_head();
        }
        if (index == (length - 1)) {
            return remove_tail();
        }
        Node *node = get_node(index);
        if (node == nullptr) {
            throw std::string("no element to remove at index=") + std::to_string(index);
        }
        Node *removed_node = node;
        Node *prev_node = node->prev;
        Node *next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
        T removed_value = removed_node->value;
        delete removed_node;
        --length;
        return removed_value;
    }

    std::ostream &print(std::ostream &sout = std::cout) {
        Node *curr_node = head;
        while (curr_node != nullptr) {
            sout << curr_node->value << " <-> ";
            curr_node = curr_node->next;
        }
        sout << std::endl << "length=" << length << std::endl;
        return sout;
    }

    size_t get_length() const { return length; }

    size_t get_length() { return length; }

    struct iterator {
        Node *node;

        iterator(Node *node) : node(node) {}

        iterator &operator++() {
            node = node->next;
            return *this;
        }

        T &operator*() { return node->value; }

        const T &operator*() const { return node->value; }

        bool operator==(const iterator &other) const { return this->node == other.node; }

        bool operator!=(const iterator &other) const { return this->node != other.node; }
    };

    iterator begin() { return iterator(head); }

    iterator end() { return iterator(nullptr); }
};

#endif // __DOUBLY_LINKED_LIST__