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

// Function to find maximum node (rightmost) in a subtree
Node* findMax(Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to find inorder predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != NULL) {
        // Case 1: Predecessor is max in left subtree
        return findMax(target->left);
    }

    // Case 2: No left child → go to ancestor
    Node* predecessor = NULL;
    Node* curr = root;
    while (curr != NULL) {
        if (target->data > curr->data) {
            predecessor = curr;   // possible predecessor
            curr = curr->right;
        } else if (target->data < curr->data) {
            curr = curr->left;
        } else {
            break;
        }
    }
    return predecessor;
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
    Node* pred = inorderPredecessor(root, target);

    if (pred != NULL)
        cout << "Inorder predecessor of " << target->data << " is " << pred->data << endl;
    else
        cout << "No inorder predecessor exists\n";

    return 0;
}
