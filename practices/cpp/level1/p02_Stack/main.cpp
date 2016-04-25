#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	int n;
	cin >> n;
	Stack stack(n, 0);
	if (!stack.isFull(n))
	{
		stack.push(100);
	}
	if (!stack.isEmpty())
	{
		n=stack.pop();
	}
}