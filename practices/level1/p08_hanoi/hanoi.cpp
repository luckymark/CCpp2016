#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void move(int n,int x,int y,int z);
int main()
{
	int h;
	scanf("%d",&h);
	move(h,'a','b','c');
	return 0;
}
void move(int n,int x,int y,int z)
{
	if(n==1) printf("%c->%c\n",x,z);
	else
	{
		move(n-1,x,z,y);
		printf("%c->%c\n",x,z);
		move(n-1,y,x,z);
	}
}
