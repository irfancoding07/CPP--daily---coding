#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* deleteNode(Node* head, int key) {

        if (head == NULL) 
            return head;

        Node* curr = head;
        Node* prev = NULL;

        // If key is at head
        if (head->data == key) {
            head = head->next;
            delete curr;
            return head;
        }

        // Search for key
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        // Key not found
        if (curr == NULL)
            return head;

        // Delete the node
        prev->next = curr->next;
        delete curr;

        return head;
    }
};

 
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
 
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Solution obj;

    cout << "Original List: ";
    printList(head);

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    head = obj.deleteNode(head, key);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
