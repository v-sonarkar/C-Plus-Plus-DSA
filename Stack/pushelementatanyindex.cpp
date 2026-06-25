
#include <iostream>
#include <stack>
using namespace std;

void pushElementAtAnyIndex(stack<int>& s, int element, int index) {
    stack<int> temp;
    int size = s.size();

    if (index < 0 || index > size) {
        cout << "Invalid index" << endl;
        return;
    }

    for (int i = 0; i < index; i++) {
        temp.push(s.top());
        s.pop();
    }

    s.push(element);

    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // Print without modifying original stack
    stack<int> temp = s;

    cout << "Stack elements before pushing: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    pushElementAtAnyIndex(s, 60, 2);

    cout << "Stack elements after pushing: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}