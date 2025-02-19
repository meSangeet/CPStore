/*
Sangeet CP Template
02-19-2025
Google OA
Q1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Solve Function
int dfs(vector<int> &Passengers, vector<vector<int>> &tree, int node, int par){
    int need = 0;
    //let's check for bacche

    for(int child : tree[node]){
        //child should not be par
        if(child != par){
            need += dfs(Passengers, tree, child, node);
        }
    }

    //if some bus will come from bacche we don't need a new one
    if(need > 0){
        return need;
    }

    if(Passengers[node] == 1){
        return 1;
    }
    return 0;
}

int solve(int N, vector<int> Passengers, vector<vector<int>> Edges) {
    vector<vector<int>> tree(N+1);
    for(auto x : Edges){
        tree[x[0]].push_back(x[1]);
        tree[x[1]].push_back(x[0]);
    }

    return dfs(Passengers, tree, 1, -1);
}

// Main Function
int main() {
    int t; cin>>t;
    while(t--){
    int N; cin>>N;
    vector<int> p(N+1);
    for(int i = 1; i<=N; i++){
        cin>>p[i];
    }
    vector<vector<int>> vec;
    for(int i = 1; i<N; i++){
        int u,v; cin>>u>>v;
        vec.push_back({u,v});
    }

    cout<<solve(N, p, vec)<<endl;
    }
    return 0;
}