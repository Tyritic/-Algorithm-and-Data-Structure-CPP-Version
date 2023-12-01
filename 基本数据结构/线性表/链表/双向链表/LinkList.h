#include<iostream>
#include<algorithm>
#include"LinkNode.h"
using namespace std;
class LinkList
{
private:
	LinkNode* Head;//头节点
	LinkNode* Curr;//当前节点
	LinkNode* Tail;//尾节点
	int Size;
public:
	LinkList();
	bool isEmpty();//判空
	void BuildListByHeadInsert(int ele);//头插法建表
	void BuildListByTailInsert(int ele);//尾插法建表同时在尾节点处插入节点
	void BackwardInsert(int ele);//	在当前节点(位于中间）的后一个节点插入一个新节点
	void ForwardInsert(int ele);//	在当前节点（位于中间）的前一个节点插入一个新节点
	void BackwardInsertByNode(int ele, LinkNode* Node);//在已知节点(位于中间）的后一个节点插入一个新节点
	void ForwardInsertByNode(int ele, LinkNode* Node);//在已知节点(位于中间）的前一个节点插入一个新节点
	int getSize();//获取表长
	void Delete();//删除当前节点的下一个节点
	void DeleteByNode(LinkNode* Node);//删除已知节点的下一个节点
	int getCurr();//获取当前节点的数据
	void SequentialPrint();//顺序打印链表
	void ReversePrint();//倒序打印链表
	LinkNode* GetHead();//获取头节点
	void Prev();//将当前节点后移一位
	int Find(int ele);//按值查找节点
	int At(int pos);//按位置查找节点
	void Clear();//清空链表内元素但不删除
	void Destory();//销毁链表
	LinkNode* GetElemByPos(int pos);//按位置查找节点
	LinkNode* GetElemByValue(int ele);//按值查找节点
	void setTail();//设置尾节点
	int CaculateSize();//计算链表长
	int getTail();
};

