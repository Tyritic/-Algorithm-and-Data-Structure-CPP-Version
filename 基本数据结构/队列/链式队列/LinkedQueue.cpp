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
	//β�巨���
	LinkedNode* temp = new LinkedNode(val);
	rear->next = temp;
	rear = temp;
}

int LinkedQueue::DeQueue()
{
	if (isEmpty())cout << "�ն���" << endl;
	else
	{
		//front����һ�������ǵ�һ��Ԫ��
		LinkedNode* temp = front->next;
		int val = temp->data;
		//����ͷ������һ�������Ϊ��ʱ���ĺ������
		front->next = temp->next;
		//��Ϊ�ձ�
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
		cout << "�ձ�" << endl;
	}
	else
	{
		LinkedNode* temp = front->next;
		int i = 1;
		while (temp)
		{
			cout << "��" << i << "��Ԫ��Ϊ��" << temp->data << endl;
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
