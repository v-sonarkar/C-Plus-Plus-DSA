
// Finding the intersection of two linked lists

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

// optimized approach is to use two pointers, one for each linked list. We traverse both lists simultaneously, and when a pointer reaches the end of its list, we redirect it to the head of the other list. If there is an intersection, the two pointers will eventually meet at the intersection point after at most two passes through the lists. If there is no intersection, both pointers will reach the end (nullptr) at the same time.
Node *findIntersectionOptimized(Node *head1, Node *head2)
{
    Node *current1 = head1;
    Node *current2 = head2;
    int len1 = 0, len2 = 0;
    while (current1 != nullptr)
    {
        len1++;
        current1 = current1->next;
    }
    while (current2 != nullptr)
    {
        len2++;
        current2 = current2->next;
    }
    current1 = head1;
    current2 = head2;
    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            current1 = current1->next;
        }
    }
    else
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            current2 = current2->next;
        }
    }

    while (current1 != nullptr && current2 != nullptr)
    {
        if (current1 == current2)
        {
            return current1; // Intersection found
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return nullptr; // No intersection found
}

int main()
{
    // Create first linked list: 1 -> 3 -> 5 -> 7 -> 9
    Node *a = new Node(1);
    Node *b = new Node(3);
    Node *c = new Node(5);
    Node *d = new Node(7);
    Node *e = new Node(9);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // Create second linked list: 2 -> 4 -> 5 -> 7 -> 9
    Node *f = new Node(2);
    Node *g = new Node(4);

    Node *h = c; // Intersection at node with value 5
    Node *i = d; // Intersection at node with value 7
    Node *j = e; // Intersection at node with value 9

    f->next = g;
    g->next = h;
    h->next = i;
    i->next = j;

    Node *intersection = findIntersectionOptimized(a, f);
    if (intersection != nullptr)
    {
        cout << "Intersection at node with value: " << intersection->val << endl;
    }
    else
    {
        cout << "No intersection found." << endl;
    }
    return 0;
}