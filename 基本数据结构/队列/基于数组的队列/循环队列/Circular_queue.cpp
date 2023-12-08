#include "Circular_queue.h"

Circular_queue::Circular_queue(int max)
{
	if (max > 0)
	{
		QueueArray = new int[max];
		if (QueueArray == nullptr)
			cerr << "存储分配错误" << endl;
		for (int i = 0; i < max; i++)
			QueueArray[i] = 0;
		front = 0;
		rear = 0;
		size = 0;
		this->maxSize = max;
	}
	else
	{
		this->maxSize = 0;
		front = -1;
		rear = -1;
		size = 0;
		QueueArray = nullptr;
		cerr << "无效数组" << endl;
	}
}

bool Circular_queue::isEmpty()
{
	return this->front==this->rear;
}

void Circular_queue::Enqueue(int val)
{
	if (isFull())
		cout << "队满" << endl;
	else
	{
		size++;
		QueueArray[rear] = val;
		rear = (rear + 1) % maxSize;
	}
}

bool Circular_queue::isFull()
{
	return (this->rear+1)%maxSize==this->front;
}

int Circular_queue::Dequeue()
{
	if (isEmpty())
		cout << "队空" << endl;
	else
	{
		size--;
		int val = QueueArray[front];
		front = (front + 1) % maxSize;
		return val;
	}
}

void Circular_queue::Clear()
{
	if (QueueArray == nullptr)//若为空表
		return;
	else
	{
		for (int i = 0; i <maxSize; i++)
			QueueArray[i] = 0;
	}
}

void Circular_queue::Destory()
{
	Clear();
	delete[]QueueArray;
}

void Circular_queue::display()
{
	
}

int Circular_queue::getSize()
{
	return (this->rear-this->front+maxSize)%maxSize;
}

int Circular_queue::getFront()
{
	return QueueArray[front];
}

int Circular_queue::getRear()
{
	return QueueArray[(rear-1)%maxSize];
}
