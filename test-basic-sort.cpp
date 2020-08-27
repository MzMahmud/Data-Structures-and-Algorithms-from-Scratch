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

bool cmp(int a, int b) { return a > b; }

int main() {
    // const int SIZE = 20;
    // srand(time(NULL));
    // vector<int> stl_sorted(SIZE);
    // for (int i = 0; i < SIZE; i++)
    //     stl_sorted.push_back(rand() % 10);

    // vector<int> my_sorted(stl_sorted);

    // int n = stl_sorted.size();

    // sort(stl_sorted.begin(), stl_sorted.end(), cmp);
    // print(stl_sorted);

    // // bouble_sort(my_sorted, 0, n - 1, cmp);
    // insertion_sort(my_sorted, 0, n - 1, cmp);
    // print(my_sorted);

    // different type
    vector<string> strs;
    strs.push_back("moaz");
    strs.push_back("maisha");
    strs.push_back("moaz");
    strs.push_back("sabiha");
    strs.push_back("tanvid");

    print(strs);
    // bouble_sort(strs, 0, strs.size() - 1);
    insertion_sort(strs, 0, strs.size() - 1);
    print(strs);

    return 0;
}