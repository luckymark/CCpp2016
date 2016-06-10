#include <iostream>	
#include "Node.h"

int main()
{
	Node root(ROOT);
	root.append(100);
	root.append(101);
	root.append(102);
	Node& current = root.showChild();
	current.append(103);
	
	root.printAllValue();
	std::cout << root.countChildNodeNumber() << std::endl;
	
	return 0;
}