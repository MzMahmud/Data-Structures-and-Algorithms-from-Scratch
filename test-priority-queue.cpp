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

int main(int argc, char *argv[]) {
    // TODO:
    // not working!!
    // bug have to be fixed in heapify_up,heapify_down

    PriorityQueue<int> pq;
    pq.push(1);
    pq.push(0);
    pq.push(-8);
    pq.push(7);
    pq.push(19);
    pq.push(91);
    pq.push(90);
    pq.push(49);
    print_pq(pq);

    return 0;
}