#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> weights;
        vector<vector<pair<int, int>>> graph(n + 1);

        // Read edges and store weights
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            weights.push_back(w);
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Sort weights in ascending order
        sort(weights.begin(), weights.end());

        // Read queries
        vector<vector<vector<int>>> queries(n + 1); // {b, k, index}
        vector<int> results(q + 1, 1e9 + 1);        // Initialize results with a large value
        for (int i = 1; i <= q; i++) {
            int a, b, k;
            cin >> a >> b >> k;

            if (b < a) swap(a, b); // Ensure `a` <= `b`
            queries[a].push_back({b, k, i}); // Store queries for node `a`
        }

        // Process each node as a starting point
        for (int start = 1; start <= n; start++) {
            // Iterate over each weight threshold
            for (int weight : weights) {
                vector<int> dist(n + 1, 1e9);
                dist[start] = 0; // Distance to itself is 0

                deque<int> dq;
                dq.push_back(start);

                // Perform a modified BFS
                while (!dq.empty()) {
                    int current = dq.front();
                    dq.pop_front();

                    for (auto& edge : graph[current]) {
                        int neighbor = edge.first;
                        int edgeWeight = edge.second;
                        int extraCost = (edgeWeight > weight) ? 1 : 0;

                        // Update distance if a shorter path is found
                        if (dist[current] + extraCost < dist[neighbor]) {
                            dist[neighbor] = dist[current] + extraCost;
                            if (extraCost == 0) {
                                dq.push_front(neighbor); // No extra cost, process early
                            } else {
                                dq.push_back(neighbor); // Extra cost, process later
                            }
                        }
                    }
                }

                for (auto& query : queries[start]) {
                    int target = query[0];
                    int maxEdges = query[1];
                    int queryIndex = query[2];

                    if (dist[target] < maxEdges) {
                        results[queryIndex] = min(results[queryIndex], weight);
                    }
                }
            }
        }

        for (int i = 1; i <= q; i++) {
            cout << results[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
