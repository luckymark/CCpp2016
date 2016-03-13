#include<stdio.h>
//判断一个数是否是13的倍数 
int main(){
	int num,i;
	scanf("%d",&num);
	i=num%13;
	if(i==0){
		printf("yes");
	}
	else{
		printf("no");
	}
}
