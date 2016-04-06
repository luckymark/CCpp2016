#include<stdio.h>
//从2个整数中，找出最大的那个数
main(){
	int i,j,max;
	scanf("%d %d",&i,&j);
	if(i>j){
		max=i;
	}
	if(i<j){
		max=j;
	}
	if(i==j){
		printf("i=j");
	}
	printf("max=%d",max);
}
