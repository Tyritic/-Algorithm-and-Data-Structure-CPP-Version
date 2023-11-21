#pragma once
#include<iostream>
#include"ArcNode.h"
class VertexNode
{
public:
	string data;//顶点保存的数据
	ArcNode* firstArc;//指向第一条依附该顶点的弧
public:
	VertexNode(string data);
	VertexNode();
};

