#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

struct State {
    int node;
    long long cost;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

long long findShortestTime(int n, vector<vector<Edge>>& graph, vector<int>& slowness) {
    // Priority queue for Dijkstra's algorithm
    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    
    // Initialize distances using bikes from each city
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        pq.push({i, 0});
    }
    
    // Modified Dijkstra's to calculate minimum time
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        int u = current.node;
        long long current_cost = current.cost;

        if (current_cost > dist[u][u]) continue;

        for (auto& edge : graph[u]) {
            for (int bike_city = 1; bike_city <= n; bike_city++) {
                long long new_cost = current_cost + edge.weight * slowness[bike_city - 1];
                if (new_cost < dist[edge.to][bike_city]) {
                    dist[edge.to][bike_city] = new_cost;
                    pq.push({edge.to, new_cost});
                }
            }
        }
    }

    // Calculate the minimum time to reach city n from city 1
    long long result = INF;
    for (int bike_city = 1; bike_city <= n; bike_city++) {
        result = min(result, dist[n][bike_city]);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<Edge>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> slowness(n);
        for (int i = 0; i < n; i++) {
            cin >> slowness[i];
        }

        cout << findShortestTime(n, graph, slowness) << endl;
    }
    return 0;
}
