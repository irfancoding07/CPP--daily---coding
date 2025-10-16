#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

 
void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour])
            topoSort(neighbour, visited, s, adj);
    }

    // Push node after visiting all neighbors
    s.push(node);
}

 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];   
        adj[u].push_back(v);
    }

   
    vector<bool> visited(v, false);
    stack<int> s;

    // Call topoSort DFS for all nodes
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            topoSort(i, visited, s, adj);
    }

    // Collect nodes from stack to form topological order
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Main function to test topological sort
int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> topoOrder = topologicalSort(edges, v, e);
    cout << "Topological Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
