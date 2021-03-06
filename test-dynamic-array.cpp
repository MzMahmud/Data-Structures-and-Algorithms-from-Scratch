#include "dynamic-array.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    // DynamicArray<int> a;

    // a.push_back(1);
    // a.push_back(2);
    // a.push_back(3);
    // a.push_back(4);

    // // copy constructor
    // DynamicArray<int> b(a);
    // // DynamicArray<int> b = a;

    // // assignment operator
    // // b = a;
    // a[3] = -4;
    // b[0] = 0;
    // b.pop_back();
    // b.pop_back();
    // cout << a << "\n" << b << endl;

    // DynamicArray<string> a;

    // a.push_back("moaz");
    // a.push_back("mahmud");
    // a.push_back("tanvir");

    // cout << a << endl;

    // int n = 3, m = 3;
    // DynamicArray<DynamicArray<int>> a(DynamicArray<int>(0, n), m);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         a[i][j] = m * i + j;
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << endl;
    // }

    DynamicArray<string> strs;
    strs.push_back("moaz");
    strs.push_back("moon");
    strs.push_back("maisha");
    strs.push_back("abir");
    strs.push_back("abir");
    strs.push_back("abir");
    strs.pop_back();
    strs.pop_back();
    strs.push_back("abir");
    strs.push_back("abir");

    {
        // DynamicArray<string> strs1(strs);
        DynamicArray<string> strs1;
        strs1 = strs;
        strs1.push_back("new");
        cout << "strs1 : ";
        cout << strs1 << endl;
    }
    cout << "strs :";
    cout << strs << endl;

    // test iterator
    cout << "with raw iterator" << endl;
    for (auto it = strs.begin(); it != strs.end(); ++it) {
        // change value with iterator
        if (*it == string("moaz"))
            *it = "MOAZ";
        cout << *it << endl;
    }
    cout << strs << endl;

    cout << "just print with for each loop " << endl;
    for (auto str : strs) {
        cout << str << endl;
    }

    cout << "change value with for each loop " << endl;
    for (auto &str : strs) {
        str.push_back('0');
    }
    cout << strs << endl;

    cout << "reverse iterator used to travarse backward\n";
    for (auto it = strs.rbegin(); it != strs.rend(); ++it) {
        // change value with reverse_iterator
        if (*it == string("MOAZ0"))
            *it = "moaz";
        cout << *it << endl;
    }
    cout << strs << endl;

    cout << "const auto&" << endl;
    for (const auto &str : strs) {
        cout << str << endl;
    }

    return 0;
}