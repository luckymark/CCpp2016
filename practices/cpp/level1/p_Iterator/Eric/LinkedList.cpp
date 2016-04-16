#include <iostream>
#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node;
	tail = head;
}
void LinkedList::newNode(int va)
{
	auto temp = new Node;
	tail->setNext(temp);
	tail = temp;
	tail->setValue(va);
}
int LinkedList::showHeadValue()
{
	return head->showValue();
}
#ifdef _DEBUG
int LinkedList::showTailValue()
{
	return tail->showValue();
}
#endif
void LinkedList::deleteHeadNode()
{
	if(head == nullptr)
	{
		std::cerr << "No Node!!" << std::endl;
		return;
	}
	auto temp = head;
	head = head->showNextNode();
	delete head;
}