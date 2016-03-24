#include<stdio.h>
#include<time.h>
int main()
{
	int q, t;
	q = clock();
	int i;
	int a, b=0, c;
	for ( i = 2; i < 1000; i++)
	{
		if (i==2||i==3)
		{
			printf("%d ", i);
		}
		else
		{
			for ( a = 2; a * a <= i ; a++)
			{
				if (i%a == 0) {
					b = 0;
					break;
				}
				else
				{
					b = 1;
				}
			}
			if (b==1)
			{
				printf("%d ", i);
			}
		}
	}
	t = clock();
	printf("%d ms", t - q);
	getchar();
	return 0;
}