#ifndef NODE_H
#define NODE_H

#include <vector>

#define ROOT true
#define UN_ROOT false

class Node
{
private:
	Node *parentNode;
	int value;
	std::vector<Node *> childNode;
public:
	Node();
	//head
	Node(Node *parent, int va, bool isRoot = UN_ROOT);
	void append(int va);
	void setValue(int sourceValue);
	int showValue();
	unsigned countChildNodeNumber();
	Node *showParentNode();
#ifdef DEBUG
	void printAllValue();
	//access child Node
	Node &showChild();
#endif
};
#endif
