#pragma once
#include<iostream>
using namespace std;
class ArcNode
{
public:
	int adjVertex;//�û�ָ�򶥵��ڶ��㼯�е�λ��
	ArcNode* nextArc;//ָ����һ������ָ��
	int weight;
public:
	ArcNode(int v, ArcNode* next,int weight);
	ArcNode();
	int getAdjVertex();
};

