#include<stdio.h>
//��2�������У��ҳ������Ǹ���
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
