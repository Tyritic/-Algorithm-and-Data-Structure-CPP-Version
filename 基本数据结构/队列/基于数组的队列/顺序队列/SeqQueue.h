#pragma once
#include<iostream>
const int Max=5;
using namespace std;
class SeqQueue
{
public:
	int* QueueArray;
	int front, rear;//frontΪ��һ��Ԫ�ص��±꣬rearΪ���һ��Ԫ�صĺ�һ��λ��
	int maxSize;
	int size;
	SeqQueue(int max = Max);
	bool isEmpty();
	void EnQueue(int val);
	int DeQueue();
	bool overFlow();
	void reSize(int newSize);//�������ó���
	void Clear();//��ն��е���ɾ��
	void Destory();//ɾ������
	void display();//�������
	int getRear();
};

