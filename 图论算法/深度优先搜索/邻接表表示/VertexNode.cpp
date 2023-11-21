#include "VertexNode.h"

VertexNode::VertexNode(string data)
{
	this->data = data;
	firstArc = NULL;
}

VertexNode::VertexNode()
{
	this->firstArc = NULL;
}
