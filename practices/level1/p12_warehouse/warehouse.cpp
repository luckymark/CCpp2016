#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
struct zb
{
	char type[110];
	int num;
};
zb goods[10010];
int n;
FILE *fp;
void show();
void in();
void out();
void save();
int main()
{
	int i,order;
    fp=fopen("store.txt","r");
    fscanf(fp,"%d\n",&n);
    for(i=1;i<=n;i++)
    {
    	fscanf(fp,"%s %d\n",goods[i].type,&goods[i].num);
	}
	while(1)
	{
		scanf("%d",&order);
		switch (order)
        {
        		case 2: {show(); break;}
        		case 3: {in();   break;}
        		case 4: {out();  break;}
        		case 5: {save(); exit(0);}
		}  
	}
	return 0;
}
void show()
{
	for(int i=1;i<=n;i++)
	{
		printf("%s %d\n",goods[i].type,goods[i].num); 
	}
}
void in()
{
	char type[110];
	int num;
	scanf("%s %d",type,&num);
	for(int i=1;i<=n;i++)
	{
		if(strcmp(type,goods[i].type)==0) 
		{
			goods[i].num+=num;
			return;
		}
	}
	n++;
	strcpy(goods[n].type,type); 
	goods[n].num=num;
	return;
}
void out()
{
	char type[110];
	int num;
	scanf("%s %d",type,&num);
	for(int i=1;i<=n;i++)
	{
		if(strcmp(type,goods[i].type)==0) 
		{
			if(num<=goods[i].num) goods[i].num-=num;
			else printf("Error! We do not have enough this goods!");
			return;
		}
	}
	printf("Error! We do not have enough this goods!");
	return;
}
void save()
{
	fclose(fp);
    fp=fopen("store.txt","w");
    fprintf(fp,"%d\n",n);
    for(int i=1;i<=n;i++)
    {
    	fprintf(fp,"%s %d\n",goods[i].type,goods[i].num); 
	}
    fclose(fp);
    return;
}













