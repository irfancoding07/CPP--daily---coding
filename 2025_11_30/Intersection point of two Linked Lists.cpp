#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* a = head1;
        Node* b = head2;

        // Dummy node to simplify list construction
        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while (a != NULL && b != NULL) {
            if (a->data == b->data) {
                // Add this common value to intersection list
                tail->next = new Node(a->data);
                tail = tail->next;

                a = a->next;
                b = b->next;
            }
            else if (a->data < b->data) {
                a = a->next;
            }
            else {
                b = b->next;
            }
        }

        Node* ans = dummy->next;
        delete dummy;  // free dummy node
        return ans;
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

    
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);
 
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    Solution obj;
    Node* result = obj.findIntersection(head1, head2);

    cout << "Intersection Linked List: ";
    printList(result);   

    return 0;
}
