const int MAXN = 100005;
vector<int> tree[MAXN];
int parent[MAXN];  // Stores the parent of each node
int depth[MAXN];   // Stores depth of each node

// DFS to preprocess parent and depth
void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;

    for (int child : tree[node]) {
        if (child != par) { // Avoid revisiting parent
            dfs(child, node, d + 1);
        }
    }
}

// Function to find LCA using parent traversal
int findLCA(int u, int v) {
    // Step 1: Bring both nodes to the same depth
    while (depth[u] > depth[v]) u = parent[u];
    while (depth[v] > depth[u]) v = parent[v];

    // Step 2: Move both nodes up until they meet
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u; // LCA found
}
