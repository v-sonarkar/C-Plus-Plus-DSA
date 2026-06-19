// Finding the middle node of a linked list
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

// Simple approach is to traverse the linked list and count the number of nodes. Then, traverse the list again to reach the middle node. This approach takes O(n) time and O(1) space.
Node *findMiddleSimple(Node *head)
{
    if (head == nullptr)
        return nullptr; // List is empty

    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    int middleIndex = count / 2;
    current = head;
    for (int i = 0; i < middleIndex; i++)
    {
        current = current->next;
    }

    return current; // Return the middle node
}
//Using the two-pointer technique, we can find the middle node in a single traversal. We maintain two pointers, slow and fast. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle node. This approach takes O(n) time and O(1) space.
Node *findMiddle(Node *head)
{
    if (head == nullptr)
        return nullptr; // List is empty

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) // check if temp itself is not null and next of temp is not null
    //First condition is for odd length linked list and second condition is for even length linked list
    {
        slow = slow->next;       // Move one step
        fast = fast->next->next; // Move two steps
    }

    return slow; // slow will be at the middle node
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Node *middle = findMiddle(a);
    if (middle != nullptr)
    {
        cout << "Middle node value: " << middle->val << endl;
    }

    return 0;
}