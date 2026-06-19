// Cycle Detection in a Linked List
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

// Floyd's Cycle Detection Algorithm (Tortoise and Hare)
bool hasCycle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return false; // No cycle if list is empty or has only one node

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) // check if temp itself is not null and next of temp is not null
    {
        slow = slow->next;       // Move one step
        fast = fast->next->next; // Move two steps
        if (slow == fast)
            return true; // Cycle detected
    }

    return false; // No cycle found
}

int main()
{
    // Create a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 2 (cycle)
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = b; // Create a cycle

    if (hasCycle(a))
        cout << "Cycle detected." << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}

