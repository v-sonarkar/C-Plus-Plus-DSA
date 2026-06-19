// Introduction to Linked Lists
// A linked list is a linear data structure that consists of a sequence of nodes, where each node contains data and a pointer to the next node in the sequence. Unlike arrays, linked lists do not require contiguous memory allocation, which allows for efficient insertion and deletion of elements.
// In a singly linked list, each node has a pointer to the next node, while in a doubly linked list, each node has pointers to both the next and previous nodes. This allows for more flexible traversal in a doubly linked list compared to a singly linked list.
// Linked lists are commonly used in various applications such as implementing stacks, queues, and other datastructures. They provide dynamic memory allocation and can grow or shrink in size as needed, making them a versatile choice for many programming tasks. However, linked lists may have higher memory overhead compared to arrays due to the storage of additional pointers, and they may not provide constant-time access to elements like arrays do.


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



int main() {
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    Node e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    //Print the linked list
    Node* current = &a;
    while (current!= nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    return 0;

}