#include "Tree.h"
#include <cstdio>
#include <iostream>
int main()
{
	Tree aTree(1, 100);
	aTree.append(1, 2, 3);
	aTree.append(2, 4, 2);
	std::cout << "4's father is " << aTree.getFather(4) << std::endl;
	std::cout << "1 has " << aTree.calSonIndex(1) <<" sons"<< std::endl;
	return 0;
}