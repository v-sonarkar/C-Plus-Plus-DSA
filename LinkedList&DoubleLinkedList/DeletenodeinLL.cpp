// Deletion of a specific node in a Linked List
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

// Function to delete a specific node
void deleteNode(Node*& head, int key) {
    if (head == nullptr) return; // List is empty

    // If the head node itself holds the key to be deleted
    if (head->val == key) {
        Node* temp = head; // Store the current head
        head = head->next; // Move head to the next node
        delete temp; // Delete the old head
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->val != key) { // Traverse the list to find the node to be deleted
        current = current->next;
    }

    if (current->next == nullptr) return; // Key not found in the list
    
    Node* temp = current->next; // Node to be deleted
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

    deleteNode(a, 30);
    cout << "After deleting node with value 30: ";
    printList(a);

    return 0;
}