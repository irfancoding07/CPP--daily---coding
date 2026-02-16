#include <iostream>
#include <vector>
#include <climits>
using namespace std;

        
struct TreeNode {
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
    int i = 0;

    TreeNode* build(vector<int>& preorder, int minVal, int maxVal) {
        if (i >= preorder.size())
            return NULL;

        int val = preorder[i];

        // If value is not in valid range, return NULL
        if (val < minVal || val > maxVal)
            return NULL;

        // Create node
        TreeNode* root = new TreeNode(val);
        i++;

        // Build left subtree
        root->left = build(preorder, minVal, val);

        // Build right subtree
        root->right = build(preorder, val, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }
};
 
void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution obj;
    TreeNode* root = obj.bstFromPreorder(preorder);

    cout << "Inorder Traversal of Constructed BST: ";
    inorder(root);

    return 0;
}
