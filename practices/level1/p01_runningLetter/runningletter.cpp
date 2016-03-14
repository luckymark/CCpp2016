#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50
int main()
{
	int i = MAX;
	char s[MAX + 1];//这个真的可以编译的过
	for (int i = 1; i < MAX; i++)
	{
		s[i] = ' ';
	}
	s[MAX] = '\0';
	s[0] = 'a';
	printf("%s", s);
	for (i = -MAX + 2; i < MAX - 2; i++)
	{
		if (abs(i - 1) == 0 || abs(i - 2) == 0)
		{
			continue;
		}
		s[MAX - abs(i - 1) ] = s[MAX - abs(i - 2) ];
		s[MAX - abs(i - 2) ] = ' ';
		printf("%s", s);
		system("cls");
	}
	/*for (int i = max - 2; i > 1; i--)
	{
		s[i - 1] = s[i];
		s[i] = ' ';
		printf("%s", s);
		system("cls");
	}*/
	system("pause");
}