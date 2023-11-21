#include "Graph.h"

Graph::Graph(int numVer,int numArc)
	:numArc(numArc),numVer(numVer)
{
	vertices = new VertexNode[numVer];
	visited = new bool[numVer];
	for (int i = 0; i < numVer; i++)
		visited[i] = false;
	inDegree = new int[numVer];
}

void Graph::initVertex()
{
	cout << "���붥������" << endl;
	for (int i = 0; i < numVer; i++)
	{
		cout << "vertex" << i << "��" ;
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

void Graph::addEdge(int from, int to,int weight)
{
		ArcNode* temp = new ArcNode;
		temp->adjVertex = to;//���߱���ָ��Ķ����ڶ��㼯�е�λ����Ϊto
		temp->nextArc= vertices[from].firstArc;//���߱�ڵ�ָ����һ�����ı߱�ڵ�Ͷ��㼯���±�Ϊfrom�Ķ�������
		temp->weight = weight;
		vertices[from].firstArc = temp;//����ʼ����������ĵ�һ�������±�����
		inDegree[to]++;
		numArc++;
}

void Graph::printLink(ArcNode* next)
{
	while (next != NULL)
	{
		cout << vertices[next->adjVertex].data << " ";//����߱�ڵ�ָ�򶥵��ڶ��㼯�е�λ�ö�Ӧ�Ķ�������
		next = next->nextArc;
	}
	cout << endl;
}

void Graph::display()
{
	cout << "�ڽӱ�Ϊ��" << endl;
	for (int i = 0; i < numVer; i++)
	{
		cout << "vertex" << i << "��";
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

void Graph::addEdge(string from, string to,int weight)
{
	
		ArcNode* temp = new ArcNode;
		temp->adjVertex = getVertex(to);
		temp->nextArc = vertices[getVertex(from)].firstArc;
		temp->weight = weight;
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
		return -1; // ����-1��ʾ���ڽӵ�
	}
}

int Graph::NextNeighbor(int v, int w)
{
	ArcNode* p = vertices[v].firstArc;
	while (p != NULL && p->adjVertex == w) 
	{
		p = p->nextArc; // ����w
	}
	if (p != NULL) 
	{
		return p->adjVertex; // ������һ���ڽӵ�
	}
	else 
	{
		return -1; // û����һ���ڽӵ���
	}
}

void Graph::BFS(int v)
{
	cout << vertices[v].data << endl;
	visited[v] = true;
	queue <int>Q;
	Q.push(v);//����ʼ�������
	while (!Q.empty())
	{
		int u = Q.front();
		if (!visited[u])//����ͷ����δ������
		{
			cout <<vertices[u].data << endl;
			visited[u] = true;
		}
		Q.pop();//��ͷ�������
		ArcNode* temp = vertices[u].firstArc;//��tempΪ��ͷ����ĵ�һ����
		while (temp != NULL)
		{
			Q.push(temp->adjVertex);//����ָ��Ķ������
			temp=temp->nextArc;//������
		}
		
	}

}

void Graph::DFS(int v)
{
	if (visited[v])//����ý���Ѿ��������򷵻� 
		return;
	cout << vertices[v].data<< endl;
	visited[v] = true;
	ArcNode* temp = vertices[v].firstArc;//��tempΪ��ͷ����ĵ�һ����
	while (temp)
	{
		DFS(temp->adjVertex);
		temp = temp->nextArc;//������
	}
}

void Graph::Dijkstra(int v)
{
	int* distance = new int[numArc];
	for (int i = 0; i < numVer; i++)
		distance[i] = INFINITY;
	for (int i = 0; i < numVer; i++)
	{
		visited[i] = false;
	}
	distance[v] = 0;
	for (int i = 0; i < numVer; i++)
	{
		int j=0;
		for (int k = 0; k < numVer; k++)
		{
			if (!visited[k] && distance[k] <= distance[j])
			{
				j = k;
			}
		}
		visited[j] = true;
		ArcNode* temp = vertices[j].firstArc;//��tempΪ��ͷ����ĵ�һ����
		while (temp != NULL)
		{
			distance[temp->adjVertex] = min(distance[temp->adjVertex], distance[j] + temp->weight);
			temp = temp->nextArc;//������
		}
	}
	for (int i = 0; i < numVer; i++)
	{
		cout << distance[i] << endl;
	}
}

bool Graph::TopologicalSort()
{
	stack<int>q;
	for (int i = 0; i < numVer; i++)
	{
		if (inDegree[i] == 0)//������Ϊ0��ѹ��ջ��
			q.push(i);
	}
	int count = 0;//��¼����Ķ�����
	while (!q.empty())
	{
		int p = q.top();//ջ��Ԫ��
		q.pop();
		cout << vertices[p].data << endl;
		count++;
		ArcNode* temp = vertices[p].firstArc;//��tempΪջ������ĵ�һ����
		while (temp != NULL)//�������к�ջ��Ԫ�������Ķ���
		{
			inDegree[temp->adjVertex]--;//��ȼ�һ
			if (!inDegree[temp->adjVertex])//������Ϊ0��ѹ��ջ��
				q.push(temp->adjVertex);
			temp = temp->nextArc;//������
		}	
	}
	if (count < numVer)return false;//��һ�α�����������ڻ�
	return true;
}

