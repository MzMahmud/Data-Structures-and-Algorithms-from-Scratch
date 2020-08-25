#ifndef __QUEUE__

#define __QUEUE__

#include "singly-linked-list.h"

template <class T> class Queue {
  private:
    SinglyLinkedList<T> m_queue;

  public:
    Queue() {}

    Queue(const Queue &other) { m_queue = other.m_queue; }

    Queue &operator=(const Queue &other) {
        if (this != &other)
            m_queue = other.m_queue;

        return *this;
    }

    void clear() { m_queue.clear(); }

    bool is_empty() { return m_queue.is_empty(); }

    size_t size() { return m_queue.size(); }

    void push(T val) { m_queue.push_back(val); }

    T front() {
        if (m_queue.size() == 0)
            throw std::string("Empty Stack");
        return m_queue.front();
    }

    T pop() { return m_queue.pop_front(); }
};

#endif // __QUEUE__