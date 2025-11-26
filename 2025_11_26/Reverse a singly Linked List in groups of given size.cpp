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
    Node *reverseKGroup(Node *head, int k) {
        
        if(head == NULL){
            return NULL;
        }

        Node* next = NULL;
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 0;

        // Reverse first k nodes
        while (curr != NULL && cnt < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
 
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};

 
void insertNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

 
void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

     
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);

    int k = 3;

    cout << "Original List: ";
    printList(head);

    Solution s;
    head = s.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
