# include <iostream>
# include <stack>
using namespace std;

void pushElementAtBottom(stack<int>& s, int element) {
   stack<int> temp;
    // Pop all elements from the original stack and push them onto the temporary stack
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    // Push the new element onto the original stack
    s.push(element);

    // Pop all elements from the temporary stack and push them back onto the original stack
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

    cout << "Stack elements before pushing at bottom: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    pushElementAtBottom(s, 60);

    cout << "Stack elements after pushing at bottom: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}