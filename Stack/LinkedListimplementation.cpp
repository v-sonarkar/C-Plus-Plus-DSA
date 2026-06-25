#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class Stack {
    Node* head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    void push(int value) {
        Node* temp = new Node(value);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int peek() {
        if (head == nullptr) return -1;
        return head->val;
    }

    void printStack() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;
    stack.printStack();
    return 0;
}