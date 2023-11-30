#pragma once
#include<iostream>
#include"LinkNode.h"
using namespace std;
class LinkedList
{
private:
	LinkNode* Head;
	LinkNode* Tail;
	int Size;
	LinkNode* Curr;
public:
	LinkedList();
	bool isEmpty();//判空
	int getCurr();//获取当前节点
	int getSize();//获取表长
	int getTail();//获取尾节点
	int calculateSize();//计算表长
	void Print();//输出
	void BuildListByHeadInsert(int ele);//头插法建表
	void BuildListByTailInsert(int ele);//尾插法建表
	void BackwardInsert(int ele);//	在当前节点的后一个节点插入一个新节点
	void ForwardInsert(int ele);//	在当前节点(当前节点位于表的中间时）的前一个节点插入一个新节点
	void BackwardInsertByNode(int ele, LinkNode* Node);//	在已知节点的后一个节点插入一个新节点
	void ForwardInsertByNode(int ele, LinkNode* Node);//	在已知节点的前一个节点插入一个新节点
	void Delete();//删除当前节点的下一个节点
	void DeleteByNode(LinkNode* Node);//删除已知节点的下一个节点
	int Find(int ele);//按值查找节点
	int At(int pos);//按位置查找节点
	void Prev();//将当前节点后移一位
	void Clear();//清空链表内元素但不删除
	void Destory();//销毁链表
	LinkNode* GetElemByPos(int pos);//按位置查找节点
	LinkNode* GetElemByValue(int ele);//按值查找节点
	void setTail();//在建表时设置尾节点
	LinkNode* getTailItem();
};

