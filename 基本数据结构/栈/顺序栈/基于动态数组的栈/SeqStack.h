#pragma once
#include<iostream>
using namespace std;
const int Max = 20;
class SeqStack
{
private:
	//�����ϵtop+1=size
	int* StackArray;//˳��ջ
	int top;//ջ��Ԫ���±꣬��ʼֵΪ-1
	int maxSize;//��󳤶�
	int size;//ջ��
public:
	SeqStack(int maxSize = Max);
	bool isEmpty();//�п�
	void push(int val);//��ջ
	int pop();//��ջ
	bool isFull();//����
	void reSize(int newSize);//�������ó���
	int getSize();//����ջ��
	int getTop();
	int getTopIndex();
	void print();
};

