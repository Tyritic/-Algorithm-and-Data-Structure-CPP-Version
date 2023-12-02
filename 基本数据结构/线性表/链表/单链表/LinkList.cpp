#include "LinkList.h"

LinkList::LinkList()
	:Size(0)
{
	Head = new LinkNode;
	Curr = Head;
	Tail = Head;
}

void LinkList::BuildListByHeadInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Head->Next;//和头节点的后一个节点联系
	Head->Next = Temp;//和头节点联系
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
	if (Tail->Next == nullptr)
	{
		Tail->Next = Temp;//和尾节点联系
		Tail = Temp;//将新节点设为尾节点
		Tail->Next = nullptr;//将尾节点的下一个节点设为空
	}
	

}

void LinkList::BackwardInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Curr->Next;
	Curr->Next = Temp;
	if (Temp->Next == nullptr)Tail = Temp;
}

void LinkList::ForwardInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Curr->Next;
	Curr->Next = Temp;
	swap(Temp->Data, Curr->Data);
}

void LinkList::BackwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Node->Next;
	Node->Next = Temp;
	if (Temp->Next == nullptr)Tail = Temp;

}

void LinkList::ForwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	Temp->Next = Node->Next;
	Node->Next = Temp;
	swap(Temp->Data, Node->Data);
}

int LinkList::getSize()
{
	return Size;
}

bool LinkList::isEmpty()
{
	//return Size==0;
	return Head->Next == nullptr;
}
void LinkList::Delete()
{
	Size--;
	LinkNode* Temp = Curr->Next;
	Curr->Next = Temp->Next;
	delete Temp;
	if (Curr->Next == NULL)Tail = Curr;
}

void LinkList::DeleteByNode(LinkNode* Node)
{
	Size--;
	LinkNode* Temp = Node->Next;
	Node->Next = Temp->Next;
	delete Temp;
	if (Node->Next == NULL)Tail = Node;
}

int LinkList::getCurr()
{
	return Curr->Data;
}

void LinkList::Print()
{
	if (Head->Next == nullptr)
	{
		cout << "空链表" << endl;
	}
	LinkNode* Temp = Head->Next;
	int i = 1;
	while (Temp != nullptr)
	{
		cout<<"节点"<<i<<"为："<<Temp->Data <<endl;
		Temp = Temp->Next;
		i++;
	}
}

int LinkList::Find(int ele)
{
	LinkNode* Temp = Head->Next;//可视为数组下标为1
	for (int i = 1; i <= Size; i++)
	{
		if (Temp->Data == ele)
			return i;
		Temp = Temp->Next;
	}
	return 0;
}

int LinkList::At(int pos)
{
	LinkNode* Temp = Head;//头节点可以视为数组下标为0
	for (int i = 1; i <= pos; i++)
	{
		Temp=Temp->Next;
	}
	return Temp->Data;
}

void LinkList::Prev()
{
	Curr = Curr->Next;
}

void LinkList::Clear()
{
	if (Head->Next == nullptr)//若为空表
		return;
	else
	{
		LinkNode* Temp = Head->Next;//头节点的下一节点视为数组下标为1
		while (Temp != nullptr)
		{
			LinkNode* Temp_Next = Temp->Next;//保存要删除节点的后驱节点
			delete Temp;//删除节点
			Temp = Temp_Next;//移动被删除节点
		}
		Head->Next = nullptr;//
		Size = 0;
	}
}

void LinkList::Destory()
{
	if (Head->Next == nullptr)//若为空表
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

int LinkList::getTail()
{
	return Tail->Data;
}

LinkNode* LinkList::GetElemByPos(int pos)
{
	if (pos < 1)return NULL;
	LinkNode* Temp = Head->Next;//头节点的下一个节点可以视为数组下标为1
	int j = 1;
	while (Temp != NULL && j < pos)
	{
		Temp = Temp->Next;
		j++;
	}
	return Temp;
}

LinkNode* LinkList::GetElemByValue(int ele)
{
	LinkNode* Temp = Head->Next;
	while (Temp != NULL && Temp->Data != ele)
		Temp = Temp->Next;
	return Temp;
}

LinkNode* LinkList::GetHead()
{
	return this->Head;
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

int LinkList::caculateSize()
{
	int length = 0;
	LinkNode* Temp = Head->Next;
	while (Temp)
	{
		length++;
		Temp = Temp->Next;
	}
	return length;
}
