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

 
class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        // Base case
        if (root == NULL)
            return NULL;

        // If current node matches n1 or n2
        if (root->data == n1 || root->data == n2)
            return root;

        // Recur for left and right subtrees
        Node* leftans = lca(root->left, n1, n2);
        Node* rightans = lca(root->right, n1, n2);

        // If both sides return non-NULL, current node is LCA
        if (leftans != NULL && rightans != NULL)
            return root;

        // Otherwise return non-NULL child
        if (leftans != NULL)
            return leftans;
        else
            return rightans;
    }
};

int main() {
    

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;

    int n1 = 4, n2 = 5;
    Node* ans = obj.lca(root, n1, n2);

    if (ans != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
