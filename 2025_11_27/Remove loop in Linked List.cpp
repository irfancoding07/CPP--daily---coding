#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

 
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

 
void removeLoop(Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    Node* slow = head;
    Node* fast = head;

    // Detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop found
    if (slow != fast)
        return;

    // Find start of loop
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    // Find last node in loop
    Node* temp = slow;
    while (temp->next != slow)
        temp = temp->next;

    temp->next = NULL; // Remove loop
}
 
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() { 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

     
    head->next->next->next->next->next = head->next->next;

    // Detect loop
    if (detectLoop(head))
        cout << "Loop detected!" << endl;
    else
        cout << "No loop!" << endl;

    
    removeLoop(head);

 
    if (detectLoop(head))
        cout << "Loop still exists!" << endl;
    else
        cout << "Loop removed successfully!" << endl;
    printList(head);

    return 0;
}
