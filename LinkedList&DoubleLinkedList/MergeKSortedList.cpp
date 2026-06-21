// Merge K Sorted  Linked Lists


#include <iostream>
#include <vector>
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

//Helper function to merge two sorted linked lists in place
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

    // Append any remaining nodes from either list
    if (l1 != nullptr)
        tempC->next = l1;
    else
        tempC->next = l2;

    Node *result = c->next;
    delete c; // Free the dummy node
    return result;
}

//Merge K sorted linked lists using divide and conquer approach
// First we merge the first two linked lists, then we merge the result with the third linked list, and so on until we have merged all the linked lists. This approach has a time complexity of O(N log K), where N is the total number of nodes across all linked lists and K is the number of linked lists.
Node *mergeKLists(vector<Node *> &lists)
{
    if (lists.empty())
        return nullptr; // If the list of linked lists is empty, return nullptr
    if (lists.size() == 1)
        return lists[0]; // If there is only one linked list, return it

    Node *mergedList = lists[0]; // Start with the first linked list

    for (size_t i = 1; i < lists.size(); i++)
    {
        mergedList = mergeTwoListsInPlace(mergedList, lists[i]); // Merge the current merged list with the next linked list
    }

    return mergedList; // Return the final merged linked list
}

int main()
{
    // Create K sorted linked lists
    Node *a = new Node(1);
    Node *b = new Node(4);
    Node *c = new Node(7);
    a->next = b;
    b->next = c;

    Node *d = new Node(2);
    Node *e = new Node(5);
    Node *f = new Node(8);
    d->next = e;
    e->next = f;

    Node *g = new Node(3);
    Node *h = new Node(6);
    Node *i = new Node(9);
    g->next = h;
    h->next = i;

    vector<Node *> lists = {a, d, g}; // Vector of linked lists

    // Merge K sorted linked lists
    Node *mergedList = mergeKLists(lists);

    // Print the merged linked list
    cout << "Merged K sorted linked lists: ";
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}