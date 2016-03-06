#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,temp=1;
	printf("enter an positive integer: ");
	scanf("%d",&n);
	if (n==1){
		printf("None!\n");
		return 0;
	}
	for (i=2;i<=sqrt(n);i++)
	{	
		if (n%i==0){
			temp=0;
			break;
		}
	}
	if (temp){
		printf("Yes!\n");
	}
	else{
		printf("No!\n");
	}
	return 0;
}