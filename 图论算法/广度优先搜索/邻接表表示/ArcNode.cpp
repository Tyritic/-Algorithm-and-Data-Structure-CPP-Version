#include "ArcNode.h"

ArcNode::ArcNode(int v, ArcNode* next)
{
	this->adjVertex = v;
	this->nextArc = next;
}

ArcNode::ArcNode()
{
	this->nextArc = NULL;
}

int ArcNode::getAdjVertex()
{
	return this->adjVertex;
}
