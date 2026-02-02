#include <iostream>
#include <climits>
using namespace std;

class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

 
bool isBST(BinaryTreeNode<int>* root, int min, int max) {
    // base case
    if (root == NULL) {
        return true;
    }

    if (root->data > min && root->data < max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    } else {
        return false;
    }
}

 
bool validateBST(BinaryTreeNode<int>* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

 
int main() {
 
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(15);

    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(7);

    root->right->right = new BinaryTreeNode<int>(20);

    if (validateBST(root)) {
        cout << "Tree is a valid BST" << endl;
    } else {
        cout << "Tree is NOT a valid BST" <<
