 #include <iostream>
using namespace std ;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void morrisInorder(Node* root) {
    Node* current = root;

    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        } else {
            Node* pred = current->left;
            while (pred->right != NULL && pred->right != current)
                pred = pred->right;

            if (pred->right == NULL) {
                pred->right = current;   // create thread
                current = current->left;
            } else {
                pred->right = NULL;      // remove thread
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}
int main() {
   Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris Inorder Traversal: ";
    morrisInorder(root);
    cout << endl;
    return 0;
}
