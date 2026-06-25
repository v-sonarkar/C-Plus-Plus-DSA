

#include <iostream>
#include <stack>
using namespace std;

void removeConsecutiveDuplicates(stack<int>& s) {
    stack<int> temp;
    int prev = -1; // Assuming all elements are non-negative

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (current != prev) {
            temp.push(current);
            prev = current;
        }
    }

    // Restore the original stack order
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(3);
    s.push(4);
    s.push(4);
    s.push(4);
    s.push(5);

    cout << "Original stack: ";
    stack<int> temp = s; // Create a copy to print without modifying the original stack
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    removeConsecutiveDuplicates(s);

    cout << "Stack after removing consecutive duplicates: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}