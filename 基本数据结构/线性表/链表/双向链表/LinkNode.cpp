#include "LinkNode.h"

LinkNode::LinkNode(int data)
	:Data(data),Prev(nullptr),Next(nullptr)
{
}

LinkNode::LinkNode()
	:Prev(nullptr),Next(nullptr)
{
}
