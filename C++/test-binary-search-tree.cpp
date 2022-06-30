#include <bits/stdc++.h>
#include "binary-search-tree.h"

using namespace std;

struct Pair{
    int a,b;
    Pair(int _a = 0,int _b = 0) : a(_a),b(_b){}

    Pair(const Pair &other) : a(other.a),b(other.b){
        cout << "copy constructor" << endl;
    }

    bool operator==(const Pair &other) const {
        return a == other.a && b == other.b;
    }
    bool operator<(const Pair &other) const {
        return (a == other.a) ? b < other.b
                              : a < other.a;
    }
};

ostream &operator<<(ostream &sout, const Pair &p){
    sout << "(" << p.a << ", " << p.b << ")";
    return sout;
}

int main() {
    vector<Pair> a;
    a.reserve(4);
    a.emplace_back(1,3);
    a.emplace_back(1,1);
    a.emplace_back(-1,2);
    a.emplace_back(2,3);

    BinarySearchTree<Pair> pair_bst;
    for(const auto &ai : a)
        pair_bst.insert(ai);
    cout << pair_bst << endl;

    BinarySearchTree<int> bst;
    // insert method
    bst.insert(-10);
    bst.insert(5);
    bst.insert(1);
    bst.insert(10);
    bst.insert(-8);
    bst.insert(19);

    // extractor (operator<<)
    cout << bst << endl;

    // contains method
    cout << "contains 1? " << boolalpha << bst.contains(1) << endl;
    cout << "contains 19? " << boolalpha << bst.contains(19) << endl;
    cout << "contains -5? " << boolalpha << bst.contains(-5) << endl;

    // remove method
    bst.remove(10);
    cout << "after removing 10 >> " << bst << endl;
    bst.remove(-8);
    cout << "after removing -8 >> " << bst << endl;
    bst.remove(-10);
    cout << "after removing -10 >> " << bst << endl;
    cout << "size " << bst.size() << endl;

    // empty scope for destructor test
    {
        // copy constructor
        // BinarySearchTree<int> bst2 = bst;

        BinarySearchTree<int> bst2;

        // assignment operator
        bst2 = bst;

        bst2.insert(42);
        bst2.insert(-13);
        cout << bst2 << endl;
    }

    cout << bst << endl;
    return 0;
}
