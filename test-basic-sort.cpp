#include "basic-sort.h"
#include <bits/stdc++.h>

using namespace std;

template <class T>

void print(const vector<T> &a) {
    for (const T &ai : a)
        cout << ai << " ";
    cout << endl;
}

template <class T>
bool match(const vector<T> &stl_sorted, const vector<T> &my_sorted) {
    if (stl_sorted.size() != my_sorted.size())
        return false;

    for (int i = 0; i < stl_sorted.size(); i++)
        if (stl_sorted[i] != my_sorted[i])
            return false;

    return true;
}

// decending order of last digit
bool decending_by_last_digit(int a, int b) {
    return (abs(a) % 10) > (abs(b) % 10);
}

// decending order of absalute value
// bool cmp(int a, int b) { return abs(a) > abs(b); }

int main() {
    // const int SIZE = 10;
    // srand(time(NULL));
    // vector<int> stl_sorted(SIZE);
    // for (int i = 0; i < SIZE; i++)
    //     stl_sorted.push_back(rand() % 15);

    // vector<int> my_sorted(stl_sorted);

    // sort(stl_sorted.begin(), stl_sorted.end(), decending_by_last_digit);
    // print(stl_sorted);

    vector<int> my_sorted
        = {9, -8, 7, 4, 6, 5, 1, 0, 2, 9, 1, 9, 1, 65, -9, 8, 46, -89, 36};
    int n = my_sorted.size();
    print(my_sorted);

    // bouble_sort_recursive(my_sorted, 0, n - 1);
    // bouble_sort_recursive(my_sorted, 0, n - 1, decending_by_last_digit);

    // bouble_sort(my_sorted, 0, n - 1);
    // bouble_sort(my_sorted, 0, n - 1, decending_by_last_digit);

    // selection_sort_recursive(my_sorted, 0, n - 1);
    // selection_sort_recursive(my_sorted, 0, n - 1, decending_by_last_digit);

    // selection_sort(my_sorted, 0, n - 1);
    // selection_sort(my_sorted, 0, n - 1, decending_by_last_digit);

    // insertion_sort_recursive(my_sorted, 0, n - 1);
    // insertion_sort_recursive(my_sorted, 0, n - 1, decending_by_last_digit);

    // insertion_sort(my_sorted, 0, n - 1);
    // insertion_sort(my_sorted, 0, n - 1, decending_by_last_digit);

    // bouble_sort_recursive(my_sorted.begin(), my_sorted.end(),
    //                       decending_by_last_digit);
    bouble_sort_recursive(my_sorted.begin(), my_sorted.end());
    print(my_sorted);

    // different type
    // vector<string> strs;
    // strs.push_back("moaz");
    // strs.push_back("maisha");
    // strs.push_back("moaz");
    // strs.push_back("sabiha");
    // strs.push_back("tanvid");

    // print(strs);
    // // bouble_sort(strs, 0, strs.size() - 1);
    // insertion_sort(strs, 0, strs.size() - 1);
    // print(strs);

    return 0;
}