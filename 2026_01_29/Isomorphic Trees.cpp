#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

 
bool isIsomorphic(Node* root1, Node* root2) {

    // Case 1: both NULL
    if (root1 == NULL && root2 == NULL)
        return true;

    // Case 2: one NULL
    if (root1 == NULL || root2 == NULL)
        return false;

    // Case 3: data mismatch
    if (root1->data != root2->data)
        return false;

    // Case 4: check with swap OR without swap
    return
        (isIsomorphic(root1->left, root2->left) &&
         isIsomorphic(root1->right, root2->right))
        ||
        (isIsomorphic(root1->left, root2->right) &&
         isIsomorphic(root1->right, root2->left));
}

int main() {

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

  
    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->right = new Node(4);

    if (isIsomorphic(root1, root2))
        cout << "True (Trees are Isomorphic)" << endl;
    else
        cout << "False (Trees are NOT Isomorphic)" << endl;

    return 0;
}
