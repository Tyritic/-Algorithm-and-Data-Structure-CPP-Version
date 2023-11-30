#include<iostream>
#include"SeqList.h"
#include<random>
using namespace std;
int main()
{
	SeqList test;
	cout << (test.isEmpty() ? "test表为空" : "test表不为空") << endl;
	cout << "test表的最大表长为：" << test.getMaxSize() << endl;
	test.reSize(5);
	cout << "test表的最大表长为：" << test.getMaxSize() << endl;
	int time;
	cout << "输入元素个数为：";
	cin >> time;
	test.reSize(time + 5);
        random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);//生成1-10的随机数
	for (int i = 0; i < time; i++)
	{
		int ele ;
		ele=dis(gen);
		test.Insert(ele, i);
	}
	test.Print();
	int pos;
	cout << "输入删除元素位置为：";
	cin >> pos;
	test.Emit(pos);
	test.Print();
	int ele ;
	cout << "输入查找元素为：";
	cin >> ele;
	cout << "元素位置为" << test.At(ele) << endl;
	cout << "输入查找元素位置为：";
	cin >> pos;
	cout << "元素为" << test.Find(pos) << endl;
	cout << "插入元素为";
	cin >> ele;
	test.Append(ele);
	test.Print();


}
