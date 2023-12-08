#pragma once
#include<iostream>
const int Max = 5;
using namespace std;
class Circular_queue
{
public:
	int* QueueArray;
	int front, rear;//front为第一个元素的下标，rear为最后一个元素的后一个位置
	int maxSize;
	int size;

public:
	Circular_queue(int max = Max);
	bool isEmpty();
	bool isFull();
	void Enqueue(int val);
	int Dequeue();
	void Clear();//清空队列但不删除
	void Destory();//删除队列
	void display();//输出队列
	int getSize();//计算长度
	int getFront();//获取队首元素
	int getRear();//获取队尾元素

};

