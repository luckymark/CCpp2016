#include<iostream>
#include<cstdio>
#include<cmath>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<conio.h>
using namespace std;
struct zb{int x;int y;};
	zb aim[110];
char map[30][30],mapx,mapy,myx,myy,step,num;
void printmap();
void oper();
int main()
{
	int a,i,j,n=0;
	bool b=1;
	FILE *fp;
	fp=fopen("map1.txt","r");
	fscanf(fp,"%d %d %d %d\n",&mapx,&mapy,&myx,&myy);
	num=0;
	for(i=1;i<=mapx;i++) fgets(map[i],mapy+2,fp);
    for(i=1;i<=mapx;i++)
    {
    	for(j=0;j<=mapy-1;j++)
    	{    
    	    map[i][j]=map[i][j]-48;
    	    if(map[i][j]==3) 
			{
				num++;
				aim[num].x=i; 
				aim[num].y=j;
			}
		}
	}
	printf("  第一关     \n");
    printmap();
	while(b)
	{
		oper();
		system("cls");
		printf("  第一关     \n");
		printmap();
		b=0;
		n++;
		printf("当前步数：%d\n",n);
		for(i=1;i<=num;i++) 
			if(map[aim[i].x][aim[i].y]!=5)
				b=1;
	}
	printf("You win!");
	fclose(fp);
	return 0;
}
void printmap()
{
	int i,j;
	for(i=1;i<=mapx;i++)
    {
    	for(j=0;j<=mapy-1;j++)
        switch (map[i][j])
        {
        		case 1: {printf("#");break;}
        		case 0: {printf(" ");break;}
        		case 2: {printf("a");break;}
        		case 3: {printf("0");break;}
        		case 4: {printf("%c",12);break;}
        		case 5: {printf("@");break;}
        		case 6: {printf("%c",12);break;}
		}  
		printf("\n");
	}
}
void oper()
{
	int x,y,xx,yy;
	char a,b;
	a=getch();
	b=getch();
	switch(b)
    {
       case 72: {x=myx-1;y=myy;xx=x-1;yy=y;break;}
	   case 80: {x=myx+1;y=myy;xx=x+1;yy=y;break;}
	   case 75: {y=myy-1;x=myx;yy=y-1;xx=x;break;}
	   case 77: {y=myy+1;x=myx;yy=y+1;xx=x;break;}
	}  
    if(map[x][y]!=1)
    {
    	if((map[x][y]==0)||(map[x][y]==3))
    	{
    		if(map[x][y]==0) map[x][y]=4;
    		else map[x][y]=6;
    		if(map[myx][myy]==6) map[myx][myy]=3;
			else map[myx][myy]=0;	
			myx=x;
			myy=y;
        }
		if(((map[x][y]==2)||(map[x][y]==5))&&((map[xx][yy]==0)||(map[xx][yy]==3)))
		{
			if(map[xx][yy]==0) map[xx][yy]=2;
			else map[xx][yy]=5;
			if(map[x][y]==2) map[x][y]=4;
			else map[x][y]=6;
			if(map[myx][myy]==6) map[myx][myy]=3;
			else map[myx][myy]=0;
			myx=x;
			myy=y;
		}
	}
}









