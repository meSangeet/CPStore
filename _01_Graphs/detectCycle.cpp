#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateAdjacencyListUndirected(const int vertices, vector<pair<int,int>> edges)
{
    vector<vector<int>> adjacencyList(vertices);

    for(auto edge : edges)
    {
        const int firstNode = edge.first;
        const int secondNode = edge.second;

        adjacencyList[firstNode].push_back(secondNode);
        adjacencyList[secondNode].push_back(firstNode);
    }

    return adjacencyList;
}

vector<vector<int>> generateAdjacencyListDirected(const int vertices, vector<pair<int,int>> edges)
{
    vector<vector<int>> adjacencyList(vertices);

    for(auto edge : edges)
    {
        const int firstNode = edge.first;
        const int secondNode = edge.second;

        adjacencyList[firstNode].push_back(secondNode);
    }

    return adjacencyList;
}

//detect cycle in undirected graph

bool checkCycleUndirected(const int currentNode, const int previousNode, vector<bool> &visited, vector<vector<int>> &graph) {
    visited[currentNode] = true;

    for (const int neighbour : graph[currentNode]) {
        if (!visited[neighbour]) {
            if (checkCycleUndirected(neighbour, currentNode, visited, graph)) {
                return true;
            }
        } else if (neighbour != previousNode) {
            return true;
        }
    }
    return false;
}

bool checkCycleInUndirectedGraph(vector<vector<int>> graph){
    bool ans = false;
    const int vertices = graph.size();
    vector<bool> visited(vertices, false);

    //loop to cover all the connected components

    for(int node = 0; node < vertices; node++)
    {
        if(!visited[node])
        {
            if(checkCycleUndirected(node, -1, visited, graph)) return true;
        }
    }
    return false;
}


//detecting cycle in a directed graph

bool checkCycleDirected(const int currentNode, vector<bool> &pathVisited, vector<bool> &visited, vector<vector<int>> &graph)
{
    visited[currentNode] = true;
    pathVisited[currentNode] = true;

    for(const int neighbour : graph[currentNode])
    {
        if(visited[neighbour] && pathVisited[neighbour]) return true;
        else if(!visited[neighbour]){
            if(checkCycleDirected(neighbour, pathVisited, visited, graph)) return true;
            pathVisited[neighbour] = false;
        }
    }
    
    pathVisited[currentNode] = false;
    return false;
}

bool checkCycleInDirectedGraph(vector<vector<int>> graph){
    bool ans = false;
    const int vertices = graph.size();
    vector<bool> visited(vertices, false);
    vector<bool> pathVisited(vertices, false);
    
    //loop to cover all the connected components

    for(int node = 0; node < vertices; node++)
    {
        if(!visited[node])
        {
            if(checkCycleDirected(node, pathVisited, visited, graph)) return true;
        }
    }
    return false;
}



int main()
{
    int vertices; cout<<"enter total number of vertices - "; cin>>vertices;
    vector<pair<int,int>> edges;
    int totalEdges; cout<<"enter total number of edges - "; cin>>totalEdges;
    
    for(int i = 0; i<totalEdges; i++)
    {
        cout<<"enter edge no "<<i+1<<" - ";
        int node1; cin>>node1; int node2; cin>>node2;
        edges.push_back({node1, node2});
    }
    vector<vector<int>> graph = generateAdjacencyListDirected(vertices, edges);

    cout<<endl<<(checkCycleInDirectedGraph(graph)?"Cycle Exists\n":"No Cycle Detected\n");

    return 0;
}

