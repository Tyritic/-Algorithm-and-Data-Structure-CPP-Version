#include "ArcNode.h"

ArcNode::ArcNode(int v, ArcNode* next,int weight)
{
	this->adjVertex = v;
	this->nextArc = next;
	this->weight = weight;
}

ArcNode::ArcNode()
{
	this->nextArc = NULL;
}

int ArcNode::getAdjVertex()
{
	return this->adjVertex;
}
