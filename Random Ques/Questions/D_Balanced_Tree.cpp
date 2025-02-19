#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> range(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> range[i].first >> range[i].second;
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<vector<int>> children(n + 1);

    function<void(int, int)> dfs = [&](int node, int prev) {
        parent[node] = prev;
        for (int child : graph[node]) {
            if (child != prev) {
                children[node].push_back(child);
                dfs(child, node);
            }
        }
    };
    dfs(1, 0);

    function<int(int)> find_min_value = [&](int root) {
        int min_val = range[root].first;
        for (int child : children[root]) {
            min_val = max(min_val, find_min_value(child));
        }
        return min_val;
    };

    int ans = find_min_value(1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
