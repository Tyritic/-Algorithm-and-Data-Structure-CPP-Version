#include"LinkedQueue.h"
#include<iostream>
#include<random>
using namespace std;
int main()
{
	LinkedQueue Test;
	cout << (Test.isEmpty() ? "Test表为空" : "Test表不为空") << endl;
	int time;
	cout << "输入元素个数为：";
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
	cout << "队头元素：" << Test.getFront() << endl;
	cout << "队尾元素：" << Test.getRear();
	cout << endl;
	for (int i = 0; i < time; i++)
	{
		Test.DeQueue();
		Test.display();
		cout << endl;
		cout << "队头元素：" << Test.getFront() << endl;
		cout << endl;
	}
}