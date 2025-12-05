#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    bool isPalindrome(Node *head) {
        Node* temp = head;
        stack<int> s;

        // Push elements to stack
        while (temp != NULL) {
            s.push(temp->data);
            temp = temp->next;
        }

        // Compare while popping
        while (head != NULL) {
            int c = s.top();
            s.pop();

            if (head->data != c) {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    Solution obj;

    if (obj.isPalindrome(head)) {
        cout << "Linked List is a Palindrome\n";
    } else {
        cout << "Linked List is NOT a Palindrome\n";
    }

    return 0;
}
