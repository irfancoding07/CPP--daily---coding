#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int minVal(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        if (root->val == key) {

            // 0 child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // 1 child (right)
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 1 child (left)
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 2 children
            int mini = minVal(root->right);
            root->val = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

 
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
   
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    Solution obj;
    root = obj.deleteNode(root, 3);  
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
