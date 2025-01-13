#include <iostream>
#include <vector>
#include <deque>
#include <climits> // For INT_MAX
using namespace std;

void zeroOneBFS(int n, vector<vector<pair<int, int>>>& graph, int source) {
    vector<int> distance(n, INT_MAX); // Distance array
    deque<int> dq;                    // Deque for 0-1 BFS

    // Initialize the source
    distance[source] = 0;
    dq.push_front(source);

    while (!dq.empty()) {
        int current = dq.front();
        dq.pop_front();

        // Process all neighbors of the current node
        for (auto& edge : graph[current]) {
            int neighbor = edge.first;
            int weight = edge.second;

            // If a shorter path is found
            if (distance[current] + weight < distance[neighbor]) {
                distance[neighbor] = distance[current] + weight;
                if (weight == 0) {
                    dq.push_front(neighbor); // Push to front for weight 0
                } else {
                    dq.push_back(neighbor); // Push to back for weight 1
                }
            }
        }
    }

    // Output the shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << distance[i] << "\n";
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n); // Adjacency list

    cout << "Enter edges (u v w), where w is 0 or 1:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graph
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    zeroOneBFS(n, graph, source);

    return 0;
}
