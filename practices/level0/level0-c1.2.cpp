#include<stdio.h>
//�ж�һ�����Ƿ���13�ı��� 
main(){
	int num,i;
	scanf("%d",&num);
	i=num%13;
	if(i==0){
		printf("yes");
	}
	else
	printf("no");
}
