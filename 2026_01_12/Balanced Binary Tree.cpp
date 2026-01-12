#include <bits/stdc++.h>

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

class Solution {
public:
    pair<bool,int> balanced(Node* root){
        // base case
        if(root == NULL){
            return make_pair(true, 0);
        }
        
        pair<bool,int> left = balanced(root->left);
        pair<bool,int> right = balanced(root->right);
        
        bool leftans = left.first;
        bool rightans = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftans && rightans && diff){
            ans.first = true;
        } else {
            ans.first = false;
        }
        
        return ans;
    }
    
    bool isBalanced(Node* root) {
        return balanced(root).first;
    }
};

int main() {
  
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;

    if (sol.isBalanced(root))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is NOT Balanced" << endl;

    return 0;
}
