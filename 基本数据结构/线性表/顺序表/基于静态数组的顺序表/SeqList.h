#pragma once
#include<iostream>
#include<cstdio>
#define max 40
using namespace std;
class SeqList
{
private:
	int ArrayList[max];
	int curr_position;
	int size;
public:
	SeqList();
	bool isEmpty();//�жϱ��
	bool isFull();//�жϱ���
	void display();//����������
	void insert(int element);//��λ��curr_position�в���Ԫ��
	void insert(int element, int pos);//��λ��pos�в���Ԫ��
	void erase();//ɾ����ǰλ�õ�Ԫ��
	void erase(int pos);//ɾ��λ��pos����Ԫ��
	int getPos();//��ȡ��ǰλ��
	int find(int pos);
	int getSize();
};

