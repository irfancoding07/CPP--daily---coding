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
  bool isCircular(Node *head) {
      // If the list is empty, consider it circular 
        if (!head) {
            return true;
        }

        Node *slow = head;
        Node *fast = head->next;

      
        while (fast && fast->next) {

            
            if (slow == fast) {
                return true;
            }

            slow = slow->next;           
            fast = fast->next->next;     
        }

        // If fast reaches NULL, no loop exists
        return false;
    }
};
int main() {
    Solution obj;

    
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = NULL;

    cout << "List 1 is circular?  ";
    cout << (obj.isCircular(head1) ? "YES" : "NO") << endl;


    
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    // Make it circular: last node → head
    head2->next->next->next = head2;

    cout << "List 2 is circular?  ";
    cout << (obj.isCircular(head2) ? "YES" : "NO") << endl;

    return 0;
}
