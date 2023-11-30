#include "LinkedList.h"

LinkedList::LinkedList()
	:Size(0)
{
	Head = new LinkNode;
	Head->Next = Head;
	Curr = Head;
	Tail = Head;
}

bool LinkedList::isEmpty()
{
	return Size==0;
}

int LinkedList::getCurr()
{
	return Curr->Data;
}

int LinkedList::getSize()
{
	return Size;
}

int LinkedList::getTail()
{
	return Tail->Data;
}

int LinkedList::calculateSize()
{
	int length = 0;
	LinkNode* Temp = Head;
	while (Temp->Next != Head)
	{
		length++;
		Temp = Temp->Next;
	}
	return length;
}

void LinkedList::Print()
{
	if (!Size)
	{
		cout << "������" << endl;
	}
	LinkNode* Temp = Head->Next;
	int i = 1;
	while (Temp != Head)
	{
		cout << "�ڵ�" << i << "Ϊ��" << Temp->Data << endl;
		Temp = Temp->Next;
		i++;
	}
}

void LinkedList::BuildListByHeadInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Head->Next;//��ͷ�ڵ�ĺ�һ���ڵ���ϵ
	Head->Next = Temp;//��ͷ�ڵ���ϵ
	//setTail();
	if (Temp->Next == Head)
	{
		Tail = Temp;
	}
}

void LinkedList::BuildListByTailInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Tail->Next = Temp;
	Tail = Temp;
	Tail->Next = Head;

}
void LinkedList::BackwardInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Curr->Next;
	Curr->Next = Temp;
	//setTail();
	if (Temp->Next == Head)
	{
		Tail = Temp;
	}
}

void LinkedList::ForwardInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Curr->Next;
	Curr->Next = Temp;
	swap(Temp->Data, Curr->Data);
}

void LinkedList::BackwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Node->Next;
	Node->Next = Temp;
	//setTail();
	if (Temp->Next == Head)
	{
		Tail = Temp;
	}
}

void LinkedList::ForwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Node->Next;
	Node->Next = Temp;
	swap(Temp->Data, Node->Data);
}

void LinkedList::Delete()
{
	Size--;
	LinkNode* Temp = Curr->Next;
	Curr->Next = Temp->Next;
	delete Temp;
	//setTail();
	if (Curr->Next == Head)
	{
		Tail = Curr;
	}
}

void LinkedList::DeleteByNode(LinkNode* Node)
{
	Size--;
	LinkNode* Temp = Node->Next;
	Node->Next = Temp->Next;
	delete Temp;
	//setTail();
	if (Node->Next == Head)
	{
		Tail = Node;
	}
}

int LinkedList::Find(int ele)
{
	LinkNode* Temp = Head->Next;//����Ϊ�����±�Ϊ1
	for (int i = 1; i <= Size; i++)
	{
		if (Temp->Data == ele)
			return i;
		Temp = Temp->Next;
	}
	return 0;
}

int LinkedList::At(int pos)
{
	LinkNode* Temp = Head;//ͷ�ڵ������Ϊ�����±�Ϊ0
	for (int i = 1; i <= pos; i++)
	{
		Temp = Temp->Next;
	}
	return Temp->Data;
}

void LinkedList::Prev()
{
	Curr = Curr->Next;
}

void LinkedList::Clear()
{
	if (Head->Next == Head)//��Ϊ�ձ�
		return;
	else
	{
		LinkNode* Temp = Head->Next;//ͷ�ڵ����һ�ڵ���Ϊ�����±�Ϊ1
		while (Temp != Head)
		{
			LinkNode* Temp_Next = Temp->Next;//����Ҫɾ���ڵ�ĺ����ڵ�
			delete Temp;//ɾ���ڵ�
			Temp = Temp_Next;//�ƶ���ɾ���ڵ�
		}
		Head->Next = Head;//
		Size = 0;
	}
}

void LinkedList::Destory()
{
	if (Head->Next == Head)//��Ϊ�ձ�
	{
		return;
	}
	else
	{
		this->Clear();
		delete Head;
		Head = nullptr;
		cout << "Successful Destory" << endl;
	}
}
LinkNode* LinkedList::GetElemByPos(int pos)
{
	if (pos < 1)return NULL;
	LinkNode* Temp = Head->Next;//ͷ�ڵ����һ���ڵ������Ϊ�����±�Ϊ1
	int j = 1;
	while (Temp != Head && j < pos)
	{
		Temp = Temp->Next;
		j++;
	}
	return Temp;
}

LinkNode* LinkedList::GetElemByValue(int ele)
{
	LinkNode* Temp = Head->Next;
	while (Temp != Head && Temp->Data != ele)
		Temp = Temp->Next;
	return Temp;
}
void LinkedList::setTail()
{
	LinkNode* Temp = Head;
	while (Temp->Next != Head)
	{
		Temp = Temp->Next;
	}
	Tail = Temp;
	Tail->Next = Head;
}

LinkNode* LinkedList::getTailItem()
{
	return Tail;
}


