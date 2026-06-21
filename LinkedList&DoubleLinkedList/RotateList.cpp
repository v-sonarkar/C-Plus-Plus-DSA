// Rotate a Linked List by k places
// To rotate a linked list to the right by k places, we can follow these steps:
// 1. Find the length of the linked list and the last node.
// 2. Connect the last node to the head to make it a circular linked list.
// 3. Find the new tail of the rotated list, which will be at position (length - k % length) from the beginning.
// 4. Set the new head to be the next node of the new tail and break
//    the circular link by setting the next pointer of the new tail to null.
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

Node *rotateRight(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head; // No rotation needed for empty list, single node, or k=0

    // Step 1: Find the length of the linked list and the last node
    Node *temp = head;
    Node *tail = nullptr;
    int length = 1; // Start with 1 to count the head node
    while (temp->next != nullptr)
    {
        if (temp->next == nullptr)
            tail = temp; // Store the last node
        temp = temp->next;
        length++;
    }
    k = k % length; // Handle cases where k is greater than the length of the list
    if (k == 0)
        return head; // If k is 0 after modulo, no rotation needed
    temp = head;
    for (int i = 1; i < length - k; i++) // Move to the new tail position
    {
        temp = temp->next;
    }
    // Step 2: Connect the last node to the head to make it circular
    tail->next = head;
    head = temp->next;    // Step 3: Set the new head
    temp->next = nullptr; // Step 4: Break the circular link
    return head;          // Return the new head of the rotated list
}

// printing the rotated list in the main function
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    int k = 2; // Number of places to rotate
    Node *rotatedHead = rotateRight(a, k);

    // Print the rotated list
    printList(rotatedHead);

    return 0;
}