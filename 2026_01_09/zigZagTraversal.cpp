#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

vector<int> zigZagTraversal(Node* root) {
    vector<int> result;
    if(root == NULL){
        return result;
    }
         
    queue<Node*> q;
    q.push(root);
         
    bool LeftToRight = true;
         
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
             
        for(int i = 0; i < size; i++){
            Node* frontnode = q.front();
            q.pop();
                 
            int index = LeftToRight ? i : size - i - 1;
            ans[index] = frontnode->data;
                 
            if(frontnode->left)
                q.push(frontnode->left);
                 
            if(frontnode->right)
                q.push(frontnode->right);
        }
             
        LeftToRight = !LeftToRight;
               
        for(auto i : ans)
            result.push_back(i);
    }
    return result;
}

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = zigZagTraversal(root);

    cout << "ZigZag Traversal: ";
    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}
