#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
 
vector<int> diagonal(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        while (temp != NULL) {
            ans.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);

            temp = temp->right;
        }
    }
    return ans;
}
 
int main() {
    

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->right->right = new Node(14);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right->left = new Node(13);

    vector<int> result = diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
