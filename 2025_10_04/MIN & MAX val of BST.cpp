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


Node* LevelOrderTraversal(Node* root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp ==  NULL){
            //purana level complete ho chuka hai
            cout << endl;
            
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp->right);
            }
        }
    }
    return root;
}

Node* minval(Node* root){
    Node* temp = root;
    
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxval(Node* root){
    Node* temp = root;
    
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
 
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
 
int main() {
     
  Node* root = NULL;
  
    //10 8 21 7 27 5 4 3 -1
    cout <<"Enter data to create BST   " << endl ;
    takeInput(root);
    
    cout << "printing the BST" << endl;
    LevelOrderTraversal(root);
    
    cout << "min value is " << minval(root)->data << endl;
    cout << "max value is " << maxval(root )->data << endl;
    return 0;
}
