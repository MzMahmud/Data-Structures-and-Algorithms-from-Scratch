#include "queue.h"
#include <bits/stdc++.h>

using namespace std;

template <class T> void print_queue(Queue<T> q) {
    while (!q.is_empty()) {
        cout << q.pop() << " - ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    {
        // in a new scopte to test
        // wheather deleting one object affects other
        // copy constructor
        // Queue<int> q1 = q;
        Queue<int> q1(q);

        // Queue<int> q1;
        // assignment operator
        // q1 = q;

        q1.pop();
        q1.push(-5);

        cout << "q1 ";
        print_queue(q1);
    }

    // function pass by value
    cout << "q in func ";
    print_queue(q);

    cout << "q ";
    while (!q.is_empty()) {
        cout << q.pop() << " - ";
    }
    cout << endl;

    cout << "q ater clear ";
    q.clear();
    q.push(-1);
    q.push(1);
    q.push(-3);
    print_queue(q);

    // supports other classes
    Queue<string> q2;
    q2.push("moaz");
    q2.push("mahmud");
    q2.push("moon");
    q2.push("maisha");

    cout << "q2 ";
    print_queue(q2);

    return 0;
}