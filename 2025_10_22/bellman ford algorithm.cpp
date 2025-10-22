#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, int src, vector<Edge> &edges) {
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    //   Relax all edges (n - 1) times
    for (int i = 1; i <= n - 1; i++) {
        for (auto edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

 // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (auto edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle!" << endl;
    } else {
        cout << "Shortest distances from source " << src << " ";
        for (int i = 1; i <= n; i++) {
            cout << "Node " << i << " : ";
            if (dist[i] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i];
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    bellmanFord(n, m, src, edges);
    return 0;
}
