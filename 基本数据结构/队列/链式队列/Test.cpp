#include"LinkedQueue.h"
#include<iostream>
#include<random>
using namespace std;
int main()
{
	LinkedQueue Test;
	cout << (Test.isEmpty() ? "Test��Ϊ��" : "Test��Ϊ��") << endl;
	int time;
	cout << "����Ԫ�ظ���Ϊ��";
	cin >> time;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);
	for (int i = 0; i < time; i++)
	{
		int ele;
		//ele = dis(gen);
		cin >> ele;
		Test.EnQueue(ele);
	}
	cout << endl;
	Test.display();
	cout << endl;
	cout << "��ͷԪ�أ�" << Test.getFront() << endl;
	cout << "��βԪ�أ�" << Test.getRear();
	cout << endl;
	for (int i = 0; i < time; i++)
	{
		Test.DeQueue();
		Test.display();
		cout << endl;
		cout << "��ͷԪ�أ�" << Test.getFront() << endl;
		cout << endl;
	}
}