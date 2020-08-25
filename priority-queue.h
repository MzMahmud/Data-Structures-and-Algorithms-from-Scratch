#ifndef __PRIORITY_QUEUE__

#define __PRIORITY_QUEUE__

#include "dynamic-array.h"
#include <vector>

template <class T> class PriorityQueue {
  private:
    size_t m_size;

    // DEBUG: There is a problem in Dynamic array code!
    // DynamicArray<T> m_heap;
    std::vector<T> m_heap;

    inline int left(int index) {
        // 0 based: 2*index + 1
        return (index << 1) + 1;
    }

    inline int right(int index) {
        // 0 based: 2*(index + 1)
        return (index + 1) << 1;
    }

    inline int parent(int index) {
        // odd -> 2i+1    -> (odd-1)/2
        // even-> 2(i+1)  -> even/2 - 1
        return (index & 1) ? ((index - 1) >> 1) : ((index >> 1) - 1);
    }

    inline bool has_left(int index) { return left(index) < m_size; }

    inline bool has_right(int index) { return right(index) < m_size; }

    inline bool is_leaf(int index) {
        return !(has_left(index) || has_right(index));
    }

    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void heapify_up(int index) {
        if (index <= 0)
            return;

        // taken as reference, beacuse it may needed to be swaped
        T &self_val = m_heap[index];
        T &parent_val = m_heap[parent(index)];

        // stop if parent >= self
        // parent >= self -> !!(parent >= self) -> !(parent < self)
        // done with < because class T is expected to have < overloaded
        if (!(parent_val < self_val))
            return;

        // swap with parent
        swap(self_val, parent_val);

        // recurrsive call on parent
        heapify_up(parent(index));
    }

    void heapify_down(int index) {
        if (is_leaf(index))
            return;

        // find the largest value
        // among current node,left child,right child
        // swap with that child and heapify_down recurrsively

        // in this implementation this great complexity
        // because i am assuming the user only has < overloaded!!
        // if we were allowed to use <= then it would have been easier

        // no left,may swap with right
        if (!has_left(index)) {
            T &p = m_heap[index];
            T &cr = m_heap[right(index)];
            if (p < cr) {
                swap(p, cr);
                heapify_down(right(index));
            }
        }
        // no right, may swap with left
        else if (!has_right(index)) {
            T &p = m_heap[index];
            T &cl = m_heap[left(index)];
            if (p < cl) {
                swap(p, cl);
                heapify_down(left(index));
            }
        }
        // has both
        else {
            T &p = m_heap[index];
            T &cl = m_heap[left(index)];
            T &cr = m_heap[right(index)];

            if (cl < cr) {
                if (p < cr) {
                    swap(p, cr);
                    heapify_down(right(index));
                }
            } else {
                if (p < cl) {
                    swap(p, cl);
                    heapify_down(left(index));
                }
            }
        }
    }

  public:
    PriorityQueue() { m_size = 0; }

    PriorityQueue(const PriorityQueue &other) {
        m_size = other.m_size;
        m_heap = other.m_heap;
    }

    PriorityQueue &operator=(const PriorityQueue &other) {
        if (this != &other) {
            m_size = other.m_size;
            m_heap = other.m_heap;
        }
        return *this;
    }

    size_t size() { return m_size; }

    bool is_empty() { return m_size == 0; }

    T front() { return m_heap[0]; }

    void push(T val) {
        // add value to the end
        m_heap.push_back(val);
        m_size++;

        // adjust the heap upword
        heapify_up(m_size - 1);
    }

    T pop() {
        T max_priority = front();

        // swap with last element
        swap(m_heap[0], m_heap[m_size - 1]);

        // remove last element
        m_heap.pop_back();
        m_size--;

        // adjust the heap downword
        heapify_down(0);

        return max_priority;
    }
};

#endif // __PRIORITY_QUEUE__