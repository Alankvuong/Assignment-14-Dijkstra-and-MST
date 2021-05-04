// *******************************************************
// *  PROGRAMMED BY : Alan Vuong, Caleb Yun, Ethan Bockler
// *  CLASS         : CS1D
// *  ASSIGN #14    : Dijkstra and MST
// *******************************************************

#include "main_header.h"
#include "dijkstra.h"
#include "mst.h"


/************************************************************
* Assignment Description
*------------------------------------------------------------
* This program implements dijkstra's algorithm using an 
* adjacency matrix and the algorithm is implemented with the 
* dijkstra class. First the nodes and edges are all input 
* and then the startDijkstra and print functions are called.
* The output lists the destination, the total distance that 
* was travelled on the path, and all of the vertices visited
* on the path. For part 2, the minimum spanning tree is 
* implemented using a adjacency list and a priority queue. 
* The nodes and edges are all input and the startMst function
* is called. The edges of the MST are outputed and after the
* total distance of the MST is output.
***************************************************************/

int main()
{
    PrintHeader();

    // Adds node and edges for Dijkstra
    cout << "PART 1: DIJKSTRA" << endl;

    Dijkstra d;

    d.addNode("Chicago");
    d.addNode("Seattle");
    d.addNode("Boston");
    d.addNode("San Francisco");
    d.addNode("Denver");
    d.addNode("New York");
    d.addNode("Los Angeles");
    d.addNode("Kansas City");
    d.addNode("Atlanta");
    d.addNode("Dallas");
    d.addNode("Houston");
    d.addNode("Miami");

    d.addEdge("Chicago", "Seattle", 2097);
    d.addEdge("Chicago", "Boston", 983);
    d.addEdge("Boston", "New York", 214);
    d.addEdge("New York", "Chicago", 787);
    d.addEdge("New York", "Atlanta", 888);
    d.addEdge("Denver", "Chicago", 1003);
    d.addEdge("Denver", "San Francisco", 1267);
    d.addEdge("Seattle", "Denver", 1331);
    d.addEdge("Seattle", "San Francisco", 807);
    d.addEdge("Kansas City", "New York", 1260);
    d.addEdge("Kansas City", "Atlanta", 864);
    d.addEdge("Kansas City", "Chicago", 533);
    d.addEdge("Kansas City", "Denver", 599);
    d.addEdge("Kansas City", "Los Angeles", 1663);
    d.addEdge("San Francisco", "Los Angeles", 381);
    d.addEdge("Los Angeles", "Denver", 1015);
    d.addEdge("Dallas", "Los Angeles", 1435);
    d.addEdge("Dallas", "Kansas City", 496);
    d.addEdge("Dallas", "Atlanta", 781);
    d.addEdge("Houston", "Dallas", 239);
    d.addEdge("Houston", "Atlanta", 810);
    d.addEdge("Atlanta", "Miami", 661);
    d.addEdge("Miami", "Houston", 1187);

    // Starts dijkstra at dallas
    d.startDijkstra("Dallas");
    // Prints the city distance and path for each vertices
    d.print();


    // Adds node and edges for MST
    cout << "PART 2: MST" << endl << endl;

    MST m;

    m.addNode("Chicago");
    m.addNode("Seattle");
    m.addNode("Boston");
    m.addNode("San Francisco");
    m.addNode("Denver");
    m.addNode("New York");
    m.addNode("Los Angeles");
    m.addNode("Kansas City");
    m.addNode("Atlanta");
    m.addNode("Dallas");
    m.addNode("Houston");
    m.addNode("Miami");

    m.addEdge("Chicago", "Seattle", 2097);
    m.addEdge("Chicago", "Boston", 983);
    m.addEdge("Boston", "New York", 214);
    m.addEdge("New York", "Chicago", 787);
    m.addEdge("New York", "Atlanta", 888);
    m.addEdge("Denver", "Chicago", 1003);
    m.addEdge("Denver", "San Francisco", 1267);
    m.addEdge("Seattle", "Denver", 1331);
    m.addEdge("Seattle", "San Francisco", 807);
    m.addEdge("Kansas City", "New York", 1260);
    m.addEdge("Kansas City", "Atlanta", 864);
    m.addEdge("Kansas City", "Chicago", 533);
    m.addEdge("Kansas City", "Denver", 599);
    m.addEdge("Kansas City", "Los Angeles", 1663);
    m.addEdge("San Francisco", "Los Angeles", 381);
    m.addEdge("Los Angeles", "Denver", 1015);
    m.addEdge("Dallas", "Los Angeles", 1435);
    m.addEdge("Dallas", "Kansas City", 496);
    m.addEdge("Dallas", "Atlanta", 781);
    m.addEdge("Houston", "Dallas", 239);
    m.addEdge("Houston", "Atlanta", 810);
    m.addEdge("Atlanta", "Miami", 661);
    m.addEdge("Miami", "Houston", 1187);

    m.startMST();

    return 0;
}