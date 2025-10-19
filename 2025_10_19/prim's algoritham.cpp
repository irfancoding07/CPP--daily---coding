#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include<limits.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Step 1: Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Step 2: Initialize key, mst, parent arrays
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Step 3: Start from node 1 (arbitrary)
    key[1] = 0;
    parent[1] = -1;

    // Step 4: Run Prim's Algorithm
    for (int count = 1; count < n; count++) {
        int mini = INT_MAX;
        int u = -1;

        // Find node with minimum key value not yet in MST
        for (int v = 1; v <= n; v++) {
            if (mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Mark this node as part of MST
        mst[u] = true;

        // Update adjacent vertices
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;  
            }
        }
    }

    // Step 5: Prepare result vector
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

 
int main() {
    int n = 5, m = 6;
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 2},
        {{1, 3}, 3},
        {{1, 4}, 6},
        {{2, 3}, 8},
        {{2, 5}, 5},
        {{4, 5}, 9}
    };

    auto ans = calculatePrimsMST(n, m, edges);

    cout << "Edges in MST:\n";
    for (auto it : ans) {
        cout << it.first.first << " - " << it.first.second << "  (Weight: " << it.second << ") " << endl;
    }
}prims
