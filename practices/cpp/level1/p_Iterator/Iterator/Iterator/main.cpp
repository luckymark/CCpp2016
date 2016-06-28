#include <iostream>
#include "Iterator.h"
#include "Queue.h"
int main()
{
	Queue<int> que(3);
	que.push(1);
	que.push(2);
	que.push(3);
	Iterator<int>* it = que.creatIterator();
	for (it->first();!it->isDone();it->next())
		std::cout << it->currentItem() << std::endl;
	return 0;
}