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
	bool isEmpty();//判断表空
	bool isFull();//判断表满
	void display();//输出表的数据
	void insert(int element);//在位置curr_position中插入元素
	void insert(int element, int pos);//在位置pos中插入元素
	void erase();//删除当前位置的元素
	void erase(int pos);//删除位置pos处的元素
	int getPos();//获取当前位置
	int find(int pos);
	int getSize();
};

