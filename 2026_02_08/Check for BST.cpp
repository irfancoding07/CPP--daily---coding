#include <iostream>
#include <climits>
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

class Solution {
  public:
    bool validbst(Node* root, int min, int max) {

        if (root == NULL)
            return true;

        if (root->data > min && root->data < max) {

            bool left  = validbst(root->left, min, root->data);
            bool right = validbst(root->right, root->data, max);

            return left && right;
        }
        else {
            return false;
        }
    }

    bool isBST(Node* root) {
        return validbst(root, INT_MIN, INT_MAX);
    }
};

int main() {
   

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    Solution obj;

    if (obj.isBST(root))
        cout << "Tree is a BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;

    return 0;
}
