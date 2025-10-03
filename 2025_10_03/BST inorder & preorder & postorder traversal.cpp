  #include <iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
 
 Node* insertIntoBST(Node* root, int d){
     //base case
     if(root == NULL){
         root = new Node(d);
         return root;
     }
     
     if(d > root->data){
         //right part me insert krna hai
         root->right = insertIntoBST(root->right,d);
     }
     
      else {
         //left part me insert krna hai
         root->left = insertIntoBST(root->left,d);
     }
     return root;
 }
 
  void takeInput(Node* &root){
      int data;
      cin >> data;
      
     while (data != -1){
         root = insertIntoBST(root,data);
         cin >> data;
     }
  }
 
    void inorder(Node* root){
     // base case
     if(root == NULL){
         return ;
     }
     inorder(root->left);
     cout << root -> data << " ";
     inorder(root->right);
 }
 
 void preorder(Node* root){
     // base case
     if(root == NULL){
         return ;
     }
     cout << root -> data << " ";
     inorder(root->left);
     inorder(root->right);
 }
 
 void postorder(Node* root){
     // base case
     if(root == NULL){
         return ;
     }
      
     inorder(root->left);
     inorder(root->right);
     cout << root -> data << " ";
 }
  
 

int main() {
     
  Node* root = NULL;
  
    //10 8 21 7 27 5 4 3 -1
    cout <<"Enter data to create BST   " << endl ;
    takeInput(root);
    
     cout << "inorder traversal is" << endl  ;
    inorder(root);
    cout << endl;
    
     cout << "preorder traversal is " << endl  ;
    preorder(root);
    cout << endl;
    
     cout << "postorder traversal is " << endl;
    postorder(root);
    

    return 0;
}
