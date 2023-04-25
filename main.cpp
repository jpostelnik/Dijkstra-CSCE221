#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

#include "Graph.h"

int main(int argc, const char *argv[])
{
    cout << "Filename of graph to load: ";

    string filename;
    cin >> filename;
    // TODO: next five code snippets
    // Snippet 1: read filename and open file
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return 0;
    }
    // Snippet 2: get number graph size
    int vertexCount, edgeCount;
    file >> vertexCount >> edgeCount;

    // cout << "vertexCount: " << vertexCount << endl;
    // cout << "edgeCount: " << edgeCount << endl;
    // Snippet 3: create graph
    Graph *graph = new Graph();

    for (size_t i = 0; i < vertexCount; i++)
    {
        /* code */
        graph->insertVertex(i);
    }

    // Snippet 4: read edges
    for (size_t i = 0; i < edgeCount; i++)
    {
        /* code */
        int l1, l2;
        float w;
        file >> l1 >> l2;
        file >> w;
        // cout << l1 << " " << l2 << " " << w << endl;
        graph->insertEdge(l1, l2, w);
    }

    // Snippet 5: read start and end of path
    int startVertex = 0;
    int endVertex = 0;
    file >> startVertex >> endVertex;

    cout << "Shortest path from " << startVertex << " to " << endVertex << ":" << endl;

    vector<Vertex *> path = graph->shortestPath(startVertex, endVertex);

    // TODO: call shortest path on your graph for the sstart and end verices and save result to path

    for (auto i : path)
    { // this is a for-each loop
        cout << i->label << " ";
    }
    // cout endline at very end
    cout << endl;
    return 0;
}
