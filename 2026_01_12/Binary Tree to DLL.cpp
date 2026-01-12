#include <iostream>
using namespace std;

 
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* prev = NULL;
    Node* head = NULL;

    void convertToDLL(Node* root) {
        if (root == NULL)
            return;

        // Left subtree
        convertToDLL(root->left);

        // Process current node
        if (prev == NULL) {
            head = root;   // first node of DLL
        } else {
            root->left = prev;
            prev->right = root;
        }

        prev = root;

        // Right subtree
        convertToDLL(root->right);
    }

    Node* bToDLL(Node* root) {
        convertToDLL(root);
        return head;
    }
};

 
void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
  

    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);

    Solution sol;
    Node* head = sol.bToDLL(root);

    cout << "Doubly Linked List (Inorder): ";
    printDLL(head);

    return 0;
}
