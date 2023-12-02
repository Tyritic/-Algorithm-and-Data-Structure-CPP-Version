#pragma once
#include<iostream>
using namespace std;
const int Max = 20;
class SeqStack
{
private:
	//满足关系top+1=size
	int* StackArray;//顺序栈
	int top;//栈顶元素下标，初始值为-1
	int maxSize;//最大长度
	int size;//栈长
public:
	SeqStack(int maxSize = Max);
	bool isEmpty();//判空
	void push(int val);//入栈
	int pop();//出栈
	bool isFull();//判满
	void reSize(int newSize);//重新设置长度
	int getSize();//计算栈长
	int getTop();
	int getTopIndex();
	void print();
};

