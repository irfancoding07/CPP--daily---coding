#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    // Step 2: Compute in-degree of each node
    vector<int> indegree(v, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Step 3: Push all nodes with in-degree 0 into the queue
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 4: Perform BFS
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
            
        //neighbour indegree update
        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

     
    return ans;
}

// Main function to test Topological Sort (BFS)
int main() {
    int v, e;
    cout << "Enter number of vertices and edges" << endl;;
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> topoOrder = topologicalSort(edges, v, e);
    cout << "Topological Order " << endl;
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
