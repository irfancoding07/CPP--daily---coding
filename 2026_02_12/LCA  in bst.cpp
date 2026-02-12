#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root == NULL)
            return NULL;
            
        // both smaller → go left
        if(root->data > n1->data && root->data > n2->data)
            return LCA(root->left, n1, n2);
            
        // both greater → go right
        if(root->data < n1->data && root->data < n2->data)
            return LCA(root->right, n1, n2);
            
        // split point
        return root;
    }
};

int main() {

 

    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    Solution obj;

    Node* n1 = root->left->left;    
    Node* n2 = root->left->right;  

    Node* ans = obj.LCA(root, n1, n2);

    if(ans)
        cout << "LCA is: " << ans->data;
    else
        cout << "LCA not found";

    return 0;
}
