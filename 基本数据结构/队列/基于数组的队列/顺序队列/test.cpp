#include<iostream>
#include<random>
#include"SeqQueue.h"
using namespace std;
int main()
{
	SeqQueue Test;
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
		ele = dis(gen);
		cout << ele << endl;
		//cin >> ele;
		Test.EnQueue(ele);
	}
	cout << endl;
	Test.display();
	cout << endl;
	for (int i = 0; i < time; i++)
	{
		cout<<Test.DeQueue()<<endl;
	}
	cout << endl;
	Test.display();
	cout << (Test.isEmpty() ? "Test表为空" : "Test表不为空") << endl;
}