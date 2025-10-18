#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include<limits.h>
#include<set>
 
using namespace std;

 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Step 1: Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // undirected graph
    }

    // Step 2: Initialize distance array with infinity
    vector<int> dist(vertices, INT_MAX);

    // Step 3: Create set for (distance, node)
    set<pair<int, int>> st;

    // Step 4: Initialize source
    dist[source] = 0;
    st.insert(make_pair(0, source));

    // Step 5: Dijkstra's main loop
    while (!st.empty()) {
        // Get top (smallest distance) element
        auto top = *(st.begin());
        st.erase(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // Traverse all neighbours
        for (auto neighbour : adj[topNode]) {
            if (nodeDistance + neighbour.second < dist[neighbour.first]) {
                // Remove existing record (if any)
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end())
                    st.erase(record);

                // Update distance
                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main() {
    int vertices = 5, edges = 6;
    vector<vector<int>> vec = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 2, 3},
        {1, 2, 4},
        {1, 3, 7},
        {2, 3, 1}
    };

    int source = 0;
    vector<int> ans = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
