#include<iostream>
#include<vector>

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
    int findPosition(vector<int>& inorder, int element, int n) {
        for(int i = 0; i < n; i++) {
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }

    Node* solve(vector<int>& inorder, vector<int>& preorder,
                int &index, int instart, int inend, int n) {

        if(index >= n || instart > inend)
            return NULL;

        int element = preorder[index++];
        Node* root = new Node(element);

        int position = findPosition(inorder, element, n);

        root->left = solve(inorder, preorder, index,
                           instart, position - 1, n);

        root->right = solve(inorder, preorder, index,
                            position + 1, inend, n);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int n = inorder.size();
        int preorderIndex = 0;
        return solve(inorder, preorder, preorderIndex, 0, n - 1, n);
    }
};

 
void printInorder(Node* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder   = {4, 2, 5, 1, 6, 3};
    vector<int> preorder  = {1, 2, 4, 5, 3, 6};

    Solution obj;
    Node* root = obj.buildTree(inorder, preorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);

    return 0;
}
