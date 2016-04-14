#ifndef NODE_H
#define NODE_H
class Node
{
private:
	int value;
	Node *next = nullptr;
public:
	Node *newNode();
	void setValue(int va);
	void setNext(Node *nt);
	Node *showNextNode();
	int showValue();
};
#endif