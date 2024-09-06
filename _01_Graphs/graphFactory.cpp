#include<bits/stdc++.h>
using namespace std;

//method to generate adjacency list for undirected graph from edges

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

//method to generate adjacency list for directed graph from edges

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

int main()
{

    cout<<"Test";

    return 0;
}

