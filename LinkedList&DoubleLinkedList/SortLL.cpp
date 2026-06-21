// Sort a Linked List
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

//Simple approach is to store the values of the linked list in an array, sort the array, and then create a new sorted linked list from the sorted array. This approach has a time complexity of O(n log n) due to the sorting step and a space complexity of O(n) for storing the values in an array.
Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head; // If the list is empty or has only one node, it's already sorted

    // Step 1: Store the values of the linked list in an array
    vector<int> values;
    Node *current = head;
    while (current != nullptr)
    {
        values.push_back(current->val);
        current = current->next;
    }

    // Step 2: Sort the array
    sort(values.begin(), values.end());

    // Step 3: Create a new sorted linked list from the sorted array
    Node *sortedHead = new Node(values[0]);
    Node *sortedCurrent = sortedHead;
    for (int i = 1; i < values.size(); ++i)
    {
        sortedCurrent->next = new Node(values[i]);
        sortedCurrent = sortedCurrent->next;
    }

    return sortedHead; // Return the head of the new sorted linked list
}

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

Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head; // Base case: if the list is empty or has only one node, it's already sorted

    // Step 1: Split the linked list into two halves
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr; // Split the list into two halves

    // Step 2: Recursively sort both halves
    Node *leftHalf = mergeSort(head);
    Node *rightHalf = mergeSort(slow);

    // Step 3: Merge the two sorted halves
    return mergeTwoListsInPlace(leftHalf, rightHalf);
}

//Print the linked list
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
    Node *a = new Node(4);
    Node *b = new Node(2);
    Node *c = new Node(1);
    Node *d = new Node(3);

    a->next = b;
    b->next = c;
    c->next = d;
    printList(a);

    // Sort the linked list using merge sort
    Node *sortedList = mergeSort(a);
    printList(sortedList);
    
    return 0;
}   