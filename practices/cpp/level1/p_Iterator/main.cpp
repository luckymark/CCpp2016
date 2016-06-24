#include<iostream>
#include"queue.h"
#include"Iterator.h"

using namespace std;

int main()
{
	Queue queue;
	Iterator iterator;

	for (size_t i = 0; i < 100; i++)
	{
		if (!queue.isFull())
		{
			queue.append(i);
		}
		else
		{
			break;
		}
	}

	iterator.traverse<Queue>(queue);

	system("pause");
	return 0;
}