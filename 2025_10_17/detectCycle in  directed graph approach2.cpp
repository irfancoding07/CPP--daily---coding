#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

bool detectCycleKahn(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adj;
    vector<int> indegree(n, 0);

    // Build adjacency list and indegree array
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0; // to count visited nodes

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        // Decrease indegree of neighbours
        for (auto neighbour : adj[node]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    // If count < n => cycle exists
    if (count == n)
        return false; // No cycle
    else
        return true;  // Cycle exists
}

int main() {
    int n = 4;  
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}  
    };

    if (detectCycleKahn(n, edges))
        cout << "Cycle detected in the graph " << endl;
    else
        cout << "No cycle detected" << endl;;

    return 0;
}
