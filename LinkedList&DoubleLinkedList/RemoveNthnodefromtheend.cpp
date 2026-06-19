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
// Two time traversal approach
Node *removeNthFromEnd(Node *&head, int n)
{
    int length = 0;
    Node *current = head;
    while (current != nullptr)
    {
        length++;
        current = current->next;
    }
    int m = length - n + 1; // m is the position of the node to be removed from the start of the linked list
    int idx = m - 1;        // idx is the position of the node just before the node to be removed from the start of the linked list
    if (idx == 0)           // If the node to be removed is the head node
    {
        head = head->next; // Update the head pointer to the next node
        return head;
    }
    current = head;               // Reset the current pointer to the head of the linked list
    for (int i = 1; i < idx; i++) // Move the current pointer to the node just before the node to be removed
    {
        current = current->next;
    }
    current->next = current->next->next; // Update the next pointer of the current node to skip the node to be removed
    return head;
}

// Using slow and fast pointer technique, we can remove the Nth node from the end in a single traversal. We maintain two pointers, first and second. We move the first pointer n+1 steps ahead, so that there is a gap of n nodes between the first and second pointers. Then, we move both pointers one step at a time until the first pointer reaches the end of the list. At this point, the second pointer will be pointing to the node just before the Nth node from the end. We can then remove the Nth node by updating the next pointer of the second node.
Node *removeNthFromEndOnePass(Node *&head, int n)
{

    // Take the fast to n+1 steps ahead of slow pointer
    // Then move both pointers one step at a time until the fast pointer reaches the end of the list. At this point, the slow pointer will be pointing to the node just before the Nth node from the end. We can then remove the Nth node by updating the next pointer of the slow node.
    if (head == nullptr)
        return nullptr; // List is empty
    Node *slow = head;

    Node *fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // Now, slow points to the node just before the Nth node from the end
    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

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
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    int n = 2; // Remove the 2nd node from the end (which is node with value 5)
    cout << "Original list: ";
    printList(a);
    removeNthFromEnd(a, n);
    printList(a);
}

