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

class Solution {
public:
    int cycleStart(Node* head) {
        Node* slow = head;
        Node* fast = head;

        //   Detect loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Find start of loop
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow->data;  // start of loop node
            }
        }

        return -1; // No loop
    }
};

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    
    head->next->next->next->next->next = head->next->next;

    Solution obj;

    int start = obj.cycleStart(head);

    if (start != -1)
        cout << "Loop starts at node with value: " << start << endl;
    else
        cout << "No loop detected!" << endl;

    return 0;
}
