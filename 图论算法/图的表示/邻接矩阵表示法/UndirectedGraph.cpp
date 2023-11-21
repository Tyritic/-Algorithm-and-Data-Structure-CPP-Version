#include "UndirectedGraph.h"

void UndirectedGraph::init(int n)
{
	numEdge = 0;
	numVertex = n;
	visited = new bool[n];
	for (int i = 0; i < numVertex; i++)
		visited[i] = 0;
	matrix = (int**)new int* [numVertex];
	for (int i = 0; i < numVertex; i++)
	{
		matrix[i] = new int[numVertex];
	}
	for (int i = 0; i < numVertex; i++)
	{
		for (int j = 0; j < numVertex; j++)
		{
			matrix[i][j] = 0;
		}
	}

}

int UndirectedGraph::getNumVertex()
{
	return this->numVertex;
}

int UndirectedGraph::getNumEdge()
{
	return this->numEdge;
}

bool UndirectedGraph::Adjacent(int from, int to)
{
	return matrix[from][to]&&matrix[to][from];
}

int UndirectedGraph::FirstNeighbor(int v)
{
	for (int i = 0; i < numVertex; i++)
	{
		if (matrix[v][i])return i;
	}
	return numVertex;
}

int UndirectedGraph::NextNeighbor(int v, int w)
{
	for (int i = w + 1; i < numVertex; i++)
	{
		if (matrix[v][i])return i;
	}
	return numVertex;
}

void UndirectedGraph::setEdge(int v1, int v2)
{
	matrix[v1][v2] = 1;
	matrix[v2][v1] = 1;
	numEdge++;
}

void UndirectedGraph::delEdge(int v1, int v2)
{
	matrix[v1][v2] = 0;
	matrix[v2][v1] = 0;
	numEdge--;
}

void UndirectedGraph::visit(int v)
{
	cout << "顶点" << v << endl;
	visited[v] = true;
}

void UndirectedGraph::getGraph()
{
	for (int i = 0; i < numVertex; i++)
	{
		for (int j = 0; j < numVertex; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int UndirectedGraph::getDegree(int v)
{
	int degree = 0;
	for (int i = 0; i < numVertex; i++)
	{
		degree += matrix[v][i];
	}
	return degree;
}

void UndirectedGraph::setVisit()
{
	for (int i = 0; i < numVertex; i++)
		visited[i] = false;
}
