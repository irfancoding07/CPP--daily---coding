#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

 
void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis,
         vector<int> &ap) {

    vis[node] = true;
    disc[node] = low[node] = timer++;
    int childCount = 0;  

    for (auto nbr : adj[node]) {
        if (nbr == parent) 
             continue;  
        
        if (!vis[nbr]) {
            dfs(nbr, node, timer, disc, low, adj, vis, ap);
            low[node] = min(low[node], low[nbr]);

            // Check articulation condition:
             if (parent != -1 && low[nbr] >= disc[node])
                ap[node] = true;

            childCount++;
        } else {
            // Back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // (2) Root node with 2 or more children
    if (parent == -1 && childCount > 1)
        ap[node] = 1;
}

 
void findArticulationPoints(int V, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adj;
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first); // undirected graph
    }

    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(V, 0); // articulation points marker
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i])
            dfs(i, -1, timer, disc, low, adj, vis, ap);
    }

    cout << "Articulation Points are: ";
    bool found = false;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) cout << "None";
    cout << endl;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {0, 3}, {3, 4}
    };

    findArticulationPoints(V, edges);
    return 0;
}
