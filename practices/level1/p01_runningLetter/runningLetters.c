#include <stdio.h>
#define screen_length 110
int abs(int num1,int num2);
void running(char letters[],int length);
int main()
{
    char str[20]="runing_man";
    running(str,screen_length);
    return 0;
}

int abs(num1,num2)
{
    if(num1-num2<=0)
    {
        return num2-num1;
    }
    else
    {
        return num1-num2;
    }
}

void running(char letters[],int length)
{
        while(1)
    {
        for(int i=0;i<2*length;i++)
        {
            system("cls");
            for(int j=abs(i,length);j>0;j--)
            {
                printf(" ");
            }
            printf("%s",letters);
        }
    }
}
