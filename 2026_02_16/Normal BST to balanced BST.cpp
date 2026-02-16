#include <iostream>
#include <vector>
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

// Step 1: Store inorder
void storeInorder(Node* root, vector<int>& arr) {
    if (root == NULL)
        return;

    storeInorder(root->left, arr);
    arr.push_back(root->data);
    storeInorder(root->right, arr);
}

// Step 2: Build Balanced BST from sorted array
Node* buildBalancedBST(vector<int>& arr, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node* root = new Node(arr[mid]);

    root->left = buildBalancedBST(arr, start, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, end);

    return root;
}

 
Node* balanceBST(Node* root) {
    vector<int> arr;

    // Store inorder (sorted)
    storeInorder(root, arr);

    // Build balanced BST
    return buildBalancedBST(arr, 0, arr.size() - 1);
}

 
void printInorder(Node* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

 
int main() {

    Node* root = new Node(10);
    root->right = new Node(20);
    root->right->right = new Node(30);
    root->right->right->right = new Node(40);

    cout << "Inorder of Original BST: ";
    printInorder(root);

 
    Node* balancedRoot = balanceBST(root);

    cout << "\nInorder of Balanced BST: ";
    printInorder(balancedRoot);

    return 0;
}
