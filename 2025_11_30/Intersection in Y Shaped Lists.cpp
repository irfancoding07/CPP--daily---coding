#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

 
Node* intersectPoint(Node* head1, Node* head2) {

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    if (ptr1 == NULL || ptr2 == NULL)
        return NULL;

    while (ptr1 != ptr2) {

        // If ptr1 reaches end, jump to head2
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;

        // If ptr2 reaches end, jump to head1
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }

    // Either intersection node OR NULL
    return ptr1;
}

// Print linked list
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

    
    Node* head2 = new Node(4);

    
    Node* common = new Node(7);
    common->next = new Node(8);
    common->next->next = new Node(10);

    
    head1->next->next->next = common;    
    head2->next = common;                

    // Print both lists
    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    // Find intersection
    Node* ans = intersectPoint(head1, head2);

    if (ans != NULL)
        cout << "Intersection at node with value: " << ans->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
