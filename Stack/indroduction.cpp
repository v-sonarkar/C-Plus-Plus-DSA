// insertion and deletion happen at the top of the stack
// stack is a linear data structure that follows the LIFO (Last In First Out) principle
//add,delete,peek,isEmpty are the basic operations of stack 
//Time complexity of all the operations is O(1) and space complexity is O(n) where n is the size of the stack

#include <iostream>
using namespace std;
class Stack {
    int top;
    int capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }

    void push(int value) {
        if (top < capacity - 1) {
            top++;
            arr[top] = value;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {

    Stack stack(5);
    stack.push(10); 
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;


    return 0;
}