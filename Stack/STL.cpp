

#include <iostream>
#include <stack>
using namespace std;

//print the top element of the stack and pop it  in reverse order until the stack is empty
void printAndPop(stack<int>& s) {
    if (!s.empty()) {
        cout << "Top element: " << s.top() << endl;
        s.pop();
    } else {
        cout << "Stack is empty" << endl;
    }
}

//using extra stack to print the elements of the stack in reverse order without modifying the original stack
void printStackInReverse(stack<int> s) {
    stack<int> temp;
    while (!s.empty()) {
        cout << s.top() << " ";
        temp.push(s.top());
        s.pop();
    }
    
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    cout << endl;
}

  


int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    cout << "Printing and popping all elements:" << endl;
    while (!s.empty()) {
        printAndPop(s);
    }
    
    
    
    return 0;
}