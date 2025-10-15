#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

 
void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges) {
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);   
    }
}

 
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;

    // Visit all neighbours
    for (auto neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList, component);
        }
    }
}

int main() {
    int n = 7;  
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 6}
    };

    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    vector<vector<int>> result;  

    prepareAdjList(adjList, edges);

    // Handle disconnected graphs
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adjList, component);
            result.push_back(component);
        }
    }

     
    cout << "DFS Traversal: ";
    for (auto component : result) {
        for (auto node : component) {
            cout << node << " ";
        }
    }
    cout << endl;

    return 0;
}
