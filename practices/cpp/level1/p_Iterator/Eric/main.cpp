#include <iostream>

#include "LinkedList.h"


int main()
{
	LinkedList testClass;
	testClass.newNode(111);
	std::cout << testClass.showTailValue() << std::endl;
	testClass.deleteHeadNode();
	return 0;
}