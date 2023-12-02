#pragma once
#include"LinkNode.h"
#include<iostream>
using namespace std;
class LinkedStack
{
public:
	LinkNode* top;
	int size;
public:
	LinkedStack();
	void push(int val);
	int pop();
	void print();
	bool isEmpty();
	int getSize();
	int getTop();
	int getTopIndex();
};

