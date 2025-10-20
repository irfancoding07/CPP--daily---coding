#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis) {

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent)
            continue;

        if (!vis[nbr]) {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // check if edge is a bridge
            if (low[nbr] > disc[node]) {
                result.push_back({node, nbr});
            }
        } else {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int vertices) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int w = edges[i][1];  
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int timer = 0;
    vector<int> disc(vertices, -1);
    vector<int> low(vertices, -1);
    unordered_map<int, bool> vis;
    vector<vector<int>> result;

    for (int i = 0; i < vertices; i++) {
        if (!vis[i]) {
            dfs(i, -1, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}

int main() {
    int v = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {3, 4}
    };

    vector<vector<int>> bridges = findBridges(edges, v);

    cout << "Bridges in the graph are" << endl;
    for (auto it : bridges) {
        cout << it[0] << " -- " << it[1] << endl;
    }

    return 0;
}
