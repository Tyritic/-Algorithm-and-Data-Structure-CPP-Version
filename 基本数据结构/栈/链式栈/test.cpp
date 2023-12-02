#include"LinkedStack.h"
#include<iostream>
#include<random>
using namespace std;
int main()
{
	LinkedStack Test;
	cout << (Test.isEmpty() ? "Test表为空" : "Test表不为空") << endl;
	int time;
	cout << "输入元素个数为：";
	cin >> time;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);
	for (int i = 0; i < time; i++)
	{
		cout << "栈顶下标为：" << Test.getTopIndex() << endl;
		int ele;
		ele = dis(gen);
		//cin >> ele;
		Test.push(ele);
	}
	cout << "栈顶下标为：" << Test.getTopIndex() << endl;
	cout << endl;
	Test.print();
	cout << endl;
	for (int i = 0; i < time; i++)
	{
		cout << "第" << i << "次出栈的元素为" << Test.pop() << endl;
		Test.print();
		cout << "栈的长度为：" << Test.getSize() << endl;
		cout << "栈顶下标为：" << Test.getTopIndex() << endl;
		cout << endl;
	}

}