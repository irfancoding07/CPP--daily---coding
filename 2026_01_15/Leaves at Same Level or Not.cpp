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
  bool checkUtil(Node* root, int level, int &leafLevel) {
        if (root == NULL)
            return true;

        // If this is a leaf node
        if (root->left == NULL && root->right == NULL) {
            // First leaf node found
            if (leafLevel == -1) {
                leafLevel = level;
                return true;
            }
            // Check level with previous leaf
            return level == leafLevel;
        }

        return checkUtil(root->left, level + 1, leafLevel) &&
               checkUtil(root->right, level + 1, leafLevel);
    }

    bool check(Node* root) {
        int leafLevel = -1;
        return checkUtil(root, 0, leafLevel);
    }
};
int main() {

 Node*  root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    Solution obj;

    if (obj.check(root))
        cout << "All leaf nodes are at the same level" << endl;
    else
        cout << "Leaf nodes are NOT at the same level" << endl;

    return 0;
}
