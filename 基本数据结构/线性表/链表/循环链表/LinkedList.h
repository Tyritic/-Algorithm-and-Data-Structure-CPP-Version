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
	bool isEmpty();//�п�
	int getCurr();//��ȡ��ǰ�ڵ�
	int getSize();//��ȡ��
	int getTail();//��ȡβ�ڵ�
	int calculateSize();//�����
	void Print();//���
	void BuildListByHeadInsert(int ele);//ͷ�巨����
	void BuildListByTailInsert(int ele);//β�巨����
	void BackwardInsert(int ele);//	�ڵ�ǰ�ڵ�ĺ�һ���ڵ����һ���½ڵ�
	void ForwardInsert(int ele);//	�ڵ�ǰ�ڵ�(��ǰ�ڵ�λ�ڱ���м�ʱ����ǰһ���ڵ����һ���½ڵ�
	void BackwardInsertByNode(int ele, LinkNode* Node);//	����֪�ڵ�ĺ�һ���ڵ����һ���½ڵ�
	void ForwardInsertByNode(int ele, LinkNode* Node);//	����֪�ڵ��ǰһ���ڵ����һ���½ڵ�
	void Delete();//ɾ����ǰ�ڵ����һ���ڵ�
	void DeleteByNode(LinkNode* Node);//ɾ����֪�ڵ����һ���ڵ�
	int Find(int ele);//��ֵ���ҽڵ�
	int At(int pos);//��λ�ò��ҽڵ�
	void Prev();//����ǰ�ڵ����һλ
	void Clear();//���������Ԫ�ص���ɾ��
	void Destory();//��������
	LinkNode* GetElemByPos(int pos);//��λ�ò��ҽڵ�
	LinkNode* GetElemByValue(int ele);//��ֵ���ҽڵ�
	void setTail();//�ڽ���ʱ����β�ڵ�
	LinkNode* getTailItem();
};

