#include "mst.h"

// Constructor
MST::MST()
{
    size = 0;
}

// Deconstructor
MST::~MST()
{

}

// Adds node to graph
void MST::addNode(string name)
{
    nameList.push_back(name);
    size++;
    adjList.resize(size);
}

// Adds edge to graph
void MST::addEdge(string uName, string vName, int dist)
{
    int u = getIndex(uName);
    int v = getIndex(vName);
    edge uEdge = {u, v, dist};
    edge vEdge = {v, u, dist};
    adjList[u].push_back(uEdge);
    adjList[v].push_back(vEdge);
}

// Gets the index of the city and returns it
int MST::getIndex(string name)
{
    auto it = find(nameList.begin(), nameList.end(), name);
    return it - nameList.begin();
}

// Handles MST algorithm
void MST::startMST()
{
    priority_queue<node, vector<node>, greater<node>> pq;
    
    int src = 0;

    parent.resize(size);
    distance.resize(size);
    for(int i = 0; i < size; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    
    vector<bool> inMST(size, false);

    pq.push(make_pair(0, src));
    distance[src] = 0;

    while(!pq.empty())
    {
        // look at first node in the priority queue
        int u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;
        
        // iterate through all adjacent vertices
        for (auto i = adjList[u].begin(); i != adjList[u].end(); i++)
        {
            int v = i->v;
            int dist = i->dist;

            // if v is valid and closer, update distance
            if (!inMST[v] && distance[v] > dist)
            {
                distance[v] = dist;
                pq.push(make_pair(distance[v], v));
                parent[v] = u;
            }
        }
    }

    // print out results
    cout << "Edges:" << endl;
    for(int i = 1; i < size; i++)
    {
        cout << nameList[parent[i]] << " - " << nameList[i] << endl;
    }

    int total = 0;
    for(int i = 1; i < size; i++)
        total += distance[i];
    
    cout << endl << "Total distance: " << total << endl;

}
