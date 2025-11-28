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
    if (head == NULL)
        return NULL;

    Node* curr = head;

    while (curr != NULL) {
        Node* temp = curr;

        while (temp->next != NULL) {
            if (temp->next->data == curr->data) {
                Node* nodetodelete = temp->next;
                temp->next = temp->next->next;
                delete nodetodelete;
            }
            else {
                temp = temp->next;
            }
        }
        curr = curr->next;
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
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print linked list
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

  
    insertEnd(head, 4);
    insertEnd(head, 2);
    insertEnd(head, 5);
    insertEnd(head, 2);
    insertEnd(head, 4);
    insertEnd(head, 3);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
