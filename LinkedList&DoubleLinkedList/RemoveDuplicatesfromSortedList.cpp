// Remove Duplicates from a Sorted Linked List
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

Node *removeDuplicates(Node *head)
{
    if (head == nullptr)
        return nullptr; // If the list is empty, return nullptr
    if (head->next == nullptr)
        return head; // If the list has only one node, return head
    Node *current = head;

    while (current != nullptr && current->next != nullptr)
    {
        if (current->val == current->next->val)
        {
            // Duplicate found, remove it

            current->next = current->next->next;
            delete current->next; // Free memory of the removed node
        }
        else
        {
            current = current->next; // Move to the next node
        }
    }

    return head; // Return the modified list
}
// Using Two Pointer Approach
Node *removeDuplicatesTwoPointer(Node *head)
{
    if (head == nullptr)
        return nullptr; // If the list is empty, return nullptr
    if (head->next == nullptr)
        return head; // If the list has only one node, return head

    Node *a = head;
    Node *b = head->next;

    while (b != nullptr)
    {
        while (b != nullptr && b->val == a->val)
        {
            b = b->next;
        }
        a->next = b;

        // Move a to the next unique node
        a = b;

        if (b != nullptr)
        {
            b = b->next;
        }
    }
    return head; // Return the modified list
}

// print the linked list
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
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    Node *a = new Node(1);
    Node *b = new Node(1);
    Node *c = new Node(2);
    Node *d = new Node(3);
    Node *e = new Node(3);
    Node *f = new Node(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    cout << "Original list: ";
    printList(a);

    a = removeDuplicates(a);

    cout << "List after removing duplicates: ";
    printList(a);

    return 0;
}