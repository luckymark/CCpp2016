#include<stdio.h>
#include<math.h>
int main()
{
	for (int kidage=1;kidage<=100;kidage++)
	{
		float temp=kidage;
		if (fabs(2*temp/6+2*temp/12+2*temp/7+9-temp)<0.0001){
			printf("The age is: %d\n",2*kidage-4);
			break;
		}
	}
	return 0;
}