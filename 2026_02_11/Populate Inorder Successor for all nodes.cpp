#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;
    
    Node(int val){
        data = val;
        left = right = next = NULL;
    }
};

class Solution {
  public:
  
    void solve(Node* root, Node*& next){
        if(root == NULL)
            return;
        
        solve(root->right, next);
        
        root->next = next;
        next = root;
        
        solve(root->left, next);
    }
  
    void populateNext(Node *root) {
        Node* next = NULL;
        solve(root, next);
    }
};
 
void printSuccessor(Node* root){
    if(!root) return;
    
    printSuccessor(root->left);
    
    cout << root->data << " -> ";
    if(root->next)
        cout << root->next->data;
    else
        cout << "NULL";
    cout << endl;
    
    printSuccessor(root->right);
}

int main() {
 
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    
    Solution obj;
    obj.populateNext(root);
    
    cout << "Inorder Successors:\n";
    printSuccessor(root);
    
    return 0;
}
