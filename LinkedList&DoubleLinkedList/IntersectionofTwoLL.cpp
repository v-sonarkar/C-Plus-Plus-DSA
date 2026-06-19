
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

Node *findIntersection(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;

    Node *current1 = head1;
    Node *current2 = head2;

    // Traverse both lists to find their lengths
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

    // Reset pointers to the heads of both lists
    current1 = head1;
    current2 = head2;

    // Move the pointer of the longer list ahead by the difference in lengths
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

    // Now move both pointers until they meet at the intersection point
    while (current1 != nullptr && current2 != nullptr)
    {
        if (current1 == current2)
            return current1; // Intersection found

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

    Node *intersection = findIntersection(a, f);
    if (intersection != nullptr)
    {
        cout << "Intersection found at node with value: " << intersection->val << endl;
    }
    else
    {
        cout << "No intersection found." << endl;
    }

    return 0;
}