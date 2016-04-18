#include<stdio.h>
#include <time.h>

int main(){
    int i,j,k;
    clock_t start, end;
    start = clock();
    for(i=2;i<=1000;i++){
	int sign=0;
	for(j=2;j<i;j++){
           k=i%j;
	    if(k==0){
		     sign++;
	    }
	    else{
	        break;
	    }
        }
	if(sign==0){
	    printf("%d \n",i);
	}
    }
    end = clock();
    printf("The time was: %f s\n", (double)(end - start) / CLK_TCK);
}
