// User defined Linked List class implementation

#include <iostream>
using namespace std;

class Node
{ // User defined Node class for linked list
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList
{ // User defined Linked List class
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insertAtPosition(int val, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0)
        {
            insertAtBeginning(val);
            return;
        }
        if (position == size)
        {
            insertAtEnd(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *current = head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next; // Point new node to the next node
        current->next = newNode;
        size++;
    }

    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    list.insertAtPosition(15, 2);

    cout << "Linked List: ";
    list.printList();

    cout << "Size of the linked list: " << list.size << endl;

    return 0;
}
