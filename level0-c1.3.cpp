#include<stdio.h>
//�ж�����
int main(){
	int year,i;
	scanf("%d",&year);
	if(((year%4)==0&&(year%100)!=0)||(year%400==0)){
		printf("yes");}
	else
	printf("no");
}
