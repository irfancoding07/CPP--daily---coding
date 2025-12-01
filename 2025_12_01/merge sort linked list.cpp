#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

 
Node* getMiddle(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Merge Sort for Linked List
Node* mergeSort(Node* head) {
    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    // 1. Find middle
    Node* middle = getMiddle(head);
    Node* rightHead = middle->next;
    middle->next = NULL; // break the list

    // 2. Recursively sort two halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    // 3. Merge sorted halves
    return merge(left, right);
}

 
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
