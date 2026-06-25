

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

    void peek() {
        if (top >= 0) {
            cout << "Top element: " << arr[top] << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }
   
    int size() {
        return top + 1;
    }

    void printStack() {
        if (top >= 0) {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }
};
    int main() {

        Stack stack(5);
        stack.push(10); 
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.peek();
        stack.pop();
        stack.peek();
        stack.printStack();
        cout << "Stack size: " << stack.size() << endl;
    }