  #include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

void LevelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

Node* minval(Node* root) {
    Node* temp = root;
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node* maxval(Node* root) {
    Node* temp = root;
    while (temp && temp->right != NULL)
        temp = temp->right;
    return temp;
}

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) return new Node(d);

    if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    else
        root->left = insertIntoBST(root->left, d);

    return root;
}

Node* deleteFromBST(Node* root, int value) {
    if (root == NULL) return root;

    if (root->data == value) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        
        // left child 
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        //right child 
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

       // 2 child
       if(root->left!= NULL && root->right != NULL){
           int mini = minval(root->right) -> data; 
           root->data = mini;
           root->right = deleteFromBST(root->right, mini); 
           return root; 
       }
       }

    else if (value < root->data)
        root->left = deleteFromBST(root->left, value);
    else
        root->right = deleteFromBST(root->right, value);

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST: ";
    // example input: 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << "Printing BST:" << endl;
    LevelOrderTraversal(root);

    cout << "Min value: " << minval(root)->data << endl;
    cout << "Max value: " << maxval(root)->data << endl;

    // deletion
    root = deleteFromBST(root, 27);

    cout << "\nBST after deletion of 27:" << endl;
    LevelOrderTraversal(root);

    cout << "Min value: " << minval(root)->data << endl;
    cout << "Max value: " << maxval(root)->data << endl;

    return 0;
}
