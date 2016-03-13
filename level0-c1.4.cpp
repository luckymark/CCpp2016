#include<stdio.h>
//从2个整数中，找出最大的那个数
int main(){
	int i,j;
	scanf("%d %d",&i,&j);
	if(i>j){
		printf("max=%d",i);
	}
	if(i==j){
		printf("i=j");
	}
	else{
		printf("max=%d",j);
	}
	
}
