#include "LinkedStack.h"

LinkedStack::LinkedStack()
	:size(0)
{
	top = NULL;
}

void LinkedStack::push(int val)
{
	size++;
	LinkNode* temp = new LinkNode(val);
	temp->next = top;
	top = temp;
}

int LinkedStack::pop()
{
	if (isEmpty())
		cout << "Empty,Stack" << endl;
	else
	{
		size--;
		LinkNode* temp = top;
		int val = temp->data;
		top = temp->next;
		delete temp;
		return val;
	}
}

void LinkedStack::print()
{
	LinkNode* temp = top;
	int i = 0;
	while (temp)
	{
		cout << "第" << i << "个元素为：" << temp->data << endl;
		temp = temp->next;
		i++;
	}
}

bool LinkedStack::isEmpty()
{
	return top==nullptr;
}

int LinkedStack::getSize()
{
	int Size = 0;
	LinkNode* temp = top;
	while (temp)
	{
		Size++;
		temp = temp->next;
	}
	return Size;
}

int LinkedStack::getTop()
{
	return top->data;
}

int LinkedStack::getTopIndex()
{
	return size;
}

