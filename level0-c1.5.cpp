#include<stdio.h>
//��3�������У��ҳ������Ǹ���
int main(){
	int i,j,k,max;
	scanf("%d %d %d",&i,&j,&k);
	if((i>j)&&(i>k)){
		max=i;
	}
	if((j>i)&&(j>k)){
		max=j;
	}
	if((k>i)&&(k>j)){
		max=k;
	}
	printf("max=%d",max);
}
