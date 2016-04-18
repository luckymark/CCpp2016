#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 20
char maze[MAX / 2][MAX] = { "*  * * * * * * * **",
"*  *              *",
"*  *              *",
"*  *              *",
"*  ****************",
"*                 *",
"****************  *",
"*              *  *",
"*              *  *",
"* * * * * * * ** H*" };
void print();
int judge(int i, char m);
int* move(int *pa);
void isVictor(int i, int j);
int main()
{
	int *a;
	int l, r;
	a = (int *)malloc(2 * sizeof(int));
	a[0] = 9;
	a[1] = 17;
	print();
	printf("请输入出口坐标:(按照(,)的格式输出!)\n");
	scanf("(%d,%d)", &l, &r);
	system("cls");
	setbuf(stdin, NULL);
	system("pause");
	print();
	while (1)
	{
		a = move(a);
		system("cls");
		print();
		isVictor(l, r);
		system("pause");
	}
}
void print()
{
	for (int i = 0; i < MAX / 2; i++)
	{
		printf("%s\n", maze[i]);
	}
}
int judge(int i, int j, char m)
{
	switch (m)
	{
	case 'w':
		if ((maze[i - 1][j] == '*') || i == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	case 's':
		if ((maze[i + 1][j] == '*') || i == 9)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	case 'a':
		if ((maze[i][j - 1] == '*') || j == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	case 'd':
		if ((maze[i][j + 1] == '*') || j == 19)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
int* move(int *pa)
{
	char n, middle;
	n = getch();
	if (judge(pa[0], pa[1], n))
	{
		switch (n)
		{
		case 'w':
			middle = maze[pa[0] - 1][pa[1]];
			maze[pa[0] - 1][pa[1]] = maze[pa[0]][pa[1]];
			maze[pa[0]][pa[1]] = middle;
			pa[0]--;
			break;
		case 's':
			middle = maze[pa[0] + 1][pa[1]];
			maze[pa[0] + 1][pa[1]] = maze[pa[0]][pa[1]];
			maze[pa[0]][pa[1]] = middle;
			pa[0]++;
			break;
		case 'a':
			middle = maze[pa[0]][pa[1] - 1];
			maze[pa[0]][pa[1] - 1] = maze[pa[0]][pa[1]];
			maze[pa[0]][pa[1]] = middle;
			pa[1]--;
			break;
		case 'd':
			middle = maze[pa[0]][pa[1] + 1];
			maze[pa[0]][pa[1] + 1] = maze[pa[0]][pa[1]];
			maze[pa[0]][pa[1]] = middle;
			pa[1]++;
			break;
		default:
			setbuf(stdin, NULL);
		}
	}
	return pa;
}
void isVictor(int i, int j)
{
	if (maze[i - 1][j - 1] == 'H')
	{
		printf("VICTOR!!\n");
		system("pause");
		exit(0);
	}
}