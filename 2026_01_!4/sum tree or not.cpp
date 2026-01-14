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
    pair<bool,int> isSum(Node* root) {
        if(root == NULL){
            return {true, 0};
        }

        // Leaf node
        if(root->left == NULL && root->right == NULL){
            return {true, root->data};
        }

        pair<bool,int> leftans = isSum(root->left);
        pair<bool,int> rightans = isSum(root->right);

        bool leftsumtree = leftans.first;
        bool rightsumtree = rightans.first;

        int leftSum = leftans.second;
        int rightSum = rightans.second;

        bool condition = (root->data == leftSum + rightSum);

        pair<bool,int> ans;

        if(leftsumtree && rightsumtree && condition){
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else {
            ans.first = false;
            ans.second = 0;   
        }

        return ans;
    }

    bool isSumTree(Node* root) {
        return isSum(root).first;
    }
};

int main() {
   

    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    Solution obj;

    if(obj.isSumTree(root))
        cout << "Tree is a Sum Tree" << endl;
    else
        cout << "Tree is NOT a Sum Tree" << endl;

    return 0;
}
