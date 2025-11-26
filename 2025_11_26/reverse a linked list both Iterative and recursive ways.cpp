#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* reverse(Node* head) {
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverse(head->next);

    head->next->next = head;   // reverse the link
    head->next = NULL;         // break old link

    return newHead;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
   
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    // Reverse the list using recursion
    head = reverse(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}


/*
//iterative way
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Iterative function to reverse linked list
Node* reverseIterative(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;   // Save next node
        curr->next = prev;      // Reverse the link
        prev = curr;            // Move prev one step
        curr = forward;         // Move curr one step
    }

    return prev;  
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    // Reverse the list (iterative)
    head = reverseIterative(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
*/
