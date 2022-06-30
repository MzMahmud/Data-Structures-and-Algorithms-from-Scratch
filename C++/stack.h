#ifndef __STACK__

#define __STACK__

#include "singly-linked-list.h"

template <class T> class Stack {
  private:
    SinglyLinkedList<T> m_stack;

  public:
    Stack() {}

    Stack(const Stack &other) { m_stack = other.m_stack; }

    Stack &operator=(const Stack &other) {
        if (this != &other)
            m_stack = other.m_stack;

        return *this;
    }

    void clear() { m_stack.clear(); }

    bool is_empty() { return m_stack.is_empty(); }

    size_t size() { return m_stack.size(); }

    void push(T val) { m_stack.push_front(val); }

    T top() {
        if (m_stack.size() == 0)
            throw std::string("Empty Stack");
        return m_stack.front();
    }

    T pop() { return m_stack.pop_front(); }
};

#endif //__STACK__