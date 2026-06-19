// Insertion in a Linked List
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
//insert a new node at the beginning of the linked list
void insertNode(Node*& head, int key) {

    if (head == nullptr) {
        head = new Node(key);
        return;
    }
    Node* newNode = new Node(key);
    newNode->next = head;
    head = newNode;
}
//insert a new node at the end of the linked list
void insertNodeAtEnd(Node*& head, int key) {
    Node* newNode = new Node(key);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) { //Null se pehle tak jao
        current = current->next;
    }
    current->next = newNode;
}
//insert at a specific position in the linked list
void insertNodeAtPosition(Node*& head, int key, int position) {
    Node* newNode = new Node(key);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }
    newNode->next = current->next; // Point new node to the next node
    current->next = newNode;
}

//insert a new node after a specific node in the linked list
void insertNodeAfter(Node* prevNode, int key) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be null" << endl;
        return;
    }
    Node* newNode = new Node(key);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
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

    insertNode(a, 5);

    printList(a);

    return 0;
}