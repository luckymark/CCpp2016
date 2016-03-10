// hanoi.cpp : 定义控制台应用程序的入口点。
//

#include<stdio.h>
#include<stdlib.h>

void hanoi(int n,char a,char b,char c);
int main()
{
	int  n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	system("pause");
}
void hanoi(int n,char a,char b,char c)
{
	if (n!=1){
		hanoi(n-1,a,c,b);
		printf("%c->%c  ",a,c);
		hanoi(n-1,b,a,c);
	}
	else{
		printf("%c->%c  ",a,c);
	}
	return;
}
	   