#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find minimum node (leftmost) in a subtree
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find inorder successor
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != NULL) {
        // Case 1: Successor is min in right subtree
        return findMin(target->right);
    }

    // Case 2: No right child → go to ancestor
    Node* successor = NULL;
    Node* curr = root;
    while (curr != NULL) {
        if (target->data < curr->data) {
            successor = curr;   // possible successor
            curr = curr->left;
        } else if (target->data > curr->data) {
            curr = curr->right;
        } else {
            break;
        }
    }
    return successor;
}

int main() {
    // Example BST
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    Node* target = root->left->right; // node = 40
    Node* succ = inorderSuccessor(root, target);

    if (succ != NULL)
        cout << "Inorder successor of " << target->data << " is " << succ->data << endl;
    else
        cout << "No inorder successor exists\n";

    return 0;
}
