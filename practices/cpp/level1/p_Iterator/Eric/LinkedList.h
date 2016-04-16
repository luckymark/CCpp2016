#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
	Node *head;
	Node *tail;
public:
	LinkedList();
	void newNode(int va);
	int showHeadValue();
#ifdef _DEBUG
	int showTailValue();
#endif
	void deleteHeadNode();
};
#endif