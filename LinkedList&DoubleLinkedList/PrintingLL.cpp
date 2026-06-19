// Printing a Linked List
//First it store address of next node as Null
//Then stores the address of next node in the next pointer of current node
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

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
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

    printList(a);
    return 0;
}