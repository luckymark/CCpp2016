#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
	int n=2,j,i;
	clock_t t1,t2;
	t1=clock();
	for (i=2;i<=1000;i++)
	{
		int flag=1;
		for (j=2;j<=sqrt(i);j++)
		{
			if (i%j==0){
				flag=0;
				break;
			}
		}
		if (flag){
			printf("%d\n",i);
		}
	}
	t2=clock();
	printf("The time is: %d ms.\n",t2-t1);
	return 0;
}
