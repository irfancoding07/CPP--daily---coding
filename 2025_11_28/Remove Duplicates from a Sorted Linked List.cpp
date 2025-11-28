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

Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return head;
    }

    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {

        if (curr->data == curr->next->data) {
            Node* nodetodelete = curr->next;
            curr->next = curr->next->next;
            delete nodetodelete;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}

 
void insertEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print linked list
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
  
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 3);
    insertEnd(head, 3);
    insertEnd(head, 4);

    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}
