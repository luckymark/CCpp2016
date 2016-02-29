#include<stdio.h>
int main(){
	for(int i = 100;i<1000;i++){
		int x = i/100;
		int y = (i%100)/10;
		int z = i%10;
		if(i==x*x*x+y*y*y+z*z*z){
			printf("%d\n",i);
		}
	}
}
