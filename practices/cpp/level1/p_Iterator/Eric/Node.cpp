#include "Node.h"
// Node::~Node()
// {
// 	if(!flagHead)
// 	{
// 		delete this;
// 	}
// }
Node *Node::newNode()
{
	next = new Node();
	return next;
}
void Node::setValue(int va)
{
	value = va;
}
void Node::setNext(Node *nt)
{
	next = nt;
}
Node *Node::showNextNode()
{
	return next;
}
int Node::showValue()
{
	return value;
}