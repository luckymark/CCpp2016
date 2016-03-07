#include <windows.h>
#include <stdio.h>
#define WIDTH 58
#define SLEEPTIME 100
inline int abs(int num)
{
	return num>0?num:-num;
}

int main(int argc, char const *argv[]) 
{
	for(int i=-WIDTH;i<=WIDTH;i++)
	{
		int length=WIDTH-abs(i);
		for(int j=0;j<length;j++)
		{
			printf(" ");
		}
		printf("A");
		Sleep(SLEEPTIME);
		system("cls");
	}
	return 0;
}
