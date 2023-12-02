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
	//return Size==0;
	return Head->Next == nullptr;
}


void LinkList::BuildListByHeadInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
        //若头节点后无节点
	if (Head->Next == NULL)
	{
		//新节点和头节点建立双向联系
		Temp->Prev = Head;
		Head->Next = Temp;
	}
	else
	{
		//新节点和头节点的后驱建立双向联系
		Head->Next->Prev = Temp;//将当前节点的后一个节点的上一个节点设为新节点
		Temp->Next = Head->Next;//将新节点的下一个节点为当前节点的下一个节点
                //新节点和头节点建立双向联系
		Temp->Prev = Head;
		Head->Next = Temp;
	}
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
	//和尾节点建立双向联系
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
	//和当前位置的后驱节点建立双向联系
	Temp->Next = Curr->Next;//将新节点的next为插入位置的next相连
	Curr->Next->Prev = Temp;//将插入位置的next的prev和新节点相连
	//和当前节点建立双向联系
	Temp->Prev = Curr;//将新节点的prev设为当前位置
	Curr->Next = Temp;//将当前位置的next设为新节点
	if (Temp->Next == nullptr)Tail = Temp;
	
	
}

void LinkList::ForwardInsert(int ele)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//和当前位置的后驱节点建立双向联系
	Temp->Next = Curr->Next;//将新节点的next为插入位置的next相连
	Curr->Next->Prev = Temp;//将插入位置的next的prev和新节点相连
	//和当前节点建立双向联系
	Temp->Prev = Curr;//将新节点的prev设为当前位置
	Curr->Next = Temp;//将当前位置的next设为新节点
	swap(Temp->Data, Curr->Data);
}

void LinkList::BackwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//和当前节点的后一个节点建立双向联系
	Temp->Next = Node->Next;//将新节点的下一个节点为当前节点的下一个节点
	Node->Next->Prev = Temp;//将当前节点的后一个节点的上一个节点设为新节点
	//和当前节点建立双向联系
	Temp->Prev = Node;//将新节点的上一个节点设为当前节点
	Node->Next = Temp;//将当前节点的下一个节点设为新节点
	if (Temp->Next == nullptr)Tail = Temp;
}

void LinkList::ForwardInsertByNode(int ele, LinkNode* Node)
{
	Size++;
	LinkNode* Temp = new LinkNode(ele);
	//和当前节点的后一个节点建立双向联系
	Temp->Next = Node->Next;//将新节点的下一个节点为当前节点的下一个节点
	Node->Next->Prev = Temp;//将当前节点的后一个节点的上一个节点设为新节点
	//和当前节点建立双向联系
	Temp->Prev = Node;//将新节点的上一个节点设为当前节点
	Node->Next = Temp;//将当前节点的下一个节点设为新节点
	swap(Temp->Data, Node->Data);
}

int LinkList::getSize()
{
	return this->Size;
}

void LinkList::Delete()
{
	Size--;
	LinkNode* Temp = Curr->Next;//被删除节点
	//和被删除节点的后驱节点进行双向关联
	Curr->Next = Temp->Next;//当前位置的next和被删除节点的后驱节点相连
	Temp->Next->Prev = Curr;//被删除节点的后驱节点的prev指向当前位置
	delete Temp;
	if (Curr->Next == NULL)Tail = Curr;
}

void LinkList::DeleteByNode(LinkNode* Node)
{
	Size--;
	LinkNode* Temp = Node->Next;//被删除节点
	//和被删除节点的后驱节点进行双向关联
	Node->Next = Temp->Next;//删除位置的next和被删除节点的后驱节点相连
	Temp->Next->Prev = Node;//被删除节点的后驱节点的prev指向删除位置
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
		cout << "空链表" << endl;
	}
	int i = 1;
	LinkNode* Temp = Head->Next;
	while (Temp)
	{
		cout << "节点" << i << "为：" << Temp->Data << endl;
		Temp = Temp->Next;
		i++;
	}
}

void LinkList::ReversePrint()
{
	if (Head->Next == nullptr)
	{
		cout << "空链表" << endl;
	}
	int i = 0;
	LinkNode* Temp = Tail;
	while (Temp->Prev)
	{
		cout << "节点" << Size-i << "为：" << Temp->Data << endl;
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
	LinkNode* Temp = Head->next;
	while (Temp)
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
