#pragma once
#include<iostream>
using namespace std;
class ArcNode
{
public:
	int adjVertex;//该弧指向顶点在顶点集中的位置
	ArcNode* nextArc;//指向下一条弧的指针
public:
	ArcNode(int v, ArcNode* next);
	ArcNode();
	int getAdjVertex();
};
