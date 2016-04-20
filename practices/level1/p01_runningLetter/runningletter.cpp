#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int i,j;
	char c;
	scanf("%c",&c);
	while(1)
	{
		j=0;
		while(j<80)
		{
    		for(i=1;i<=j;i++) printf(" ");
    		printf("%c",c);
    		system("cls");
    		j++;
    	}	
    	j=79;
    	while(j>=0)
    	{
    		for(i=1;i<=j;i++) printf(" ");
    		printf("%c",c);
    		system("cls");
    		j--;
    	}	
    }
	return 0;
}

