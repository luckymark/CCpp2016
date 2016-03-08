#include<stdio.h>
#include<stdlib.h>
int main()
{
	for (double i = 0; i < 200.0; i++)
	{
		if (i / 6.0 + i / 12.0 + i / 7.0 + i / 2.0 + 5 + 4 == i)
			printf("%.0lf\n", i);
	}
	system("pause");
}
