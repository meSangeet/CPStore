#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int n;
    cin >> n;

    vector<int> degree(n + 1, 0);
    vector<vector<int>> adjacency(n + 1);

    // Read the edges and build the tree
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    priority_queue<pair<int,int>> pq;
    for(int i = 1; i<=n; i++){
        pq.push({degree[i], i});
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        //we remove the ith node it will create degree[i] components
        int comp = degree[i];
        // cout<<"ini - "<<comp<<" final - ";
        // pq.erase({})
        vector<int> deg(degree);  
        deg[i] = 0;
        int mx = 0;
        for(int nei : adjacency[i]){
            deg[nei]--;
        }
        for(auto x : deg){
            mx = max(x, mx);
        }
        comp += mx-1;
        // cout<<comp<<endl;
        ans = max(ans, comp);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        // cout<<"new test\n";
        solve();
    }

    return 0;
}
