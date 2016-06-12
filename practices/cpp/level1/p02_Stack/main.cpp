#include<iostream>
#include"stack.h"

using namespace std;

int main()
{
	cout << "Please input the length of the stack.(<=100)" << endl;
	int x;
	cin >> x;
	system("cls");
	Stack stack(x);
	for (size_t i = 0; i < x; i++)
	{
		if (!stack.isFull())
		{
			stack.push(i);
		}
		else
		{
			break;
		}
	}
	int n;
	for (size_t i = 0; i < x; i++)
	{
		if (!stack.isEmpty())
		{
			n = stack.pop();
			cout << n << endl;
		}
	}
	system("pause");
	return 0;
}