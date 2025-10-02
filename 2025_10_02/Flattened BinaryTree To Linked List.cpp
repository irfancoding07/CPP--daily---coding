  #include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* prevNode = NULL;

void flatten(Node* root) {
    if (root == NULL) return;

    // Process right first, then left (reverse preorder)
    flatten(root->right);
    flatten(root->left);

    // Link current node to previously processed node
    root->right = prevNode;
    root->left = NULL;

    // Move prevNode
    prevNode = root;
}

void printList(Node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Create tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);

    cout << "Flattened Linked List: ";
    printList(root);

    return 0;
}
