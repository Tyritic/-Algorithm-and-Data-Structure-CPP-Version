#include "SeqStack.h"

SeqStack::SeqStack(int maxSize)
{
	if (maxSize > 0)
	{
		StackArray = new int[maxSize];
		if (StackArray == nullptr)
			cerr << "存储分配错误" << endl;
		top = -1;
		size = 0;
		this->maxSize = Max;
	}
	else
	{
		maxSize = 0;
		size = 0;
		top = -1;
		StackArray = nullptr;
		cerr << "无效数组" << endl;
	}
}

bool SeqStack::isEmpty()
{
	return top == -1;
}

void SeqStack::push(int val)
{
	if (isFull())
		cout << "Stack is Full." << endl;
	else
	{
		top++;
		StackArray[top] = val;
		size++;
	}
}

int SeqStack::pop()
{
	if (isEmpty())
		cout << "Stack is Empty" << endl;
	else
	{
		size--;
		int val = StackArray[top];
		top--;
		return val;
		
	}
}

bool SeqStack::isFull()
{
	return top==maxSize-1;
}

void SeqStack::reSize(int newSize)
{
	int* newStack = new int[newSize];
	if(newStack==nullptr)
		cerr << "存储分配错误" << endl;
	for (int i = 0; i < size; i++)
	{
		newStack[i] = this->StackArray[i];
	}
	delete []StackArray;
	StackArray = newStack;
}

int SeqStack::getSize()
{
	return top+1;
}

int SeqStack::getTop()
{
	return StackArray[top];
}

int SeqStack::getTopIndex()
{
	return this->top;
}

void SeqStack::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << "第" << i << "个元素为：" << this->StackArray[i] << endl;
	}
}
