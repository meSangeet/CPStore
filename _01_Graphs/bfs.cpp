#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
//storing the BFS of the graph into a vector
/*

V = number of vertices
adj = adjacency list

*/
vector<ll> bfs(ll V, vector<ll> adj[])
{
    vector<bool> visited(V, false);
    visited[0] = true;
    queue<ll> q;
    vector<ll> bfs;
    q.push(0);

    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto neighbour:adj[node])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return bfs;
}

int main()
{

    return 0;
}