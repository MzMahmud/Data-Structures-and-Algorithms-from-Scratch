#ifndef __QUICK_SORT__

#define __QUICK_SORT__

#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

void quick_sort(vector<int> &a, int begin_index, int end_index) {
    if (begin_index >= end_index)
        return;

    int pivot = a[end_index];
    int lowest_index = begin_index;
    for (int i = begin_index; i < end_index; i++) {
        if (a[i] < pivot) {
            swap(a[lowest_index++], a[i]);
        }
    }
    swap(a[lowest_index], a[end_index]);

    quick_sort(a, begin_index, lowest_index - 1);
    quick_sort(a, lowest_index + 1, end_index);
}

#endif // __QUICK_SORT__
