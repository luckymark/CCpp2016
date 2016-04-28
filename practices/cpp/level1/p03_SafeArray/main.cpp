#include<iostream>
#include"safeArray.h"
using namespace std;
int main()
{
	int n, s, p;
	cin >> n >> s;
	SafeArray safeArray(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		if (safeArray.judge(i, n))
		{
			safeArray.set(p, i);
		}
	}
	if (safeArray.judge(s, n))
	{
		safeArray.get(s);
	}
}