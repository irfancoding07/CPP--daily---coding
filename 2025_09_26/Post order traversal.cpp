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

vector<int> postorderIterative(Node* root) {
    vector<int> result;
    if(root == NULL) return result;

    stack<Node*> s1, s2;
    s1.push(root);

    while(!s1.empty()) {
        Node* curr =
