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

    LinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtPosition(int val, int position)
    {
        Node *newNode = new Node(val);
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

    void display()
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
    list.display();

    return 0;
}