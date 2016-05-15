#include<iostream>
#include<cstdio>
#include<cmath>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<conio.h>
using namespace std;
int map[35][35],way[35][35],len,myx,myy;
const int fx[5]={-1,0,1,0};
const int fy[5]={0,1,0,-1};
struct zb{int x;int y;int s;};
  zb route[50000];
void buildmaze();
void bfsmap();
void printmaze();
void oper();
int main()
{
    len=10000;
    buildmaze();  //�Զ������Թ� 
    bfsmap();
    while(len==10000) {buildmaze(); bfsmap();}  //�������Թ����м��� 
    printmaze();
    myx=1; myy=1;
    while((myx!=30)||(myy!=30))
    {
    	oper();  //���뷽��� 
    	system("cls");
    	printmaze();
	}
	printf("You win!");
    return 0;
} 		  
void buildmaze()
{
	int k;
	srand(time(0));
	for(int i=1;i<=30;i++)
		for(int j=1;j<=30;j++)
	    {
	    	k=rand()%3;
	        if((k==0)||(k==2)) map[i][j]=0;
	        else map[i][j]=1;
	    }
	map[1][1]=3;
	map[30][30]=4;
}
void bfsmap()
{
     int i,j,x,y,head,tail;   
     memset(way,0,sizeof(way));       
     memset(route,0,sizeof(route)); 

     head=0;
     tail=1;
     route[tail].x=1;
     route[tail].y=1; 
     route[tail].s=1; 
     way[1][1]=1;        
     while (head<tail)    
     {               
    	head++;
        for (i=0;i<=3;i++)  
        {
        	x=route[head].x+fx[i]; 
            y=route[head].y+fy[i];
            if ((x>=1&&x<=30)&&(y>=1&&y<=30)&&((map[x][y]==0)||(map[x][y]==4))&&(way[x][y]==0))	
            {		                                          
            	tail++;
            	route[tail].x=x;
                route[tail].y=y; 
                route[tail].s=route[head].s+1;      
                way[x][y]=1;
                if ((x==30) && (y==30))     
                {
                	len=route[tail].s;
                    return;
                }
           }
       }
     }
}
void printmaze()
{
	int i,j;
	for(i=0;i<=31;i++)
	{
	    for(j=0;j<=31;j++)
	    {
	       if((i==0)||(i==31)||(j==0)||(j==31)) {printf("#");continue;}
           switch (map[i][j])
           {
        		case 1: {printf("#");break;}
        		case 0: {printf(" ");break;}
        		case 3: {printf("O");break;}
        		case 4: {printf("E");break;}
		   }  
	    }
	    printf("\n");
    }
}
void oper()
{
	int x,y;
	char a,b;
	a=getch();
	b=getch();
	switch(b)
    {
       case 72: {x=myx-1;y=myy;break;}
	   case 80: {x=myx+1;y=myy;break;}
	   case 75: {y=myy-1;x=myx;break;}
	   case 77: {y=myy+1;x=myx;break;}
	}  
	if((x>=1&&x<=30)&&(y>=1&&y<=30)&&((map[x][y]==0)||(map[x][y]==4))) 
	{
	   map[x][y]=3;
	   map[myx][myy]=0;
	   myx=x;
	   myy=y;
	   b=1;
    }
}
