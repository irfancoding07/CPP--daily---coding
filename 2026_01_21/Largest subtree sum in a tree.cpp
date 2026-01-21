#include<iostream>

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
    int maxSum;

    int solve(Node* root) {
        // Base case
        if (root == NULL)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int currSum = root->data + left + right;

        maxSum = max(maxSum, currSum);

        return currSum;
    }

    int findLargestSubtreeSum(Node* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    cout << "Largest Subtree Sum: "
         << obj.findLargestSubtreeSum(root);

    return 0;
}
