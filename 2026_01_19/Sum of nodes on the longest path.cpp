#include<iostream>
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
    void solve(Node* root, int len, int sum, int &maxlen, int &maxsum) {
        if (root == NULL) {
            if (len > maxlen) {
                maxlen = len;
                maxsum = sum;
            }
            else if (len == maxlen) {
                maxsum = max(sum, maxsum);
            }
            return;
        }

        sum += root->data;

        solve(root->left,  len + 1, sum, maxlen, maxsum);
        solve(root->right, len + 1, sum, maxlen, maxsum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int sum = 0;
        int maxlen = 0;
        int maxsum = INT_MIN;

        solve(root, len, sum, maxlen, maxsum);
        return maxsum;
    }
};

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    Solution obj;
    cout << obj.sumOfLongRootToLeafPath(root);

    return 0;
}
