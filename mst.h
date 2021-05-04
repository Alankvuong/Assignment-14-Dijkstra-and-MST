#ifndef MST_H_
#define MST_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// pair of integers to represent node (weight, index)
typedef pair<int, int> node;

// Struct to handle information of edges
struct edge
{
    int u;
    int v;
    int dist;
};

class MST
{
public:
    MST();
    ~MST();

    // graph functions
    void addNode(string name);
    void addEdge(string uName, string vName, int dist);
    
    // starts MST using Prim-Jarnik's
    void startMST();

private:
    int size;

    // contains names with associated index
    vector<string> nameList;

    // adjacency list of edges
    vector<vector<edge>> adjList;

    vector<int> parent;

    // distance to each vertex
    vector<int> distance;

    // convert from name to index
    int getIndex(string name);
};
#endif