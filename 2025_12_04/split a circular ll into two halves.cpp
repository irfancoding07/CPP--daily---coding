#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

class Solution {
public:
    pair<Node*, Node*> splitList(Node* head) {
        Node* slow = head;
        Node* fast = head;

        if (head == nullptr)
            return {nullptr, nullptr};

        // Find middle
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Fix fast for even number of nodes
        if (fast->next->next == head)
            fast = fast->next;

        Node* head1 = head;
        Node* head2 = slow->next;

        // Make second half circular
        fast->next = head2;

        // Make first half circular
        slow->next = head1;

        return {head1, head2};
    }
};

int main() {
    
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, head};  // link last to head

    cout << "Original Circular List: ";
    printCircular(head);

    Solution s;
    auto result = s.splitList(head);

    cout << "First Half: ";
    printCircular(result.first);

    cout << "Second Half: ";
    printCircular(result.second);

    return 0;
}
