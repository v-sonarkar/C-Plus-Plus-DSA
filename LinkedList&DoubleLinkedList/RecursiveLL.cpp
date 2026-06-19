// Recursive Functions for Linked List
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Recursive function to print the linked list
void printListRecursive(Node* head) {
    if (head == nullptr) return;
    cout << head->val << " ";
    printListRecursive(head->next);
}

int main() {
    Node * a = new Node(10);
    Node * b = new Node(20);
    Node * c = new Node(30);
    Node * d = new Node(40);
    Node * e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    cout << "Linked List (Recursive): ";
    printListRecursive(a);
    cout << endl;

    return 0;
}