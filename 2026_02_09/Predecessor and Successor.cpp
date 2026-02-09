#include <iostream>
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

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;

        while (curr != NULL) {
            if (curr->data == key) {

                // predecessor = max in left subtree
                if (curr->left != NULL) {
                    Node* temp = curr->left;
                    while (temp->right != NULL)
                        temp = temp->right;
                    pre = temp;
                }

                // successor = min in right subtree
                if (curr->right != NULL) {
                    Node* temp = curr->right;
                    while (temp->left != NULL)
                        temp = temp->left;
                    suc = temp;
                }
                break;
            }
            else if (key < curr->data) {
                suc = curr;        // possible successor
                curr = curr->left;
            }
            else {
                pre = curr;        // possible predecessor
                curr = curr->right;
            }
        }

        return {pre, suc};
    }
};

int main() {
  
    Node* root = new Node(8);
    root->left = new Node(1);
    root->right = new Node(9);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(10);

    int key = 8;

    Solution obj;
    vector<Node*> ans = obj.findPreSuc(root, key);

    if (ans[0] != NULL)
        cout << "Predecessor: " << ans[0]->data << endl;
    else
        cout << "Predecessor: NULL" << endl;

    if (ans[1] != NULL)
        cout << "Successor: " << ans[1]->data << endl;
    else
        cout << "Successor: NULL" << endl;

    return 0;
}
