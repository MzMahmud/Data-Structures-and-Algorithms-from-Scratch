#ifndef __BASIC_SORT__

#define __BASIC_SORT__

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

template <class T> bool less_then(T a, T b) { return a < b; }

template <class T>
void bouble_sort(vector<T> &a, int begin_index, int end_index,
                 bool (*less)(T, T) = less_then) {

    if (begin_index >= end_index)
        return;

    int i = begin_index;
    while (i < end_index) {
        if (!less(a[i], a[i + 1]))
            swap(a[i], a[i + 1]);
        i++;
    }

    bouble_sort(a, begin_index, end_index - 1, less);
}

template <class T>
void insertion_sort(vector<T> &a, int begin_index, int end_index,
                    bool (*less)(T, T) = less_then) {

    if (begin_index >= end_index)
        return;

    int max_index = -1;

    for (int i = begin_index; i <= end_index; i++) {
        if ((max_index < 0) or !less(a[i], a[max_index])) {
            max_index = i;
        }
    }

    swap(a[max_index], a[end_index]);
    insertion_sort(a, begin_index, end_index - 1, less);
}

#endif //__BASIC_SORT__