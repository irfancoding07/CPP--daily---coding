#include <iostream>
#include <vector>

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
  
  void TraversalLeft(Node* root, vector<int> &ans){
      // base case
      if((root == NULL) || (root->left == NULL && root->right == NULL)){
          return;
      }
      
      ans.push_back(root->data);
      
      if(root->left)
          TraversalLeft(root->left, ans);
      else
          TraversalLeft(root->right, ans);
  }
  
  void TraversalLeaf(Node* root, vector<int> &ans) {
      if(root == NULL)
          return;
          
      if(root->left == NULL && root->right == NULL){
          ans.push_back(root->data);
          return;
      }
      
      TraversalLeaf(root->left, ans);
      TraversalLeaf(root->right, ans);
  }
  
  void Traversalright(Node* root, vector<int> &ans){
      if((root == NULL) || (root->left == NULL && root->right == NULL)){
          return;
      }
      
      if(root->right)
          Traversalright(root->right, ans);
      else
          Traversalright(root->left, ans);
          
      
      ans.push_back(root->data);
  }
    
  vector<int> boundaryTraversal(Node *root) {
      vector<int> ans;
      
      if(root == NULL)
          return ans;
          
      ans.push_back(root->data);
      
      TraversalLeft(root->left, ans);
      
      TraversalLeaf(root->left, ans);
      TraversalLeaf(root->right, ans);
      
      Traversalright(root->right, ans);
      
      return ans;
  }
};

int main() {
    

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}
