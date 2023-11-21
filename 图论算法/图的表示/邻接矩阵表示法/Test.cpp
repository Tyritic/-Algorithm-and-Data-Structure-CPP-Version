#include<iostream>
#include"UndirectedGraph.h"
using namespace std;
int main()
{
	UndirectedGraph G;
	G.init(6);
	G.setEdge(0, 1);
	G.setEdge(0, 2);
	G.setEdge(1, 3);
	G.setEdge(1, 4);
	G.getGraph();
	//G.BFS(4);
	G.DFS(0);
}
