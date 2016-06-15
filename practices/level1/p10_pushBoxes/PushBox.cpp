#include<cstdio>
#include<windows.h>

using namespace std;

int nowpx,nowpy;
int nowbx,nowby;
int tobx,toby;
int step=0;

char s[11][11]={"##########",
                "###...s...",
                "#.#.......",
                "#.#.#..b..",
                "#.#.##.#..",
                "#.#.....#.",
                "#####...#.",
                "#..#..###.",
                "..........",
                "###t######",
};

void print()
{
    for (int i=0;i<10;i++)
	{
        for (int j=0;j<10;j++)
		{
            if ((nowpx==i)&&(nowpy==j))
            {
            	printf("p");
            }
                
            else
            {
            	if (nowbx==i && nowby==j)
            	{
	            	printf("b");
	            }
                    
                else
                {
                	printf("%c",s[i][j]);
                }
                    
            }
                
        }
        printf("\n");
    }
    printf("You have walked %d step(s)\n",step);
}

int main()
{
    for (int i=0;i<10;i++)
    {
    	
    
        for (int j=0;j<10;j++)
		{
                if (s[i][j]=='s')
				{
                    nowpx=i;
                    nowpy=j;
                }
                if (s[i][j]=='b')
				{
                    nowbx=i;
                    nowby=j;
                }
        }
    }
    s[nowpx][nowpy]='.';
    s[nowbx][nowby]='.';
    print();
    while (1)
	{
            char tmp[200];
            int tox,toy;
            tobx=nowbx;
            toby=nowby;
            scanf("%s",tmp);
            system("cls");
            if (!((tmp[0]=='w')||(tmp[0]=='s')||(tmp[0]=='a')||(tmp[0]=='d'))||(strlen(tmp)>=2))
			{
                print();
                printf("Filed\nYou can't move like this\n");
                continue;
            }
            if (tmp[0]=='w')
			{
                tox=nowpx-1;
                toy=nowpy;
                if (tox==nowbx && toy==nowby)
				{
                        tobx=nowbx-1;
                        toby=nowby;
                }
            }
            if (tmp[0]=='s')
			{
                tox=nowpx+1;
                toy=nowpy;
                if (tox==nowbx && toy==nowby)
				{
                        tobx=nowbx+1;
                        toby=nowby;
                }
            }
            if (tmp[0]=='a')
			{
                tox=nowpx;
                toy=nowpy-1;
                if (tox==nowbx && toy==nowby)
				{
                        tobx=nowbx;
                        toby=nowby-1;
                }
            }
            if (tmp[0]=='d')
			{
                tox=nowpx;
                toy=nowpy+1;
                if (tox==nowbx && toy==nowby)
				{
                        tobx=nowbx;
                        toby=nowby+1;
                }
            }
            if ((tox<0)||(toy>=10)||(tox>=10)||(toy<0))
			{
                print();
                printf("Filed\nYou can't go out the map\n");
                continue;
            }
            if ((tobx<0)||(toby>=10)||(tobx>=10)||(toby<0))
			{
                print();
                printf("Filed\nYou can't go out the map\n");
                continue;
            }
            if (s[tox][toy]=='#'){
                print();
                printf("Filed\nYou can't go to the point\n");
                continue;
            }
            if (s[tobx][toby]=='#')
			{
                print();
                printf("Filed\nBox can't go to the point\n");
                continue;
            }
            nowpx=tox;
            nowpy=toy;
            nowbx=tobx;
            nowby=toby;
            step++;
            if (s[nowbx][nowby]=='t')
			{
                printf("Succeed!\n");
                printf("You have walked %d step(s)\n",step);
                return 0;
            }
            print();
    }
    return 0;
}