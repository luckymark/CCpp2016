#include<stdio.h>
#include<math.h>
#define Width 78
#include<stdlib.h>
int main(){
	printf("ÊäÈëÒ»¸ö×Ö·ûch£º");
	char ch;
	scanf("%c",&ch);
	int i,j;
	for(i=0;i<=2*Width;i++){
		if(i<=Width){
			for(j=0;j<=i;j++){
				printf(" ");
			}	
		}
		if(i>Width){
			for(j=0;j<=abs(i-2*Width);j++){
				printf(" ");
			}	
		}
		
		printf("%c",ch);
	    system("cls");
	}
	
	
}
