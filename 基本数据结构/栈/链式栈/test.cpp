#include"LinkedStack.h"
#include<iostream>
#include<random>
using namespace std;
int main()
{
	LinkedStack Test;
	cout << (Test.isEmpty() ? "Test��Ϊ��" : "Test��Ϊ��") << endl;
	int time;
	cout << "����Ԫ�ظ���Ϊ��";
	cin >> time;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);
	for (int i = 0; i < time; i++)
	{
		cout << "ջ���±�Ϊ��" << Test.getTopIndex() << endl;
		int ele;
		ele = dis(gen);
		//cin >> ele;
		Test.push(ele);
	}
	cout << "ջ���±�Ϊ��" << Test.getTopIndex() << endl;
	cout << endl;
	Test.print();
	cout << endl;
	for (int i = 0; i < time; i++)
	{
		cout << "��" << i << "�γ�ջ��Ԫ��Ϊ" << Test.pop() << endl;
		Test.print();
		cout << "ջ�ĳ���Ϊ��" << Test.getSize() << endl;
		cout << "ջ���±�Ϊ��" << Test.getTopIndex() << endl;
		cout << endl;
	}

}