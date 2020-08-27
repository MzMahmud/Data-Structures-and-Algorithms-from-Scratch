#ifndef __BASIC_SORT__

#define __BASIC_SORT__

#include <algorithm>
#include <vector>

template <class T> bool less_then(T a, T b) { return a < b; }

// recursiove one is easy to understand
template <class T>
void bouble_sort_recursive(std::vector<T> &a, int begin_index, int end_index,
                           bool (*compare_function)(T, T) = less_then) {

    if (begin_index >= end_index)
        return;

    // for each run, boubles up the largest element to the end
    int i = begin_index;
    while (i < end_index) {
        if (!compare_function(a[i], a[i + 1]))
            std::swap(a[i], a[i + 1]);
        i++;
    }

    // the largest one is in its position ie.the last position; sort the rest
    bouble_sort_recursive(a, begin_index, end_index - 1, compare_function);
}

// if you've understood the recursive one,it would seem easy
template <class T>
void bouble_sort(std::vector<T> &a, int begin_index, int end_index,
                 bool (*compare_function)(T, T) = less_then) {

    while (begin_index < end_index) {
        for (int i = begin_index; i < end_index; i++) {
            if (!compare_function(a[i], a[i + 1]))
                std::swap(a[i], a[i + 1]);
        }
        end_index--;
    }
}

// recursiove one is easy to understand
template <class T>
void selection_sort_recursive(std::vector<T> &a, int begin_index, int end_index,
                              bool (*compare_function)(T, T) = less_then) {

    if (begin_index >= end_index)
        return;

    // in each pass, select the minimum element
    int min_index = begin_index;
    for (int i = begin_index + 1; i <= end_index; i++) {
        if (compare_function(a[i], a[min_index])) {
            min_index = i;
        }
    }
    // put the minimum element in the beginning
    std::swap(a[begin_index], a[min_index]);
    // sort the rest
    selection_sort_recursive(a, begin_index + 1, end_index, compare_function);
}

// if you've understood the recursive one,it would seem easy
template <class T>
void selection_sort(std::vector<T> &a, int begin_index, int end_index,
                    bool (*compare_function)(T, T) = less_then) {

    while (begin_index < end_index) {
        int min_index = begin_index;
        for (int i = begin_index + 1; i <= end_index; i++) {
            if (compare_function(a[i], a[min_index])) {
                min_index = i;
            }
        }
        std::swap(a[begin_index], a[min_index]);
        begin_index++;
    }
}

// recursiove one is easy to understand
template <class T>
void insertion_sort_recursive(std::vector<T> &a, int begin_index, int end_index,
                              bool (*compare_function)(T, T) = less_then) {

    if (begin_index >= end_index)
        return;

    // sort just before the last index
    insertion_sort_recursive(a, begin_index, end_index - 1, compare_function);

    // put the last element to its proper place
    int item = a[end_index];
    int i = end_index - 1;
    // while i-th index is not smaller than item,its not the proper spot
    while (i >= begin_index and !compare_function(a[i], item)) {
        // shift the bigger element one place right
        a[i + 1] = a[i];
        i--;
    }
    // i-th index is the element which is the one that is smaller then last
    // put last element one pass i. We have made space by shofting others
    a[i + 1] = item;
}

// if you've understood the recursive one,it would seem easy
template <class T>
void insertion_sort(std::vector<T> &a, int begin_index, int end_index,
                    bool (*compare_function)(T, T) = less_then) {

    for (int right = begin_index + 1; right <= end_index; right++) {
        int item = a[right];
        int i = right - 1;
        while (i >= begin_index and !compare_function(a[i], item)) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = item;
    }
}

#endif //__BASIC_SORT__