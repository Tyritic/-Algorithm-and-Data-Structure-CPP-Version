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
	VertexNode* vertices;//���㼯��
	bool* visited;//��Ƿ������
	int numVer, numArc;//�������ͱ���
	int* inDegree;//��¼��������
public:
	Graph(int numVer, int numArc);
	void initVertex();//��ʼ�����㼯��
	void addEdge(int from, int to,int weight);//��ӱߣ�������ʼ������յ㶥���ڶ��㼯�е������±�
	void printLink(ArcNode*next);//��ӡ�ڽӱ�������Ľڵ�����*
	void display();//��ӡ�ڽӱ�
	void getNeighbors(int v);//��ȡ����������ڽӶ���
	int getVertex(string data);//�������ݲ��Ҷ���
	void addEdge(string from, string to,int weight);//��ӱߣ�������ʼ������յ㶥�������
	int FirstNeighbor(int v);
	int NextNeighbor(int v, int w);
	void BFS(int v);
	void DFS(int v);
	void Dijkstra(int v);
	bool TopologicalSort();
};

