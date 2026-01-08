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
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;

        // base case
        if (root == NULL) {
            return ans;
        }

        map<int, int> Topnode;
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // store first node of each horizontal distance
            if (Topnode.find(hd) == Topnode.end()) {
                Topnode[hd] = frontNode->data;
            }

            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }

            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        for (auto i : Topnode) {
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(6);
    root->right->right = new Node(5);

    Solution obj;
    vector<int> result = obj.topView(root);

    cout << "Top View of Binary Tree: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
