  #include <iostream>
#include <queue>
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

node* LevelOrderTraversal(node* root){
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
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
int main() {
     
    node* root = NULL;
    
    root = buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "printing the level order traversal output " << endl;
    LevelOrderTraversal(root);
    
    return 0;
}
