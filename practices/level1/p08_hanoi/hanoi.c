#include <stdio.h>
void move(char a,char b,char c,int n)
{
    if(n==1)
        printf("%c to %c\n",a,c);
    else
        {
            move(a,c,b,n-1);
            printf("%c to %c\n",a,c);
            move(b,a,c,n-1);
        }

}
int main()
{
    int n;
    scanf("%d",&n);
    move('A','B','C',n);
    return 0;
}
