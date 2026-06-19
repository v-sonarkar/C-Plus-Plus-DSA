// Removing the Nth node from the end of a linked list
// Last nth bode from the end means the (length - n + 1)th node from the start of the linked list. To remove the Nth node from the end, we can use a two-pointer technique. We maintain two pointers, first and second. We move the first pointer n+1 steps ahead, so that there is a gap of n nodes between the first and second pointers. Then, we move both pointers one step at a time until the first pointer reaches the end of the list. At this point, the second pointer will be pointing to the node just before the Nth node from the end. We can then remove the Nth node by updating the next pointer of the second node.
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

void removeNthFromEnd(Node *&head, int n)
{
    if (head == nullptr)
        return; // List is empty

    Node *dummy = new Node(0); // Create a dummy node to handle edge cases
    dummy->next = head;
    Node *first = dummy;
    Node *second = dummy;

    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++)
    {
        if (first == nullptr)
            return; // n is greater than the length of the list
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    // Remove the Nth node from the end
    Node *nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;

    head = dummy->next; // Update head in case the first node was removed
    delete dummy;       // Free the dummy node
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f= new Node(6);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;


cout<< " Original List: ";
    printList(a);

   


}