#include <cstdio>
#include <windows.h>
using namespace std;
const char s[]="display";
#define MAX 70
#define DUR 50
int main()
{
	while(1)
	{
		for(int i=1;i<MAX*2;i++)
		{
			system("cls");
			for(int j=1;j<(i<MAX?i:2*MAX-i);j++)
			{
				printf(" ");
			}
			printf("%s",s);
			Sleep(DUR);
		}
	}
	return 0;
}
