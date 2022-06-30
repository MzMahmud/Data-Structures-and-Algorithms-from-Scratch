#include "stack.h"
#include <bits/stdc++.h>

using namespace std;

template <class T> void print_stack(Stack<T> s) {
    cout << "---\n";
    while (!s.is_empty()) {
        cout << s.pop() << endl;
    }
    cout << "---\n";
}

int main(int argc, char *argv[]) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // copy constructor
    // Stack<int> s1 = s;
    // Stack<int> s1(s);

    {
        // in a new scopte to test
        // wheather deleting one object affects other

        // assignment operator
        Stack<int> s1;
        s1 = s;

        s1.pop();
        s1.push(-5);

        print_stack(s1);
    }

    // function pass by value
    print_stack(s);
    cout << "---\n";
    while (!s.is_empty()) {
        cout << s.pop() << endl;
    }
    cout << "---\n";

    s.clear();
    s.push(-1);
    s.push(1);
    s.push(-3);
    print_stack(s);

    // supports other classes
    Stack<string> s2;
    s2.push("moaz");
    s2.push("mahmud");
    s2.push("moon");
    s2.push("maisha");
    print_stack(s2);

    return 0;
}