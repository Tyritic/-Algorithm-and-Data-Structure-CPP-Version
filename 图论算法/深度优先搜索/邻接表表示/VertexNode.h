#pragma once
#include<iostream>
#include"ArcNode.h"
class VertexNode
{
public:
	string data;//���㱣�������
	ArcNode* firstArc;//ָ���һ�������ö���Ļ�
public:
	VertexNode(string data);
	VertexNode();
};

