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

 
int minValue(Node* root) {
    if (root == NULL)
        return -1;   // BST is empty

    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int main() {
 
    Node* root = new Node(8);
    root->left = new Node(1);
    root->right = new Node(9);
    root->left->right = new Node(4);
    root->right->right = new Node(10);
    root->left->right->left = new Node(3);

    cout << "Minimum value in BST: " << minValue(root) << endl;

    return 0;
}



  
