#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

 
Node* reverseDLL(Node* head) {
    if (head == NULL) 
        return NULL;

    // Swap next and prev
    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;
 
    if (head->prev == NULL)
        return head;

    return reverseDLL(head->prev);
}

 
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

 
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    cout << "Original List: ";
    printList(head);

    
    head = reverseDLL(head);

    cout << "\nReversed List: ";
    printList(head);

    return 0;
}
