#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Solution {
public:
    Node *moveToFront(Node *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node* seclast = NULL;
        Node* last = head;

        // Find last and second-last node
        while (last->next != NULL) {
            seclast = last;
            last = last->next;
        }

        // Remove last node from end
        seclast->next = NULL;

        // Move last node to front
        last->next = head;
        head = last;

        return head;
    }
};

void insertEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
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
    Node* head = NULL;

        insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.moveToFront(head);

    cout << "After moving last to front: ";
    printList(head);

    return 0;
}
