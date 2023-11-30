#include "SeqList.h"

SeqList::SeqList()
	:size(0), curr_position(0)
{

}

bool SeqList::isEmpty()
{
	return size==0;
}

bool SeqList::isFull()
{
	return curr_position==(max-1);
}

void SeqList::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << ArrayList[i] << " " ;
	}
}

void SeqList::insert(int element)
{
	if (isFull())
	{
		cerr << "表已满" << endl;
		return;
	}
	else
	{
		for (int i = size; i > curr_position; i--)
		{
			ArrayList[i] = ArrayList[i - 1];
		}
		ArrayList[curr_position] = element;
		size++;
	}
	
}

void SeqList::insert(int element, int pos)
{
	if (isFull() || pos >= max)
	{
		return;
	}
	else
	{
		for (int i = size; i > pos; i--)
		{
			ArrayList[i] = ArrayList[i - 1];
		}
		ArrayList[pos] = element;
		size++;
	}
}

void SeqList::erase()
{
	size--;
	for (int i = curr_position; i < size-1; i++)
	{
		ArrayList[i] = ArrayList[i + 1];
	}
}

void SeqList::erase(int pos)
{
	if (pos >= max)
	{
		cerr << "无效位置" << endl;
	}
	else
	{
		size--;
		for (int i = pos; i < size; i++)
		{
			ArrayList[i] = ArrayList[i + 1];
		}
	}
}

int SeqList::getPos()
{
	return this->curr_position;
}

int SeqList::find(int pos)
{
	if (pos > max)
	{
		cerr << "无效位置" << endl;
	}
	else
	return ArrayList[pos];
}

int SeqList::getSize()
{
	return this->size;
}
