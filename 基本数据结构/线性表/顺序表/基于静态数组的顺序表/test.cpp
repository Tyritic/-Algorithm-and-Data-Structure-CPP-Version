#include<iostream>
using namespace std;
#include<random>
#include"SeqList.h"
int main()
{
	SeqList test;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);
	int time;
	cin >> time;
	for (int i = 0; i < time; i++)
	{
		int ele;
		ele = dis(gen);
		//cin >> ele;
		test.insert(ele);
	}
	cout << "表中元素为：" << endl;
	test.display();
	cout << endl;
	cout << "表的大小为：" << test.getSize() << endl;
	test.erase(9);
	test.display();
}
