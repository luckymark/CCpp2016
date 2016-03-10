//By Eric 2016-03-02
//p03_Diophantus
#include <stdio.h>

inline int pow3(int num)
{
	return num * num * num;
}
int main(void)
{
	for (int count_num = 100; count_num < 1000; count_num++)
	{
		int total = pow3(count_num % 10) + pow3(count_num / 100) + pow3(count_num / 10 - count_num / 100 * 10);
		if (total == count_num)
		{
			printf("%d\n", count_num);
		}
	}

	return 0;
}