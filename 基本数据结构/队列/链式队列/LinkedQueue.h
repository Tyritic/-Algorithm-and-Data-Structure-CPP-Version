#pragma once
#include"LinkedNode.h"
#include<iostream>
using namespace std;
class LinkedQueue
{
public:
	LinkedNode* front;//��ͷ��㣬�����������
	LinkedNode* rear;//��β��㣬�����������
	int size;

public:
	LinkedQueue();
	bool isEmpty();
	void EnQueue(int val);
	int DeQueue();
	void display();
	int getFront();
	int getRear();
};

