#include<iostream>
#include"queue.h"

using namespace std;

int main()
{
	Queue queue;
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
	int n;
	for (size_t i = 0; i < 100; i++)
	{
		if (!queue.isEmpty())
		{
			n = queue.pop();
		}
		cout << n << endl;
	}
	system("pause");
	return 0;
}