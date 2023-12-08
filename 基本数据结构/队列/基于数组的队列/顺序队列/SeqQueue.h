#pragma once
#include<iostream>
const int Max=5;
using namespace std;
class SeqQueue
{
public:
	int* QueueArray;
	int front, rear;//front为第一个元素的下标，rear为最后一个元素的后一个位置
	int maxSize;
	int size;
	SeqQueue(int max = Max);
	bool isEmpty();
	void EnQueue(int val);
	int DeQueue();
	bool overFlow();
	void reSize(int newSize);//重新设置长度
	void Clear();//清空队列但不删除
	void Destory();//删除队列
	void display();//输出队列
	int getRear();
};

