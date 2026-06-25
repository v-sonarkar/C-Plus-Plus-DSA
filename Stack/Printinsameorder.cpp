
# include <iostream>
# include <stack>
using namespace std;

void printStackInSameOrder(stack<int> s) {
    stack<int> temp;
    
    if (s.empty()) {
        cout << "Stack is empty" << endl;
        return;
    }
   while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    
    while (!temp.empty()) {
        cout << temp.top() << " ";
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
    
    cout << "Stack elements in same order: ";
    printStackInSameOrder(s);
    cout << endl;
    
    return 0;
}