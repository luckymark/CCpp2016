#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
char *encrypt(char *c);
char *decrypt(char *c);
int main()//√‹¬Î3965317 
{
    char word[10010],*jmword;
	gets(word);
	jmword=encrypt(word);
	puts(jmword);
	puts(decrypt(jmword));
	return 0;
}
char *encrypt(char *c)
{
	int i;
	char m[10010];
    for(i=0;i<=strlen(c);i++)
    {
    	switch(i%7) 
    	{
    		case 0: {m[i]=c[i]+3;break;}
    		case 1: {m[i]=c[i]+9;break;}
    		case 2: {m[i]=c[i]+6;break;}
    		case 3: {m[i]=c[i]+5;break;}
    		case 4: {m[i]=c[i]+3;break;}
    		case 5: {m[i]=c[i]+1;break;}
    		case 6: {m[i]=c[i]+7;break;}
		}
	}
	return m;
}
char *decrypt(char *c)
{
	int i;
	char m[10010];
    for(i=0;i<=strlen(c);i++)
    {
    	switch(i%7) 
    	{
    		case 0: {m[i]=c[i]-3;break;}
    		case 1: {m[i]=c[i]-9;break;}
    		case 2: {m[i]=c[i]-6;break;}
    		case 3: {m[i]=c[i]-5;break;}
    		case 4: {m[i]=c[i]-3;break;}
    		case 5: {m[i]=c[i]-1;break;}
    		case 6: {m[i]=c[i]-7;break;}
		}
	}
	return m;
}
