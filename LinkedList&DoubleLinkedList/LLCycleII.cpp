// Detecting a cycle in a linked list
//from where the cycle starts
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

//put a temp node at the head and move slow from the point where slow and fast met and move temp from head and check if they meet at some point then return that point
Node *detectCycle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr; // No cycle if list is empty or has only one node

    Node *slow = head;
    Node *fast = head;

    // First, detect if a cycle exists using Floyd's Cycle Detection Algorithm
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Move one step
        fast = fast->next->next; // Move two steps
        if (slow == fast)
        {
            // Cycle detected, now find the starting point of the cycle
            Node *temp = head;
            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            return temp; // Return the starting point of the cycle
        }
    }

    return nullptr; // No cycle found
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

    Node *cycleStartNode = detectCycle(a);
    if (cycleStartNode != nullptr)
        cout << "Cycle detected. The cycle starts at node with value: " << cycleStartNode->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}