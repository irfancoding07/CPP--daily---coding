#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class graph {
public:
    unordered_map<T, list<int>> adj;

    // Function to add an edge
    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        adj[u].push_back(v);       // add edge u -> v
        if (direction == 0) {      // if undirected, also add v -> u
            adj[v].push_back(u);
        }
    }

    // Function to print adjacency list as adjacency matrix-like output
    void printAdjMatrix(int n) {
        cout << "Adjacency Matrix" << " ";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            
            // check if node i has neighbors
            if (adj.find(i) != adj.end()) {
                for (auto j : adj[i]) {  
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    graph<int> g;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // undirected graph
    }

    // Print adjacency matrix
    g.printAdjMatrix(n);

    return 0;
}
