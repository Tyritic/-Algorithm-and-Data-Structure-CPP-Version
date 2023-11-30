#pragma once
#include<iostream>
#include<algorithm>
const int defaultSize = 3;
class SeqList
{
private:
	int Size;//表长
	int* Array;//动态数组
	int Curr;//当前位置的数组下标
	int maxSize;//数组最大长度
public:
	SeqList(int size=defaultSize);
	void Init(int size);//动态数组的初始化
	void reSize(int newSize);//重新设置数组大小
	void Insert(int ele);//在当前位置后插入元素
	void Insert(int ele, int pos); //在指定位置后插入元素
	void Emit();//删除当前位置的元素
	void Emit(int pos);//删除指定位置的元素
	bool isEmpty();//判空
	bool isFull();//判满
	int getMaxSize();//获取表的最大长度
	void Print();//输出表的元素
	int At(int ele);//根据元素查找位置
	int Find(int pos);//根据位置查找元素
	void Append(int ele);//将表向后拓展一位
	int getSize();//获取表长
};

