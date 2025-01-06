#include<iostream>
#include<vector>
using namespace std;
#define ll long long

//printing the shortest distance of all nodes from the source node
void dijikstra(ll source, vector<vector<pair<ll,ll>>> &adj){
    ll n = adj.size();
    vector<ll> dist(n, LLONG_MAX);
    dist[source] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        ll topNode = pq.top().second;
        ll currDist = pq.top().first;

        if(currDist > dist[topNode]) continue;

        for(auto neighbour : adj[topNode]){
            ll node = neighbour.first;
            ll dist = neighbour.second;
            ll newPossibleDistanceForNode = dist[topNode] + dist;
            if(newPossibleDistanceForNode < dist[node]){
                dist[node] = newPossibleDistanceForNode;
                pq.push({dist[node], node});
            }
        }
    }
    // Print shortest distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

//returning a vector for shortest distance of all nodes from the source node

vector<ll> dijikstra(ll source, vector<vector<pair<ll,ll>>> &adj){
    ll n = adj.size();
    vector<ll> distances(n, LLONG_MAX);
    distance[source] = 0;
    priority_queue<pair<ll,ll>, vecotr<pair<ll,ll>>, greater<pair<ll,ll>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        ll topNode pq.top().second;
        ll distanceForTopNode = pq.top();
        pq.pop();
        if(distance[topNode] < distanceForTopNode) continue;
        for(const pair<ll,ll> &neighbour : adj[topNode]){
            ll neighbourNode = neighbour.first;
            ll neighbourDistance = neighbour.second;
            ll newPossibleDistanceForNode = distance[topNode] + neighbourDistance;
            if(newPossibleDistanceForNode < distance[neighbourNode]){
                distance[neighbourNode] = newPossibleDistanceForNode;
                pq.push({distance[neighbourNode], neighbourNode});
            }
        }
    } 

    return distance;
}

int main() {
    ll n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n);

    cout << "Enter edges (u, v, w) where u and v are nodes and w is the weight:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Uncomment this line for undirected graphs
    }

    ll source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(source, adj);

    return 0;
}