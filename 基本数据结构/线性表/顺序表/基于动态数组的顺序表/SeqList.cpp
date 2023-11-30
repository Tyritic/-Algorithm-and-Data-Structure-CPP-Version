#include "SeqList.h"
#include<iostream>
using namespace std;
SeqList::SeqList(int size)
	:maxSize(size),Size(0),Curr(0)
{
	if (size < 0)
	cerr << "Invalid Data" << endl;
	Init(size);
}

void SeqList::Init(int size)
{
	Array = new int[size];
}

void SeqList::reSize(int newSize)
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
			newArray[i] = Array[i];
		}
		delete[] Array;
		Array = newArray;
	}
}

void SeqList::Insert(int ele)
{
	for (int i = Size; i >Curr; i--)
	{
		Array[i] = Array[i - 1];
	}
	Size++;
	Array[Curr] = ele;
}

void SeqList::Insert(int ele, int pos)
{
	if (pos < 0 || pos >= maxSize)
	{
		cerr << "Invalid Position" << endl;
		return;
	}
	else
	{
		Size++;
		for (int i = Size; i > pos; i--)
		{
			Array[i] = Array[i - 1];
		}
		Array[pos] = ele;
	}

}

void SeqList::Emit()
{
	for (int i = Curr; i < Size-1; i++)
	{
		Array[i] = Array[i + 1];
	}
	Size--;
}

void SeqList::Emit(int pos)
{
	if (pos < 0 || pos >= Size)
	{
		cerr << "Invalid Position" << endl;
		return;
	}
	else
	{
		for (int i = pos; i < Size - 1; i++)
		{
			Array[i] = Array[i + 1];
			
		}
		Size--;
	}
}

bool SeqList::isEmpty()
{
	return Size==0;
}

bool SeqList::isFull()
{
	return Size<=maxSize;
}

int SeqList::getMaxSize()
{
	return maxSize;
}

void SeqList::Print()
{
	for (int i = 0; i < Size; i++)
		cout << "下标为" << i << "的元素为：" << Array[i] << endl;
}

int SeqList::At(int ele)
{
	for (int i = 0; i < Size; i++)
	{
		if (Array[i] == ele)return i;
	}
}

int SeqList::Find(int pos)
{
	return Array[pos];
}

void SeqList::Append(int ele)
{
	if (Size + 1 <= maxSize)
	{
		Array[Size] = ele;
		Size++;
	}
	else
	{
		reSize(Size + 1);
		Array[Size] = ele;
		Size++;
	}
}

int SeqList::getSize()
{
	return Size;
}
