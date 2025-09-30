   #include <iostream>
using namespace std ;

class node {
    
    public:
   int data;
   node* left;
   node* right;
   
   node(int d){
       this -> data = d;
       this -> left = NULL;
       this-> right = NULL;
   }
};

node* buildtree (node* root){
    
    cout << "enter the data " << endl;
    int data;
    cin >> data;
    
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout << "enter data for inserting in left" <<data << endl;
    root->left = buildtree(root->left);
    
      cout << "enter data for inserting in right" <<data << endl;
    root->right = buildtree(root->right);
    
    return root;
}

 
 
 void postorder(node* root){
     // base case
     if(root == NULL){
         return ;
     }
      
     postorder(root->left);
     postorder(root->right);
     cout << root -> data << " ";
 }
  

int main() {
    node* root = NULL;
    
    root = buildtree(root);
    
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
     
    cout << endl;
    
     cout << "postorder traversal is : ";
    postorder(root);
    
     
    return 0;
}
