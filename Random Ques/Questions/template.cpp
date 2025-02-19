#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

vector<ll> weights;

struct tree {

    public:
    ll root;
    ll noOfNodes;
    vector<vector<ll>> adj;
    vector<ll> mat;
    vector<ll> subtreeSum;
    vector<ll> noOfNodesInSubtree;
    vector<ll> dfsInTime;
    vector<ll> dfsOutTime;
    vector<ll> depth;
    vector<ll> parent;
    vector<ll> eulerTour;
    vector<ll> segmentTree;

    // Initialize the tree via an edge list (n nodes)
    void init_via_edge_vector(ll n, vector<pair<ll,ll>> &vec){
        noOfNodes = n;
        adj.assign(n, vector<ll>());
        for(auto& edge : vec){
            ll u = edge.first;
            ll v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        subtreeSum.assign(n, 0);
        noOfNodesInSubtree.assign(n, 0);
        dfsInTime.assign(n, -1);
        dfsOutTime.assign(n, -1);
        depth.assign(n, -1);
        parent.assign(n, -1);
        eulerTour.clear();
        segmentTree.assign(4 * n, 0);
    }

    // Initialize the tree via adjacency list
    void init_via_adj_list(vector<vector<ll>> &adjList){
        noOfNodes = adjList.size();
        adj = adjList;
        subtreeSum.assign(noOfNodes, 0);
        noOfNodesInSubtree.assign(noOfNodes, 0);
        dfsInTime.assign(noOfNodes, -1);
        dfsOutTime.assign(noOfNodes, -1);
        depth.assign(noOfNodes, -1);
        parent.assign(noOfNodes, -1);
        eulerTour.clear();
        segmentTree.assign(4 * noOfNodes, 0);
    }

    // Initialize the tree via adjacency matrix
    void init_via_adj_matrix(vector<vector<ll>> &adjMatrix){
        noOfNodes = adjMatrix.size();
        adj.assign(noOfNodes, vector<ll>());
        for(int i = 0; i < noOfNodes; i++){
            for(int j = 0; j < noOfNodes; j++){
                if(adjMatrix[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        subtreeSum.assign(noOfNodes, 0);
        noOfNodesInSubtree.assign(noOfNodes, 0);
        dfsInTime.assign(noOfNodes, -1);
        dfsOutTime.assign(noOfNodes, -1);
        depth.assign(noOfNodes, -1);
        parent.assign(noOfNodes, -1);
        eulerTour.clear();
        segmentTree.assign(4 * noOfNodes, 0);
    }

    // Depth First Search (DFS) to fill various arrays
    void dfs(ll u, ll dep = 0, ll p = -1){
        dfsInTime[u] = eulerTour.size();
        eulerTour.push_back(u);
        depth[u] = dep;
        parent[u] = p;
        noOfNodesInSubtree[u] = 1;
        subtreeSum[u] = 1;  // In case you want to count the node itself

        for(ll v : adj[u]){
            if(v != p){
                dfs(v, dep + 1, u);
                noOfNodesInSubtree[u] += noOfNodesInSubtree[v];
                subtreeSum[u] += subtreeSum[v];
            }
        }

        dfsOutTime[u] = eulerTour.size();
    }

    // Breadth First Search (BFS)
    void bfs(ll start){
        vector<bool> visited(noOfNodes, false);
        queue<ll> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            ll node = q.front();
            q.pop();
            cout << node << " ";
           
            for(auto &neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    // Get LCA (Lowest Common Ancestor) using Euler Tour + Segment Tree
    void buildSegmentTree() {
        // Build the segment tree from Euler Tour
        ll n = eulerTour.size();
        for (ll i = 0; i < n; ++i)
            segmentTree[n + i] = eulerTour[i];
       
        for (ll i = n - 1; i > 0; --i)
            segmentTree[i] = min(segmentTree[i * 2], segmentTree[i * 2 + 1]);
    }

    // Query for LCA in Euler Tour + Segment Tree
    ll queryLCA(ll u, ll v) {
        ll l = min(dfsInTime[u], dfsInTime[v]);
        ll r = max(dfsInTime[u], dfsInTime[v]);
        ll result = LONG_LONG_MAX;
       
        // Query the segment tree between l and r
        l += segmentTree.size() / 2;
        r += segmentTree.size() / 2;
       
        while(l <= r) {
            if(l % 2 == 1) {
                result = min(result, segmentTree[l]);
                l++;
            }
            if(r % 2 == 0) {
                result = min(result, segmentTree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return result;
    }

    // Get subtree sum of node u
    ll getSubtreeSum(ll u) {
        return subtreeSum[u];
    }

    // Get number of nodes in the subtree rooted at u
    ll getNumberOfNodesInSubtree(ll u) {
        return noOfNodesInSubtree[u];
    }

    // Check if node u is an ancestor of node v
    bool isAncestor(ll u, ll v) {
        return dfsInTime[u] <= dfsInTime[v] && dfsOutTime[u] >= dfsOutTime[v];
    }

    // Preprocess LCA using DFS and Euler Tour
    void preprocessLCA() {
        eulerTour.clear();
        dfs(0);  // Root the tree at node 0
        buildSegmentTree();
    }

    // Find the kth ancestor of a node u
    ll findKthAncestor(ll u, ll k) {
        while(k > 0 && u != -1) {
            u = parent[u];
            k--;
        }
        return u;
    }

    // Get the path from node u to node v
    vector<ll> getPath(ll u, ll v) {
        vector<ll> path;
        while(u != v) {
            path.push_back(u);
            u = parent[u];
        }
        path.push_back(v);
        reverse(path.begin(), path.end());
        return path;
    }
};

void solve(){
    tree t;
    ll n; cin>>n;
    weights.clear();
    map<ll, vector<ll>> m;
    for(ll i = 0; i<n; i++){
        ll weight; cin>>weight;
        weights.push_back(weight);
        m[weight].push_back(i);
    }
   
    //process edges
    vector<pair<ll,ll>> edges;
    for(ll i = 1; i <= n-1; i++){
        ll u,v; cin>>u>>v;
        u--;
        v--;
        edges.push_back({u,v});
    }
    
    t.init_via_edge_vector(n, edges);
   
    vector<pair<ll, vector<ll>> vec;
    for(auto x : m){
        vec.push_back(x);
    }
    
    sort(vec.begin(), vec.end(), greater<pair<ll, vector<ll>>());
    
    t.dfs(0);
    
    
}

int main() {
    ll t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}