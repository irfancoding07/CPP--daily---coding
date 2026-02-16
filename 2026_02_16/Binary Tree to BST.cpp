#include <iostream>
#include <vector>
#include <algorithm>
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
void inorderStore(Node* root, vector<int>& arr) {
    if (root == NULL)
        return;

    inorderStore(root->left, arr);
    arr.push_back(root->data);
    inorderStore(root->right, arr);
}

// Step 2: Replace values using inorder
void inorderReplace(Node* root, vector<int>& arr, int &index) {
    if (root == NULL)
        return;

    inorderReplace(root->left, arr, index);
    root->data = arr[index++];
    inorderReplace(root->right, arr, index);
}
 
void binaryTreeToBST(Node* root) {
    vector<int> arr;

    // Store inorder
    inorderStore(root, arr);

    // Sort values
    sort(arr.begin(), arr.end());

    // Replace values
    int index = 0;
    inorderReplace(root, arr, index);
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
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    cout << "Inorder before conversion: ";
    printInorder(root);

   
    binaryTreeToBST(root);

    cout << "\nInorder after conversion (BST): ";
    printInorder(root);

    return 0;
}
