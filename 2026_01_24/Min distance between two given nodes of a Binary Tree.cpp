#include <bits/stdc++.h>
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
       if(root == NULL){
           return NULL;
       }
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       Node* leftans = lca(root->left,n1,n2);
       Node* rightans = lca(root->right,n1,n2);
       
       
       if(leftans != NULL && rightans != NULL){
           return root;
       }
       else if(leftans != NULL && rightans == NULL){
           return leftans;
       }
       else if(leftans == NULL && rightans != NULL){
           return rightans;
       }
       else 
           return NULL;
       
    }
    // Function to find distance from root to node k
    int findDistance(Node* root, int k, int dist) {
        if (root == NULL)
            return -1;

        if (root->data == k)
            return dist;

        int left = findDistance(root->left, k, dist + 1);
        if (left != -1)
            return left;

        return findDistance(root->right, k, dist + 1);
    }

    
    int findDist(Node* root, int a, int b) {
        Node* LCA = lca(root, a, b);

        int d1 = findDistance(LCA, a, 0);
        int d2 = findDistance(LCA, b, 0);

        return d1 + d2;
    }
};

int main() {
   
    Node* root = new Node(11);
    root->left = new Node(22);
    root->right = new Node(33);

    root->left->left = new Node(44);
    root->left->right = new Node(55);

    root->right->left = new Node(66);
    root->right->right = new Node(77);

    Solution obj;

    int a = 77, b = 22;
    cout << obj.findDist(root, a, b);

    return 0;
}
