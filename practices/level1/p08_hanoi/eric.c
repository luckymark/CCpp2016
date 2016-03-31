//Eric 2016-03-05
//p08_hanoi
//从左至右 依次为 a b c
#include <stdio.h>

void move(char base, char destination, int level);
//返回另一个柱子
char anotherBar(char bar1, char bar2);

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
		move(base, anotherBar(base, destination), level - 1);
		printf("%c2%c\n", base, destination);
		move(anotherBar(base, destination), destination, level - 1);
	}
}
//返回另一个柱子
char anotherBar(char bar1, char bar2)
{
   return TOTAL - bar1 - bar2;
}