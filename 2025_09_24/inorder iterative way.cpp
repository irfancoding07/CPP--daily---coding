  #include <iostream>
#include <stack>
#include <vector>
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

vector<int> inorderIterative(Node* root) {
    vector<int> result;
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()) {
        // 1. Reach the leftmost node
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // 2. Current is NULL, process top node
        curr = st.top();
        st.pop();
        result.push_back(curr->data);

        // 3. Visit right subtree
        curr = curr->right;
    }

    return result;
}

int main() {
    // Example Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = inorderIterative(root);

    cout << "Inorder Traversal: ";
    for(int x : ans) cout << x << " ";
    return 0;
}
 
