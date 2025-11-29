#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

 class Solution {
  public:
     Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addOne(Node* head) {
      head = reverse(head);
        
        int carry = 1;
        Node* temp = head;
        Node* tail = NULL;

        while (temp != NULL && carry == 1) {
            if (temp->data == 9) {
                temp->data = 0;
            } else {
                temp->data = temp->data + 1;
                carry = 0;
            }
            
            tail = temp;
            temp = temp->next;
        }

        // If carry remains  
        if (carry == 1) {
            tail->next = new Node(1);
        }

        head = reverse(head);
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
    
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.addOne(head);

    cout << "After adding 1: ";
    printList(head);

    return 0;
}
