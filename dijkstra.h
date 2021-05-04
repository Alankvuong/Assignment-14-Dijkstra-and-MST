#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Dijkstra
{
public:
    Dijkstra();
    ~Dijkstra();

    // add node to graph
    void addNode(string name);

    // add edge connecting nodes with weight (distance)
    void addEdge(string uName, string vName, int dist);

    // start Dijkstra algorithm from starting point
    void startDijkstra(string startName);

    // print each node's distance and path from Dijkstra
    void print();

private:
    int size;
    vector<string> nameList;
    vector<vector<int>> adjMatrix;

    // distance to each vertex
    vector<int> distance;

    // keeps track of parent of each node in SPT
    vector<int> parent;

    // included in shortest path tree
    vector<bool> sptSet;

    // helper function: convert node's name to index
    int getIndex(string name);

};

#endif