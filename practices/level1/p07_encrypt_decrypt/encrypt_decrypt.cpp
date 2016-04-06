#include <cstdio>
#include <iostream>
#include <cstring>
#define KEY 101
using namespace std;
void fcruptFunction(char *s,int len);
void ecruptFunction(char *s,int len);
int main()
{
    printf("Ecrupt or Dcrupt?Input 1 or 2\n");
    int oper;
    char s[100];
    scanf("%d",&oper);
    if(oper==1)
    {
        printf("Please input the text which you want to Ecrupt:\n");
        gets(s);
        ecruptFunction(s,strlen(s));
    }
    else if(oper==2)
    {
        printf("Please input the text which you want to Dcrupt:\n");
        gets(s);
        fcruptFunction(s,strlen(s));
    }
    return 0;
}
void ecruptFunction(char *s,int len)
{
    for(int i=0;i<len;i++)
    {
        s[i]^=KEY;
    }
    puts(s);
}
void fcruptFunction(char *s,int len)
{
    for(int i=0;i<len;i++)
    {
        s[i]^=KEY;
    }
    puts(s);
}
