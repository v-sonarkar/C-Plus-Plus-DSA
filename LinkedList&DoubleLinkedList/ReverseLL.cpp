// Reverse a Linked List
// Given the head of a singly linked list, reverse the list, and return the new head.
// Approach: We can use an iterative approach to reverse the linked list by maintaining pointers to the previous, current, and next nodes.
#include <iostream>
#include <vector>
#include <algorithm>
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

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *Next = nullptr;

    while (current != nullptr)
    {
        Next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current node
        current = Next;       // Move current to next node
    }

    return prev; // Return the new head of the reversed list
}

//Simple approach is to store the values of the linked list in an array, reverse the array, and then create a new reversed linked list from the reversed array. This approach has a time complexity of O(n) and a space complexity of O(n).
Node *reverseListUsingArray(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head; // If the list is empty or has only one node, it's already reversed

    // Step 1: Store the values of the linked list in an array
    vector<int> values;
    Node *current = head;
    while (current != nullptr)
    {
        values.push_back(current->val);
        current = current->next;
    }

    // Step 2: Reverse the array
    reverse(values.begin(), values.end());

    // Step 3: Create a new reversed linked list from the reversed array
    Node *reversedHead = new Node(values[0]);
    Node *reversedCurrent = reversedHead;
    for (size_t i = 1; i < values.size(); ++i)
    {
        reversedCurrent->next = new Node(values[i]);
        reversedCurrent = reversedCurrent->next;
    }

    return reversedHead; // Return the head of the new reversed linked list
}


// printing the reversed list in the main function
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

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    cout << "Original list: ";
    printList(a);

    Node *reversedList = reverseList(a);
    cout << "Reversed list (iterative): ";
    printList(reversedList);    

    // Reversing the list again using the array method
    Node *reversedListUsingArray = reverseListUsingArray(reversedList); 
    cout << "Reversed list (using array): ";
    printList(reversedListUsingArray);

    return 0;
}