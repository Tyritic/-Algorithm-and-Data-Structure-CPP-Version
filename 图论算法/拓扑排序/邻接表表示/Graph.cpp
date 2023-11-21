#include "Graph.h"

Graph::Graph(int numVer)
	:numVer(numVer),numArc(0)
{
	vertices = new VertexNode[numVer];
	visited = new bool[numVer];
	for (int i = 0; i < numVer; i++)
		visited[i] = false;
	inDegree = new int[numVer];
}

void Graph::initVertex()
{
	cout << "输入顶点数据" << endl;
	for (int i = 0; i < numVer; i++)
	{
		cout << "vertex" << i << "：" ;
		string data;
		cin >> data;
		VertexNode temp(data);
		vertices[i] = temp;
	}
	for (int i = 0; i < numVer; i++)
	{
		inDegree[i] = 0;
	}
}

void Graph::addEdge(int from, int to)
{
		ArcNode* temp = new ArcNode;
		temp->adjVertex = to;//将边表结点指向的顶点在顶点集中的位置设为to
		temp->nextArc= vertices[from].firstArc;//将边表节点指向下一条弧的边表节点和顶点集中下标为from的顶点相连
		vertices[from].firstArc = temp;//将起始顶点的依附的第一条弧和新边相连
		inDegree[to]++;
		numArc++;
}

void Graph::printLink(ArcNode* next)
{
	while (next != NULL)
	{
		cout << vertices[next->adjVertex].data << " ";//输出边表节点指向顶点在顶点集中的位置对应的顶点数据
		next = next->nextArc;
	}
	cout << endl;
}

void Graph::display()
{
	cout << "邻接表为：" << endl;
	for (int i = 0; i < numVer; i++)
	{
		cout << "vertex" << i << "：";
		cout << vertices[i].data << " ";
		printLink(vertices[i].firstArc);
	}
}

void Graph::getNeighbors(int v)
{
	printLink(vertices[v].firstArc);
}

int Graph::getVertex(string data)
{
	for (int i = 0; i < numVer; i++)
	{
		if (vertices[i].data == data)
			return i;
	}
}

void Graph::addEdge(string from, string to)
{
	
		ArcNode* temp = new ArcNode;
		temp->adjVertex = getVertex(to);
		temp->nextArc = vertices[getVertex(from)].firstArc;
		vertices[getVertex(from)].firstArc = temp;
		inDegree[getVertex(to)]++;
		numArc++;
}

int Graph::FirstNeighbor(int v)
{
	ArcNode* p = vertices[v].firstArc;
	if (p != NULL) 
	{
		return p->adjVertex;
	}
	else 
	{
		return -1; // 返回-1表示无邻接点
	}
}

int Graph::NextNeighbor(int v, int w)
{
	ArcNode* p = vertices[v].firstArc;
	while (p != NULL && p->adjVertex == w) 
	{
		p = p->nextArc; // 跳过w
	}
	if (p != NULL) 
	{
		return p->adjVertex; // 返回下一个邻接点
	}
	else 
	{
		return -1; // 没有下一个邻接点了
	}
}


bool Graph::TopologicalSort()
{
	stack<int>q;
	for (int i = 0; i < numVer; i++)
	{
		if (inDegree[i] == 0)//如果入度为0则压入栈中
			q.push(i);
	}
	int count = 0;//记录输出的顶点数
	while (!q.empty())
	{
		int p = q.top();//栈顶元素
		q.pop();
		cout << vertices[p].data << endl;
		count++;
		ArcNode* temp = vertices[p].firstArc;//设temp为栈顶顶点的第一条弧
		while (temp != NULL)//遍历所有和栈顶元素相连的顶点
		{
			inDegree[temp->adjVertex]--;//入度减一
			if (!inDegree[temp->adjVertex])//如果入度为0则压入栈中
				q.push(temp->adjVertex);
			temp = temp->nextArc;//向后遍历
		}	
	}
	if (count < numVer)return false;//若一次遍历不完则存在环
	return true;
}

