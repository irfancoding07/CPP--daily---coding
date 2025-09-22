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
       this -> right = NULL;
   }
};

node* buildtree(node* root){
      
      cout << "entre the data" << endl;
      int data;
      cin >> data;
      root = new node(data);
      
      if(data == -1){
          return NULL;
      }
    cout << "entre data for inserting in left" <<data << endl;
    root -> left = buildtree(root->left);
    cout << "entre data for inserting in right" <<data << endl;
    root -> right = buildtree(root->right);
    return root;
}
int main() {
     
    node* root = NULL;
    
    root = buildtree(root);
    return 0;
}
