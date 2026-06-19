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

     void deleteAtHead()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

     void deleteAtEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }

     void deleteAtPosition(int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0)
        {
            deleteAtHead();
            return;
        }
        if (position == size - 1)
        {
            deleteAtEnd();
            return;
        }
        Node *current = head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        Node *temp = current->next; // Node to be deleted
        current->next = temp->next;
        delete temp; // Delete the node
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

    list.deleteAtHead();
    cout << "After deleting head : "; 
    list.printList();
    list.deleteAtEnd();
    cout << "After deleting end: ";
    list.printList();
    list.deleteAtPosition(1);
    cout << "After deleting at position 1: ";
    list.printList();


    return 0;
}


