#include "SeqQueue.h"

SeqQueue::SeqQueue(int max)
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

bool SeqQueue::isEmpty()
{
	return front==rear;
}

void SeqQueue::EnQueue(int val)
{
	if (rear == maxSize)
		cout << "上溢出" << endl;
	else
	{
		size++;
		QueueArray[rear] = val;
		rear++;
	}
}

int SeqQueue::DeQueue()
{
	if (this->front == this->rear)
		cout << "空队列" << endl;
	else
	{
		int val = QueueArray[front];
		size--;
		front++;
		return val;
	}
	
}

bool SeqQueue::overFlow()
{
	return rear==maxSize;
}

void SeqQueue::reSize(int newSize)
{
	if (newSize < 0)
	{
		cerr << "Invalid Data" << endl;
	}
	if (newSize != maxSize)
	{
		maxSize = newSize;
		int* newArray = new int[maxSize];
		if (newArray == nullptr)
		{
			cerr << "Memory allocate error" << endl;
			exit(0);
		}
		for (int i = 0; i < maxSize; i++)
		{
			newArray[i] = QueueArray[i];
		}
		delete[] QueueArray;
		QueueArray = newArray;
	}
}

void SeqQueue::Clear()
{
	if (QueueArray == nullptr)//若为空表
		return;
	else
	{
		for (int i = 0; i <= rear; i++)
			QueueArray[i] = 0;
	}
}

void SeqQueue::Destory()
{
	Clear();
	delete[]QueueArray;
}

void SeqQueue::display()
{
	for (int i = front; i <rear; i++)
	{
		cout << QueueArray[i] << endl;
	}
}

int SeqQueue::getRear()
{
	return QueueArray[rear-1];
}
