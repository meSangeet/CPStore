#include<iostream>
#include<vector>
using namespace std;
#define ll long long

//recursive dfs fucntion
void dfs(ll s, ll V, vector<ll> adj[], vector<ll> &dfsans, vector<bool> &visited)
{
    visited[s] = true;
    dfsans.push_back(s);

    for(auto neighbour:adj[s])
    {
        if(!visited[neighbour])
        {
            dfs(neighbour, V, adj, dfsans, visited);
        }
    }
}

//wrapper function to perform dfs
vector<ll> dfs_of_graph(ll V, vector<ll> adj[])
{
    vector<bool> visited(V, false);
    vector<ll> dfsans;
    for(int i = 0; i<V; i++)
    {
        if(!visited[i])
        {
            dfs(i, V, adj, dfsans, visited);
        }
    }

    return dfsans;
}

int main()
{


    return 0;
}