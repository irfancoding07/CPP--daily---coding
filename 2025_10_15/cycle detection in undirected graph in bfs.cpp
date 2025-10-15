 #include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
    unordered_map<int, int> parent;
    visited[src] = true;
    parent[src] = -1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node]) {
            if (visited[neighbour] && neighbour != parent[node]) {
                // visited neighbor not parent → cycle detected
                return true;
            } 
            else if (!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n) {
    unordered_map<int, list<int>> adj;
    // Build adjacency list
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    // Handle disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicBFS(i, visited, adj)) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    vector<vector<int>> edges = { {0,1}, {1,2}, {2,0}, {3,4} };    
    int n = 5; // 0,1,2,3,4

    cout << "Is the graph cyclic? " << cycleDetection(edges, n) << endl;
    return 0;
}
