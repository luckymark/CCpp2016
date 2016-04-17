#include "Node.h"

#include <iostream>

Node::Node(bool isRoot)
{
	parentNode = nullptr;
}
Node::Node(Node *parent, int va, bool isRoot)
{
	parentNode = parent;
	value = va;
}
void Node::append(int va)
{
	auto temp = new Node(this, va);
	childNode.push_back(temp);
}
void Node::setValue(int sourceValue)
{
	value = sourceValue;
}
unsigned Node::countChildNodeNumber()
{
	unsigned total = 1;
	for(auto it = childNode.begin(); it != childNode.end(); it++)
	{
		total += (*it)->countChildNodeNumber();
	}
	if (parentNode == nullptr)
	{
		return total - 1;
	}
	else
	{
		return total;
	}
}
Node *Node::showParentNode()
{
	return parentNode;
}

#ifdef DEBUG
#include <iostream>
void Node::printAllValue()
{
	for(auto it = childNode.begin(); it != childNode.end(); it++)
	{
		(*it)->printAllValue();
	}
	if(parentNode != nullptr)
	{
		std::cout << value << std::endl;
	}
}
Node &Node::showChild()
{
	if(childNode.begin() != childNode.end())
	{
		return *childNode[0];
	}
	else
	{
		return *this;
		
	}
}
#endif