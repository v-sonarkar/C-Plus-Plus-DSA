// User defined Linked List class implementation

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

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int key)
    {
        Node *newNode = new Node(key);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAtBeginning(int key)
    {
        Node *newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int key, int position)
    {
        Node *newNode = new Node(key);
        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
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
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    list.printList();

    list.insertAtBeginning(5);

    list.insertAtPosition(15, 2);
    list.insertAtPosition(25, 3);
    list.insertAtPosition(35, 5);

    list.printList();

    return 0;
}