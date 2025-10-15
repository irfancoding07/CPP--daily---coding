#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

 
bool isCyclicDFS(int node, int parent, unordered_map<int,bool> &visited,
                 unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (isCyclicDFS(neighbour, node, visited, adj)) {
                return true;  
            }
        } else if (neighbour != parent) {
             
            return true;
        }
    }
    return false;
}

// Main function to handle disconnected components
string cycleDetectionDFS(vector<vector<int>> &edges, int n) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;

    // Check all nodes (for disconnected graphs)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, -1, visited, adj)) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    vector<vector<int>> edges = { {0,1}, {1,2}, {2,0}, {3,4} };    
    int n = 5; // nodes 0,1,2,3,4

    cout << "Is the graph cyclic? " << cycleDetectionDFS(edges, n) << endl;
    return 0;
}
