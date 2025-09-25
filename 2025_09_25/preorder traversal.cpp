  #include <bits/stdc++.h>
using namespace std;

// Binary tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Iterative Preorder Traversal using vector
vector<int> preorderTraversal(Node* root) {
    vector<int> result;
    if(root == NULL) return result;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node* curr = st.top();
        st.pop();

        result.push_back(curr->data);  // store in vector

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
    return result;
}

int main() {
    /* Example Tree:
              1
             / \
            2   3
           / \
          4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> preorder = preorderTraversal(root);

    cout << "Preorder using vector: ";
    for(int val : preorder) cout << val << " ";
    cout << endl;
    return 0
