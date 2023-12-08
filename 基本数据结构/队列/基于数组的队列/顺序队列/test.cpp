#include<iostream>
#include<random>
#include"SeqQueue.h"
using namespace std;
int main()
{
	SeqQueue Test;
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
	cout << (Test.isEmpty() ? "Test��Ϊ��" : "Test��Ϊ��") << endl;
}