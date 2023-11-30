#include"LinkedList.h"
#include<iostream>
#include<random>
using namespace std;
int main()
{
	LinkedList Test;
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
		Test.BuildListByHeadInsert(ele);
	}
	Test.Print();
	cout << endl;
	cout << Test. getTail()<< endl;
	LinkNode* Temp1 = Test.GetElemByPos(5);
	Test.BackwardInsertByNode(10, Temp1);
	Test.Print();
	cout << Test.getTail() << endl;
	LinkNode* Temp2 = Test.GetElemByPos(5);
	Test.DeleteByNode(Temp2);
	Test.Print();
	cout << Test.getTail() << endl;
	
}