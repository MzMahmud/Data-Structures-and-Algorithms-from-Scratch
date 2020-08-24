#ifndef __DYNAMIC_ARRAY__

#define __DYNAMIC_ARRAY__

#include <iostream>

template <class T> class DynamicArray {
  private:
    size_t m_capacity, m_size;
    T *m_a;

    void reallocate() {
        T *old_a = m_a;
        m_a = new T[m_capacity];
        memmove(m_a, old_a, m_size * sizeof(T));
        delete[] old_a;
    }

  public:
    DynamicArray(size_t cap = 4) {
        m_capacity = cap;
        m_size = 0;
        m_a = new T[m_capacity];
    }

    size_t size() { return m_size; }
    size_t size() const { return m_size; }

    size_t capacity() { return m_capacity; }
    size_t capacity() const { return m_capacity; }

    void push_back(T val) {
        if (m_size == m_capacity) {
            // m_capacity = 1.5 * m_capacity
            m_capacity = m_capacity + (m_capacity >> 1);
            reallocate();
        }

        m_a[m_size++] = val;
    }

    void pop_back() {
        if (m_size)
            m_size--;
    }

    T &operator[](int i) { return m_a[i]; }
    const T &operator[](int i) const { return m_a[i]; }
};

template <class T>
std::ostream &operator<<(std::ostream &sout, const DynamicArray<T> &a) {
    sout << "[";
    int n = a.size();
    for (int i = 0; i < n; i++)
        sout << a[i] << (i == (n - 1) ? "]" : ",");
    return sout;
}

#endif // __DYNAMIC_ARRAY__