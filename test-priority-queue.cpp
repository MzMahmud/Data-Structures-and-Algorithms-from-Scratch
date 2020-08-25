#include "priority-queue.h"
#include <bits/stdc++.h>

using namespace std;

template <class T> void print_pq(PriorityQueue<T> pq) {
    cout << "---\n";
    while (!pq.is_empty()) {
        cout << pq.pop() << endl;
    }
    cout << "---\n";
}

template <class T> bool match(PriorityQueue<T> pq, const vector<T> &v) {
    int i = 0;
    while (!pq.is_empty()) {
        if (i >= v.size() or v[i++] != pq.pop())
            return false;
    }
    return i == v.size();
}

int main(int argc, char *argv[]) {
    // TODO:
    // not working!!
    // bug have to be fixed in heapify_up,heapify_down

    // PriorityQueue<int> pq;
    // pq.push(1);
    // pq.push(0);
    // pq.push(-8);
    // pq.push(7);
    // pq.push(19);
    // pq.push(7);
    // pq.push(91);
    // pq.push(-90);
    // pq.push(1);
    // pq.push(49);

    // {
    //     // copy constructor
    //     PriorityQueue<int> pq1 = pq;
    //     // PriorityQueue<int> pq1(pq);
    //     pq1.push(5);
    //     pq1.pop();
    //     pq1.push(50);
    //     pq1.push(-5);

    //     cout << "pq1\n";
    //     print_pq(pq1);
    // }

    // cout << "pq\n";
    // print_pq(pq);
    // check against random inputs to see that it gives the proper order
    // srand(time(NULL));

    // const int size = 20;
    // vector<int> nums(size);
    // for (int i = 0; i < size; i++) {
    //     int val = 1 + rand() % (size / 2);
    //     nums[i] = val;
    //     pq.push(val);
    // }

    // sort(begin(nums), end(nums));
    // reverse(begin(nums), end(nums));
    // print_pq(pq);

    // if (!match(pq, nums))
    //     cout << "WRONG :(" << endl;
    // else
    //     cout << "a OK :D" << endl;

    PriorityQueue<string> pq_str;
    pq_str.push(string("moaz"));
    pq_str.push(string("mon"));
    pq_str.push(string("abir"));
    pq_str.push(string("moon"));
    pq_str.push(string("maisha"));
    print_pq(pq_str);
    return 0;
}