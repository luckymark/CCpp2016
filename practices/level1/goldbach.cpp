#include<stdio.h>
int main(){
    int num,i,j,a[100],sign=0;
    for(num=1;num<=100;num++){
    	for(i=2;i<num;i++){
    	    if((num%i!=0)){
		sign++;
	    }
	}
	if(sign==0){
	    a[i-1]=num;
	}
	else{
	    continue;
	}
    }
    for(num=1;num<=100;num++){
	for(i=1;i<=100;i++){
	    for(j=1;j<=100;j++){
		if(a[i]+a[j]==num){
		    sign++;
		}
	    }	
	}
    }
    if(sign==0){
         printf("no");
    }
    else{
	printf("yes");
    }
}

	

