// Deletion in a Linked List
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

void deleteNode(Node*& head, int key) {
    if (head == nullptr) return;

    // If the node to be deleted is the head node
    if (head->val == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->val != key) {
        current = current->next;
    }

    // If the node was found, delete it
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
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