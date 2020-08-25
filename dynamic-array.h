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
        memcpy(m_a, old_a, m_size * sizeof(T));
        delete[] old_a;
    }

  public:
    DynamicArray(size_t cap = 4) {
        m_capacity = (cap < 4) ? 4 : cap;
        m_size = 0;
        m_a = new T[m_capacity];
    }

    DynamicArray(T init_value, size_t size) {
        m_size = size;
        m_capacity = (size <= 4) ? 4 : (size + (size >> 1));
        m_a = new T[m_capacity];

        for (int i = 0; i < m_size; ++i)
            m_a[i] = init_value;
    }

    DynamicArray(const DynamicArray &other) {
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_a = new T[m_capacity];

        for (int i = 0; i < m_size; i++)
            m_a[i] = other.m_a[i];
    }

    ~DynamicArray() {
        std::cout << "in dest\n";
        if (m_a != nullptr)
            delete[] m_a;
        std::cout << "end dest\n";
    }

    DynamicArray &operator=(const DynamicArray &other) {
        if (this == &other)
            return *this;

        if (m_capacity < other.m_capacity) {
            m_capacity = other.m_capacity;
            T *old_a = m_a;
            m_a = new T[m_capacity];
            delete[] old_a;
        }

        m_size = other.m_size;

        for (int i = 0; i < m_size; i++)
            m_a[i] = other.m_a[i];

        return *this;
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
        if (m_size == 0)
            throw std::string("Empty Array. Can't be popped!");
        m_size--;
    }

    T &operator[](int i) {
        if (i < 0 or i >= m_size)
            throw std::string("Index out of Bound!");
        return m_a[i];
    }
    T &operator[](int i) const {
        if (i < 0 or i >= m_size)
            throw std::string("Index out of Bound!");
        return m_a[i];
    }
};

template <class T>
std::ostream &operator<<(std::ostream &sout, const DynamicArray<T> &a) {
    int n = a.size();

    sout << "[";
    for (int i = 0; i < n; i++)
        sout << a[i] << (i == (n - 1) ? "" : ",");
    sout << "]";

    return sout;
}

#endif // __DYNAMIC_ARRAY__