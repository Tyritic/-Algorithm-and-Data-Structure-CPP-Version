#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Graph
{
public:
	virtual void init(int n) = 0;
	virtual int getNumVertex() = 0;
	virtual int getNumEdge() = 0;
	virtual bool Adjacent(int from, int to) = 0;
	virtual int FirstNeighbor(int v) = 0;
	virtual int NextNeighbor(int v, int w) = 0;
	virtual void setEdge(int v1, int v2) = 0;
	virtual void delEdge(int v1, int v2) = 0;
	virtual void setVisit() = 0;
};

