#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include<limits.h>
 
using namespace std;

 

// Helper function for topological sort
void topoSort(int node, unordered_map<int, list<pair<int,int>>> &adj, 
              vector<bool> &visited, stack<int> &st) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour.first]) {
            topoSort(neighbour.first, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges, int src) {
    // Step 1: Create adjacency list (with weights)
    unordered_map<int, list<pair<int,int>>> adj;
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    // Step 2: Topological sort
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoSort(i, adj, visited, st);
        }
    }

    // Step 3: Initialize distances
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Step 4: Process nodes in topological order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {
            for (auto neighbour : adj[node]) {
                int v = neighbour.first;
                int wt = neighbour.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
    }

    return dist;
}

int main() {
    int n = 6, m = 7;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 3, 6},
        {1, 2, 2},
        {2, 4, 4},
        {2, 5, 2},
        {5, 4, 1}
    };

    int src = 0;
    vector<int> ans = shortestPathInDAG(n, m, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (ans[i] == INT_MAX)
            cout << "INF ";
        else
            cout << ans[i] << " ";
    }

    return 0;
}
