#include<iostream>
#include"Graph.h"
using namespace std;
int main()
{
	Graph test(5);
	test.initVertex();
	test.addEdge(0, 1);
	test.addEdge(0, 3);
	test.addEdge(1, 3);
	test.addEdge(1, 2);
	test.addEdge(2, 4);
	test.addEdge(3, 2);
	test.addEdge(3, 4);
	test.display();
	cout << endl;
	//for (int i = 0; i < test.numVer; i++)
		//cout << test.inDegree[i] << endl;
	test.DFS(0);
	
}
