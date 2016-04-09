#include<iostream>
#include<cstdio>
#include<Windows.h>

using namespace std;

void hanoi(int i, char start, char mid, char end);

int main()
{
	int i;
	cin >> i;
	hanoi(i,'A','B','C');
	Sleep(100000);
	return 0;
}

void hanoi(int i,char start,char mid,char end)
{
	if (i != 1)
	{
		hanoi(i - 1, start, end, mid);
		cout << "move " << i << " from " << start << " to " << end << endl;
		hanoi(i - 1, mid, start, end);
	}
	else
	{
		cout << "move " << i << " from " << start << " to " << end << endl;
	}
}