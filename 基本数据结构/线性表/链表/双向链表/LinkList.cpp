#include "LinkList.h"

LinkList::LinkList()
	:Size(0)
{
	Head = new LinkNode;
	Curr = Head;
	Tail = Head;
}

bool LinkList::isEmpty()
{
	return Size==0;
}

void LinkList::BuildListByHeadInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//�½ڵ��ͷ�ڵ�ĺ�������˫����ϵ
	Temp->Next = Head->Next;
	Temp->Prev = Head;
	Head->Next = Temp;
	//setTail();
	if (Temp->Next == nullptr)
	{
		Tail = Temp;
	}
}

void LinkList::BuildListByTailInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//��β�ڵ㽨��˫����ϵ
	if (Tail->Next == nullptr)
	{
		Tail->Next = Temp;
		Temp->Prev = Tail;
	}
	Tail = Temp;
}

void LinkList::BackwardInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//�͵�ǰ�ڵ�ĺ�һ���ڵ㽨��˫����ϵ
	Temp->Next = Curr->Next;//���½ڵ����һ���ڵ�Ϊ��ǰ�ڵ����һ���ڵ�
	Curr->Next->Prev = Temp;//����ǰ�ڵ�ĺ�һ���ڵ����һ���ڵ���Ϊ�½ڵ�
	//�͵�ǰ�ڵ㽨��˫����ϵ
	Temp->Prev = Curr;//���½ڵ����һ���ڵ���Ϊ��ǰ�ڵ�
	Curr->Next = Temp;//����ǰ�ڵ����һ���ڵ���Ϊ�½ڵ�
	if (Temp->Next == nullptr)Tail = Temp;
	
	
}

void LinkList::ForwardInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//�͵�ǰ�ڵ�ĺ�һ���ڵ㽨��˫����ϵ
	Temp->Next = Curr->Next;//���½ڵ����һ���ڵ�Ϊ��ǰ�ڵ����һ���ڵ�
	Curr->Next->Prev = Temp;//����ǰ�ڵ�ĺ�һ���ڵ����һ���ڵ���Ϊ�½ڵ�
	//�͵�ǰ�ڵ㽨��˫����ϵ
	Temp->Prev = Curr;//���½ڵ����һ���ڵ���Ϊ��ǰ�ڵ�
	Curr->Next = Temp;//����ǰ�ڵ����һ���ڵ���Ϊ�½ڵ�
	swap(Temp->Data, Curr->Data);
}

void LinkList::BackwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//�͵�ǰ�ڵ�ĺ�һ���ڵ㽨��˫����ϵ
	Temp->Next = Node->Next;//���½ڵ����һ���ڵ�Ϊ��ǰ�ڵ����һ���ڵ�
	Node->Next->Prev = Temp;//����ǰ�ڵ�ĺ�һ���ڵ����һ���ڵ���Ϊ�½ڵ�
	//�͵�ǰ�ڵ㽨��˫����ϵ
	Temp->Prev = Node;//���½ڵ����һ���ڵ���Ϊ��ǰ�ڵ�
	Node->Next = Temp;//����ǰ�ڵ����һ���ڵ���Ϊ�½ڵ�
	if (Temp->Next == nullptr)Tail = Temp;
}

void LinkList::ForwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//�͵�ǰ�ڵ�ĺ�һ���ڵ㽨��˫����ϵ
	Temp->Next = Node->Next;//���½ڵ����һ���ڵ�Ϊ��ǰ�ڵ����һ���ڵ�
	Node->Next->Prev = Temp;//����ǰ�ڵ�ĺ�һ���ڵ����һ���ڵ���Ϊ�½ڵ�
	//�͵�ǰ�ڵ㽨��˫����ϵ
	Temp->Prev = Node;//���½ڵ����һ���ڵ���Ϊ��ǰ�ڵ�
	Node->Next = Temp;//����ǰ�ڵ����һ���ڵ���Ϊ�½ڵ�
	swap(Temp->Data, Node->Data);
}

