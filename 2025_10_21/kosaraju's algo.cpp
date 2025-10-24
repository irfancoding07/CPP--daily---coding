#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;

//  Normal DFS for Topological Sorting
void dfs(int node, unordered_map<int, list<int>> &adj, stack<int> &st,
         unordered_map<int, bool> &vis) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, adj, st, vis);
        }
    }
    st.push(node);
}

//   Reverse DFS on Transposed Graph
void ReverseDfs(int node, unordered_map<int, list<int>> &transpose,
                unordered_map<int, bool> &vis) {
    vis[node] = true;
    for (auto nbr : transpose[node]) {
        if (!vis[nbr]) {
            ReverseDfs(nbr, transpose, vis);
        }
    }
}

 
int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    //   Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    //  Topological Sort (DFS order)
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, adj, st, vis);
        }
    }

    //   Create Transpose Graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    //   Second DFS pass using Topological Order
    for (int i = 0; i < v; i++) {
        vis[i] = false;
    }

    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!vis[top]) {
            count++;
            ReverseDfs(top, transpose, vis);
        }
    }

    return count;
}

 
int main() {
    int v = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    cout << "Number of Strongly Connected Components: "
         << stronglyConnectedComponents(v, edges) << endl;

    return 0;
}
