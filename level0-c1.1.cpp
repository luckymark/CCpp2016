#include<stdio.h>
#include<math.h>
//判断数的正负、判断是否为偶数
int main(){
	int num,i;
	scanf("%d",&num);
	if(num==0){
		printf("=0,yes");
	}
	if(num>0){
		printf(">0 \n");
		i=num%2;
		if(i==0){
		printf("yes");
		}
		else
		printf("no");
	}
	if(num<0){	
		printf("<0\n");
		if(abs(num)%2==0){
			printf("yes");
		}
		else
	printf("no");
	}
	
}