int LinkList::getSize()
{
	return this->Size;
}

void LinkList::Delete()
{
	Size--;
	LinkNode* Temp = Curr->Next;//��ɾ���ڵ�
	//�͵�ǰ�ڵ����һ���ڵ����һ���ڵ����˫�����
	Curr->Next = Temp->Next;
	Temp->Next->Prev = Curr;
	delete Temp;
	if (Curr->Next == NULL)Tail = Curr;
}

void LinkList::DeleteByNode(LinkNode* Node)
{
	Size--;
	LinkNode* Temp = Node->Next;//��ɾ���ڵ�
	//�͵�ǰ�ڵ����һ���ڵ����һ���ڵ����˫�����
	Node->Next = Temp->Next;
	Temp->Next->Prev = Node;
	delete Temp;
	if (Node->Next == NULL)Tail = Node;
}

int LinkList::getCurr()
{
	return Curr->Data;
}

void LinkList::SequentialPrint()
{
	if (Head->Next == nullptr)
	{
		cout << "������" << endl;
	}
	int i = 1;
	LinkNode* Temp = Head->Next;
	while (Temp)
	{
		cout << "�ڵ�" << i << "Ϊ��" << Temp->Data << endl;
		Temp = Temp->Next;
		i++;
	}
}

void LinkList::ReversePrint()
{
	if (Head->Next == nullptr)
	{
		cout << "������" << endl;
	}
	int i = 0;
	LinkNode* Temp = Tail;
	while (Temp->Prev)
	{
		cout << "�ڵ�" << Size-i << "Ϊ��" << Temp->Data << endl;
		Temp = Temp->Prev;
		i++;
	}
}

LinkNode* LinkList::GetHead()
{
	return this->Head;
}

void LinkList::Prev()
{
	Curr = Curr->Next;
}

int LinkList::Find(int ele)
{
	int i = 1;
	LinkNode* Temp = Head->Next;
	while (Temp)
	{
		if (Temp->Data == ele)
		{
			return i;
		}
		Temp = Temp->Next;
		i++;
	}
}

int LinkList::At(int pos)
{
	LinkNode* Temp = Head;
	for (int i = 1; i <= pos; i++)
	{
		Temp = Temp->Next;
	}
	return Temp->Data;
}

void LinkList::Clear()
{
	if (Head->Next == nullptr)//��Ϊ�ձ�
		return;
	else
	{
		LinkNode* Temp = Head->Next;//ͷ�ڵ����һ�ڵ���Ϊ�����±�Ϊ1
		while (Temp != nullptr)
		{
			LinkNode* Temp_Next = Temp->Next;//����Ҫɾ���ڵ�ĺ����ڵ�
			delete Temp;//ɾ���ڵ�
			Temp = Temp_Next;//�ƶ���ɾ���ڵ�
		}
		Head->Next = nullptr;//
		Size = 0;
	}
}

void LinkList::Destory()
{
	if (Head->Next == nullptr)//��Ϊ�ձ�
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

LinkNode* LinkList::GetElemByPos(int pos)
{
	LinkNode* Temp = Head;
	for (int i = 1; i <= pos; i++)
	{
		Temp = Temp->Next;
	}
	return Temp;
}

LinkNode* LinkList::GetElemByValue(int ele)
{
	LinkNode* Temp = Head->Next;
	while (Temp)
	{
		if (Temp->Data == ele)
		{
			return Temp;
		}
		Temp = Temp->Next;
	}
}

void LinkList::setTail()
{
	LinkNode* Temp = Head;
	while (Temp->Next != nullptr)
	{
		Temp = Temp->Next;
	}
	Tail = Temp;
}

int LinkList::CaculateSize()
{
	int length = 0;
	LinkNode* Temp = Head;
	while (Temp->Next != nullptr)
	{
		length++;
		Temp = Temp->Next;
	}
	return length;
}

int LinkList::getTail()
{
	return Tail->Data;
}
