#pragma once
#include"ArcNode.h"
#include"VertexNode.h"
#include<queue>
#include<iostream>
#include<stack>
using namespace std;
class Graph
{
public:
	VertexNode* vertices;//顶点集合
	bool* visited;//标记访问情况
	int numVer, numArc;//顶点数和边数
	int* inDegree;//记录顶点的入度
public:
	Graph(int numVer, int numArc);
	void initVertex();//初始化顶点集合
	void addEdge(int from, int to,int weight);//添加边，输入起始顶点和终点顶点在顶点集中的数组下标
	void printLink(ArcNode*next);//打印邻接表中链表的节点数据*
	void display();//打印邻接表
	void getNeighbors(int v);//获取给定顶点的邻接顶点
	int getVertex(string data);//根据数据查找顶点
	void addEdge(string from, string to,int weight);//添加边，输入起始顶点和终点顶点的数据
	int FirstNeighbor(int v);
	int NextNeighbor(int v, int w);
	void DFS(int v);
};
