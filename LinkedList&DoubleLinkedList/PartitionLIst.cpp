// Partition a Linked List
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. You should preserve the original relative order of the nodes in each of the two partitions.
// Approach: We can create two separate linked lists, one for nodes less than x and another for nodes greater than or equal to x. We can then concatenate the two lists to get the final partitioned linked list.
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
// Simple approach with Time Complexity of O(n) and Space Complexity of O(n)
Node *partition(Node *head, int x)
{
    if (head == nullptr)
        return nullptr; // If the list is empty, return nullptr

    Node *lessHead = new Node(0);    // Dummy head for less than x
    Node *greaterHead = new Node(0); // Dummy head for greater than or equal to x
    Node *lessCurrent = lessHead;
    Node *greaterCurrent = greaterHead;

    Node *current = head;
    while (current != nullptr)
    {
        if (current->val < x)
        {
            lessCurrent->next = new Node(current->val);
            lessCurrent = lessCurrent->next;
        }
        else
        {
            greaterCurrent->next = new Node(current->val);
            greaterCurrent = greaterCurrent->next;
        }
        current = current->next;
    }

    // Concatenate the two lists
    lessCurrent->next = greaterHead->next;

    Node *result = lessHead->next;
    delete lessHead;    // Free the dummy node
    delete greaterHead; // Free the dummy node
    return result;      // Return the head of the partitioned linked list
}

int main()
{
    Node *a = new Node(1);
    Node *b = new Node(4);
    Node *c = new Node(3);
    Node *d = new Node(2);
    Node *e = new Node(5);
    Node *f = new Node(2);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    int x = 3;
    cout << "Partitioned list around " << x << ": ";
    Node *partitionedList = partition(a, x);
    while (partitionedList != nullptr)
    {
        cout << partitionedList->val << " ";
        partitionedList = partitionedList->next;
    }
    cout << endl;

    return 0;
}
