#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()

vector<vector<int>> adj;
vector<int> weights, colors;
int n, k;
vector<vector<int>> up; // for LCA
vector<int> depth;
int LOG;

// Binary lifting preprocessing for LCA
void dfs(int v, int p, int d) {
    up[v][0] = p;
    depth[v] = d;
    for(int i = 1; i <= LOG; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : adj[v]) {
        if(u != p) {
            dfs(u, v, d + 1);
        }
    }
}

// Get LCA of two vertices
int getLCA(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i = LOG; i >= 0; i--) {
        if(diff & (1 << i)) {
            a = up[a][i];
        }
    }
    if(a == b) return a;
    for(int i = LOG; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

// Check if current coloring makes vertex v cutie
bool isCutie(int v, const vector<int>& curr_colors) {
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(getLCA(i, j) == v && 
               curr_colors[i-1] == curr_colors[j-1] && 
               curr_colors[i-1] != curr_colors[v-1]) {
                return true;
            }
        }
    }
    return false;
}

// Calculate cost for current coloring
ll getCost(const vector<int>& curr_colors) {
    ll cost = 0;
    for(int i = 1; i <= n; i++) {
        if(isCutie(i, curr_colors)) {
            cost += weights[i-1];
        }
    }
    return cost;
}

void solve() {
    cin >> n >> k;
    
    adj.clear();
    adj.resize(n+1);
    weights.resize(n);
    colors.resize(n);
    
    rv(weights);
    rv(colors);
    
    // Build tree
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Initialize LCA
    LOG = ceil(log2(n));
    up.assign(n+1, vector<int>(LOG+1));
    depth.resize(n+1);
    dfs(1, 1, 0);
    
    vector<int> final_colors = colors;
    ll min_cost = INF;
    
    // Try all possible combinations for missing colors
    function<void(int)> generateColors = [&](int idx) {
        if(idx == n) {
            ll current_cost = getCost(final_colors);
            if(current_cost < min_cost) {
                min_cost = current_cost;
                colors = final_colors;
            }
            return;
        }
        
        if(final_colors[idx] != 0) {
            generateColors(idx + 1);
            return;
        }
        
        for(int c = 1; c <= k; c++) {
            final_colors[idx] = c;
            generateColors(idx + 1);
        }
    };
    
    generateColors(0);
    cout << min_cost << "\n";
    pv(colors);
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
