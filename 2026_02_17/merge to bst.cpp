#include <iostream>
#include <vector>
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

 
Node* insert(Node* root, int key) {
    if(root == NULL)
        return new Node(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

class Solution {
  public:
  
      // Inorder traversal function
    void inorder(Node* root, vector<int> &arr) {
        if(root == NULL) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
  
    vector<int> merge(Node *root1, Node *root2) {
        
        vector<int> bst1, bst2;
        
        // Step 1: Store inorder of both BSTs
        inorder(root1, bst1);
        inorder(root2, bst2);
        
        // Step 2: Merge two sorted arrays
        vector<int> result;
        int i = 0, j = 0;
        
        while(i < bst1.size() && j < bst2.size()) {
            if(bst1[i] < bst2[j]) {
                result.push_back(bst1[i]);
                i++;
            } else {
                result.push_back(bst2[j]);
                j++;
            }
        }
        
        // Remaining elements
        while(i < bst1.size()) {
            result.push_back(bst1[i]);
            i++;
        }
        
        while(j < bst2.size()) {
            result.push_back(bst2[j]);
            j++;
        }
        
        return result;
    }
};

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;

    
    root1 = insert(root1, 3);
    root1 = insert(root1, 1);
    root1 = insert(root1, 5);
 
    root2 = insert(root2, 4);
    root2 = insert(root2, 2);
    root2 = insert(root2, 6);

    Solution obj;
    vector<int> merged = obj.merge(root1, root2);

    cout << "Merged BST elements: ";
    for(int val : merged)
        cout << val << " ";

    return 0;
}
