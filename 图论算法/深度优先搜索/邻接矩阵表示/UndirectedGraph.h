#pragma once
#include "Graph.h"
#include<queue>
class UndirectedGraph :
    public Graph
{
private:
    int numVertex, numEdge;
    int** matrix;
    bool* visited;
public:
    void init(int n);
    int getNumVertex();
    int getNumEdge();
    bool Adjacent(int from, int to);
    int FirstNeighbor(int v) ;
    int NextNeighbor(int v, int w) ;
    void setEdge(int v1, int v2);
    void delEdge(int v1, int v2);
    void visit(int v);
    void getGraph();
    int getDegree(int v);
    void setVisit();
};

