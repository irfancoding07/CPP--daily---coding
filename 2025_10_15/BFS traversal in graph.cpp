 #include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;
 
 
void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges) {
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);   
    }
}

// BFS Function
void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        // Traverse all neighbors
        for (auto neighbor : adjList[frontNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

 
int main() {
    int n = 7; // number of nodes (0 to 6)
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 6}
    };

    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;

    prepareAdjList(adjList, edges);

    // Handle disconnected graphs
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    cout << "BFS Traversal: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
