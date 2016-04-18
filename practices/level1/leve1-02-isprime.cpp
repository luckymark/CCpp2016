#include<stdio.h>
int main(){
    int num,i,sign;
    scanf("%d",&num);
    if(num<=1){
	printf("no");
    }
    else{
	for(i=2;i<num;i++){
            if((num%i!=0)){
		sign++;
	    }
	}
	if(sign==0){
            printf("yes");
	}
	else{
	    printf("no");
	}
    }
}
