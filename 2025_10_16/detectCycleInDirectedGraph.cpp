#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool checkCycleDFS(int node, vector<bool> &visited, vector<bool> &dfsvisited, vector<list<int>> &adj) {
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (checkCycleDFS(neighbour, visited, dfsvisited, adj))
                return true;
        }
        else if (dfsvisited[neighbour]) {
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) {
    vector<list<int>> adj(n);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v); // directed edge
    }

    vector<bool> visited(n, false);
    vector<bool> dfsvisited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (checkCycleDFS(i, visited, dfsvisited, adj))
                return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int,int>> edges(m);
    cout << "Enter edges (u v) 0-indexed " << endl; ;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (detectCycleInDirectedGraph(n, edges))
        cout << "Graph has a cycle" << endl;
    else
        cout << "Graph has no cycle" << endl;

    return 0;
}
