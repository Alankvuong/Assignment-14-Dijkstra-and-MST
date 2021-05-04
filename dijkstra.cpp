#include "dijkstra.h"

// Constrcutor
Dijkstra::Dijkstra()
{
    size = 0;
}

// Deconstructor
Dijkstra::~Dijkstra()
{
    
}

// Adds a node/vertices to the graph
void Dijkstra::addNode(string name)
{
    nameList.push_back(name);
    size++;
    adjMatrix.resize(size);
    for (auto it = adjMatrix.begin(); it != adjMatrix.end(); it++)
    {
        (*it).resize(size);
    }
}

// Adds an edge to the graph
void Dijkstra::addEdge(string uName, string vName, int dist)
{
    int u = getIndex(uName);
    int v = getIndex(vName);
    adjMatrix[u][v] = dist;
    adjMatrix[v][u] = dist;
}

// Gets the index of the node in the lsit and returns it
int Dijkstra::getIndex(string name)
{
    auto it = find(nameList.begin(), nameList.end(), name);
    return it - nameList.begin();
}

// Handles the dijkstra algorithm
void Dijkstra::startDijkstra(string startName)
{
    int src = getIndex(startName);
    
    distance.resize(size);
    parent.resize(size);
    sptSet.resize(size);

    for(int i = 0; i < size; i++)
    {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    distance[src] = 0;
    parent[src] = -1;

    // Find the shortest path for all vertices
    for (int count = 0; count < size; count++)
    {
        // find node with minimum distance
        int u = 0;
        int minDist = INT_MAX;
        for (int i = 0; i < size; i++) 
        {
            if (!sptSet[i] && distance[i] <= minDist)
            {
                u = i;
                minDist = distance[u];
            }
        }

        sptSet[u] = true;

        // Update distance value
        for (int v = 0; v < size; v++) {
            if (!sptSet[v] && adjMatrix[u][v] > 0 && distance[u] != INT_MAX && distance[u] + adjMatrix[u][v] < distance[v])
            {
                distance[v] = distance[u] + adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
}

// Prints the distance and path for each city
void Dijkstra::print()
{
    cout << "" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << nameList[i] << endl;
        cout << "Distance: " << distance[i] << endl;

        cout << "Path: ";
        vector<int> path;
        int p = parent[i];
        while (p != -1)
        {
            path.insert(path.begin(), p);
            p = parent[p];
        }
        for (int j = 0; j < path.size(); j++) {
            cout << nameList[path[j]];
            cout << ", ";
        }
        cout << nameList[i] << endl;
        
        cout << endl << endl;
    }

}