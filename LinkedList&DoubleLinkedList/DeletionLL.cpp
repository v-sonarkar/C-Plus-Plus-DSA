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

void deleteAtHead(Node*& head) {
    if (head == nullptr) return; // List is empty
    Node* temp = head; // Store the current head
    head = head->next; // Move head to the next node
    delete temp; // Delete the old head
}

void deleteAtEnd(Node*& head) {
    if (head == nullptr) return; // List is empty
    if (head->next == nullptr) { // Only one node in the list
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next != nullptr) { // Traverse to the second last node
        current = current->next;
    }
    delete current->next; // Delete the last node
    current->next = nullptr; // Set the next of second last node to null
}
 void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) return; // List is empty
    if (position == 0) { // Delete the head node
        deleteAtHead(head);
        return;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current->next != nullptr; i++) {
        current = current->next;
    }
    if (current->next == nullptr) return; // Position is out of bounds
    Node* temp = current->next; // Store the node to be deleted
    current->next = current->next->next; // Bypass the node to be deleted
    delete temp; // Delete the node

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