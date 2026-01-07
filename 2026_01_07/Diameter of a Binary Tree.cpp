 
#include <iostream>
#include <algorithm>

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
    pair<int,int> diameterfast(Node* root) {
        if (root == NULL) {
            return make_pair(0, -1); // {diameter, height in edges}
        }

        auto left = diameterfast(root->left);
        auto right = diameterfast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 2;

        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameter(Node* root) {
        return diameterfast(root).first;
    }
};

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    cout << "Diameter of tree (edges): " << obj.diameter(root) << endl;

    return 0;
}
