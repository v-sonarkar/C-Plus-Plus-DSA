// Merge Two Sorted Linked Lists
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

//with Time Complexity of O(n+m) and Space Complexity of O(n+m)
Node *mergeTwoLists(Node *l1, Node *l2)
{
    Node *tempA = l1;
    Node *tempB = l2;
    Node *c = new Node(0);
    Node *tempC = c;

    while (tempA != nullptr && tempB != nullptr)
    {
        if (tempA->val < tempB->val)
        {
            Node *newNode = new Node(tempA->val);
            tempC->next = newNode;
            tempC = newNode;
            tempA = tempA->next;
        }
        else
        {
            Node *newNode = new Node(tempB->val);
            tempC->next = newNode;
            tempC = newNode;
            tempB = tempB->next;
        }
    }

    if (tempA == nullptr)
    {
        tempC->next = tempB;
    }
    else if (tempB == nullptr)
    {
        tempC->next = tempA;
    }

    return c->next;
}

//with Time Complexity of O(n+m) and Space Complexity of O(1)
Node *mergeTwoListsInPlace(Node *l1, Node *l2)
{
    Node *c = new Node(0);
    Node *tempC = c;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            tempC->next = l1;
            l1 = l1->next;
        }
        else
        {
            tempC->next = l2;
            l2 = l2->next;
        }

        tempC = tempC->next;
    }

    if (l1 != nullptr)
    {
        tempC->next = l1;
    }
    else
    {
        tempC->next = l2;
    }

    Node *result = c->next;
    delete c;

    return result;
}

int main()
{
    Node *a = new Node(1);
    Node *b = new Node(3);
    Node *c = new Node(5);

    a->next = b;
    b->next = c;

    Node *d = new Node(2);
    Node *e = new Node(4);
    Node *f = new Node(6);

    d->next = e;
    e->next = f;

    cout << "Merged list (new nodes): ";
    Node *mergedList1 = mergeTwoLists(a, d);
    while (mergedList1 != nullptr)
    {
        cout << mergedList1->val << " ";
        mergedList1 = mergedList1->next;
    }
    cout << endl;

    // Reset the original lists for the in-place merge
    a->next = b;
    b->next = c;
    d->next = e;
    e->next = f;

    cout << "Merged list (in-place): ";
    Node *mergedList2 = mergeTwoListsInPlace(a, d);
    while (mergedList2 != nullptr)
    {
        cout << mergedList2->val << " ";
        mergedList2 = mergedList2->next;
    }
    cout << endl;

    return 0;
}