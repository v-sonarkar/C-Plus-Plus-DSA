// Copy List with Random Pointer
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    // Step 1: Create a mapping from original nodes to copied nodes
    unordered_map<Node*, Node*> nodeMap;
    Node* current = head;
    while (current) {
        nodeMap[current] = new Node(current->val);
        current = current->next;
    }

    // Step 2: Assign next and random pointers for the copied nodes
    current = head;
    while (current) {
        nodeMap[current]->next = nodeMap[current->next];
        nodeMap[current]->random = nodeMap[current->random];
        current = current->next;
    }

    return nodeMap[head];
}

int main() {
    // Create a linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->random = head->next; // Random pointer from node 1 to node 2
    head->next->random = head; // Random pointer from node 2 to node 1

    // Copy the linked list
    Node* copiedHead = copyRandomList(head);

    // Print the values and random pointers of the copied list
    Node* current = copiedHead;
    while (current) {
        cout << "Node value: " << current->val << ", Random points to: " 
             << (current->random ? current->random->val : -1) << endl;
        current = current->next;
    }

    return 0;
}