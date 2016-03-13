#include<stdio.h>
main(){
	int num,i,j,k;

	for(num=100;num<=999;num++){
		i=num% 10;
		j=((num-i)/10)%10;
		k=(num-i-10*j)/100;
		if(num==i*i*i+j*j*j+k*k*k){
			printf("%d \n",num);
		}
		
	}
}
