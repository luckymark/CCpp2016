// Level1P01_RunningLetter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <math.h>
#include <stdio.h>

int main()
{
	const int SCREEN_WIDE = 80;
	for (int i = 0; i < 2*SCREEN_WIDE; i++)
	{
		for (int j = 0;j < 80 - abs(i - SCREEN_WIDE);j++)
		{
			printf(" ");
		}
		printf("a\n");
		system("cls");
	}
	return 0;
}