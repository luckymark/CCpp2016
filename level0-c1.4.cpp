#include<stdio.h>
//��2�������У��ҳ������Ǹ���
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
