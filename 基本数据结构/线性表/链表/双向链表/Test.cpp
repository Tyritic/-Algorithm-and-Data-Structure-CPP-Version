#include"LinkList.h"
#include<iostream>
#include<random>
using namespace std;
int main()
{
	LinkList Test;
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
		cin >> ele;
		Test.BuildListByHeadInsert(ele);
	}
	Test.SequentialPrint();
	cout << endl;
	cout << Test.getTail() << endl;
	LinkNode* Temp = Test.GetElemByPos(4);
	Test.BackwardInsertByNode(10, Temp);
	Test.SequentialPrint();
	cout << Test.getTail() << endl;
	

}