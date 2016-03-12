#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int main()
{
	char s[max+1];
	for (int i = 1; i < max; i++)
		{
			s[i] = ' ';
		}
	s[max] = '\0';
	s[0] = 'a';
	printf("%s", s);
	for (int i = 0; i < max - 1; i++)
	{
		s[i + 1] = s[i];
		s[i] = ' ';
		printf("%s", s);
		system("cls");
	}
	for (int i = max - 1; i > 1; i--)
	{
		s[i - 1] = s[i];
		s[i] = ' ';
		printf("%s", s);
		system("cls");
	}
	system("pause");
}
