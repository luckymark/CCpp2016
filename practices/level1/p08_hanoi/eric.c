//Eric 2016-03-05
//p08_hanoi
//从左至右 依次为 a b c
#include <stdio.h>
//用于计算另一个柱子
#define TOTAL 'a' + 'b' + 'c'

void move(char base, char destination, int level);

int main(void)
{
	int numLevel;
	printf("输入层数：");
	scanf("%d", &numLevel);
	move('a', 'c', numLevel);

	return 0;
}
void move(char base, char destination, int level)
{
	if (level == 1)
	{
		printf("%c2%c\n", base, destination);
	}
	else
	{
		move(base, TOTAL - base - destination, level - 1);
		printf("%c2%c\n", base, destination);
		move(TOTAL - base - destination, destination, level - 1);
	}
}