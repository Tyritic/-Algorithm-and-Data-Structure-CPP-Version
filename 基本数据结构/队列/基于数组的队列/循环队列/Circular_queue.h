#pragma once
#include<iostream>
const int Max = 5;
using namespace std;
class Circular_queue
{
public:
	int* QueueArray;
	int front, rear;//frontΪ��һ��Ԫ�ص��±꣬rearΪ���һ��Ԫ�صĺ�һ��λ��
	int maxSize;
	int size;

public:
	Circular_queue(int max = Max);
	bool isEmpty();
	bool isFull();
	void Enqueue(int val);
	int Dequeue();
	void Clear();//��ն��е���ɾ��
	void Destory();//ɾ������
	void display();//�������
	int getSize();//���㳤��
	int getFront();//��ȡ����Ԫ��
	int getRear();//��ȡ��βԪ��

};

