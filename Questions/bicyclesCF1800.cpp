#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define ll long long

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> sf(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sf[i];
    }

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    vector<ll> time(n + 1, LLONG_MAX);
    time[1] = 0;
    pq.push({0, 1, sf[1]}); // {current_time, node, min_speed_factor}
    ll minii = sf[1];
    while (!pq.empty()) {
        auto topp = pq.top();
        pq.pop();

        ll currTime = topp[0];
        ll topNode = topp[1];
        ll minBike = topp[2];
        minii = min(minii, minBike);
        minii = min(minii, sf[topNode]);
        if (currTime > time[topNode] && sf[topNode] <= minBike) continue;

        for (auto neighbour : adj[topNode]) {
            ll node = neighbour.first;
            ll dist = neighbour.second;

            ll newPossibleTime = currTime + min(sf[topNode], minBike) * dist;
            if (newPossibleTime < time[node]) {
                time[node] = newPossibleTime;
                pq.push({newPossibleTime, node, min(sf[topNode], minBike)});
                sf[node] = min(sf[topNode], sf[node]);
                sf[node] = min(sf[node], minBike);
            }
            if(minBike < sf[node]) {
                pq.push({currTime + minBike * dist, node, minBike});
            }
        }
    }

    cout<<time[n]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
