#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const char s[]="display";
const int MAX=70;
const int dur=50;
int main()
{
	int i,j;
	while(1)
	{
		for(i=1;i<MAX;i++)
		{
			system("cls");
			for(j=1;j<i;j++)
				printf(" ");
			printf("%s",s);
			Sleep(dur);
		}
		for(i=MAX;i>0;i--)
		{
			system("cls");
			for(j=1;j<i;j++)
				printf(" ");
			printf("%s",s);
			Sleep(dur);
		}
	}
	return 0;
}