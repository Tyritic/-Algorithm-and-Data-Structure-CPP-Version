#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
	front = new LinkedNode;
	rear = front;
	size = 0;
}

bool LinkedQueue::isEmpty()
{
	return this->front==this->rear;
}

void LinkedQueue::EnQueue(int val)
{
	//尾插法入队
	LinkedNode* temp = new LinkedNode(val);
	rear->next = temp;
	rear = temp;
}

int LinkedQueue::DeQueue()
{
	if (isEmpty())cout << "空队列" << endl;
	else
	{
		//front的下一个结点才是第一个元素
		LinkedNode* temp = front->next;
		int val = temp->data;
		//将队头结点的下一个结点设为临时结点的后驱结点
		front->next = temp->next;
		//若为空表
		if (rear == temp)
			rear = front;
		delete temp;
		return val;
	}
}

void LinkedQueue::display()
{
	if (isEmpty())
	{
		cout << "空表" << endl;
	}
	else
	{
		LinkedNode* temp = front->next;
		int i = 1;
		while (temp)
		{
			cout << "第" << i << "个元素为：" << temp->data << endl;
			temp = temp->next;
			i++;
		}
	}
	
}

int LinkedQueue::getFront()
{
	return front->next->data;
}

int LinkedQueue::getRear()
{
	return rear->data;
}
