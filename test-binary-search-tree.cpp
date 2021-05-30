#include <bits/stdc++.h>
#include "binary-search-tree.h"

using namespace std;

int main() {
    BinarySearchTree<int> bst;
    bst.insert(-10);
    bst.insert(5);
    bst.insert(1);
    bst.insert(10);
    bst.insert(-8);
    bst.insert(19);
    cout << bst << endl;

    bst.remove(10);
    cout << "after removing 10 >> " << bst << endl;
    bst.remove(-8);
    cout << "after removing -8 >> " << bst << endl;
    bst.remove(-10);
    cout << "after removing -10 >> " << bst << endl;


    /*cout << bst.contains(1) << endl;
    cout << bst.contains(19) << endl;
    cout << bst.contains(-5) << endl;
    {
        // BinarySearchTree<int> bst2 = bst;
        BinarySearchTree<int> bst2;
        bst2 = bst;
        bst2.insert(42);
        bst2.insert(-13);
        cout << bst2 << endl;
    }

    cout << bst << endl;*/
    return 0;
}
