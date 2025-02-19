#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

// Basic printing BFS
void BFS(ll source, vector<vector<ll>> &graph) {
    ll n = graph.size();
    vector<ll> visited(n, 0); // 1-based indexing: n vertices
    queue<ll> q;

    visited[source] = 1; // Mark source as visited
    q.push(source);

    while (!q.empty()) {
        ll curNode = q.front();
        cout << curNode << " ";
        q.pop();

        for (ll neighbour : graph[curNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
}

//finding shortest between two nodes path using bfs
void BFS

int main() {
    ll n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1); // 1-based indexing

    cout << "Enter edges (u, v) where u and v are nodes:\n";
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Uncomment for undirected graphs
    }

    ll source;
    cout << "Enter the source vertex: ";
    cin >> source;

    BFS(source, adj);

    return 0;
}

