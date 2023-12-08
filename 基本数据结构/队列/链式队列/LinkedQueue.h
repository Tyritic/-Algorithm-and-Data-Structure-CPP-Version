#pragma once
#include"LinkedNode.h"
#include<iostream>
using namespace std;
class LinkedQueue
{
public:
	LinkedNode* front;//队头结点，结点内无数据
	LinkedNode* rear;//队尾结点，结点内有数据
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

