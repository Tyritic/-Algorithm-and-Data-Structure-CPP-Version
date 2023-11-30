#include<iostream>
#include<algorithm>
#include"LinkNode.h"
using namespace std;
class LinkList
{
private:
	LinkNode* Head;//ͷ�ڵ�
	LinkNode* Curr;//��ǰ�ڵ�
	LinkNode* Tail;//β�ڵ�
	int Size;
public:
	LinkList();
	bool isEmpty();//�п�
	void BuildListByHeadInsert(int ele);//ͷ�巨����
	void BuildListByTailInsert(int ele);//β�巨����ͬʱ��β�ڵ㴦����ڵ�
	void BackwardInsert(int ele);//	�ڵ�ǰ�ڵ�(λ���м䣩�ĺ�һ���ڵ����һ���½ڵ�
	void ForwardInsert(int ele);//	�ڵ�ǰ�ڵ㣨λ���м䣩��ǰһ���ڵ����һ���½ڵ�
	void BackwardInsertByNode(int ele, LinkNode* Node);//����֪�ڵ�(λ���м䣩�ĺ�һ���ڵ����һ���½ڵ�
	void ForwardInsertByNode(int ele, LinkNode* Node);//����֪�ڵ�(λ���м䣩��ǰһ���ڵ����һ���½ڵ�
	int getSize();//��ȡ��
	void Delete();//ɾ����ǰ�ڵ����һ���ڵ�
	void DeleteByNode(LinkNode* Node);//ɾ����֪�ڵ����һ���ڵ�
	int getCurr();//��ȡ��ǰ�ڵ������
	void SequentialPrint();//˳���ӡ����
	void ReversePrint();//˳���ӡ����
	LinkNode* GetHead();//��ȡͷ�ڵ�
	void Prev();//����ǰ�ڵ����һλ
	int Find(int ele);//��ֵ���ҽڵ�
	int At(int pos);//��λ�ò��ҽڵ�
	void Clear();//���������Ԫ�ص���ɾ��
	void Destory();//��������
	LinkNode* GetElemByPos(int pos);//��λ�ò��ҽڵ�
	LinkNode* GetElemByValue(int ele);//��ֵ���ҽڵ�
	void setTail();//����β�ڵ�
	int CaculateSize();//��������
	int getTail();
};

