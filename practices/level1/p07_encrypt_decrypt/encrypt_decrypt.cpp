#include <cstdio>
#include <iostream>
#define KEY 101
using namespace std;
void DcruptFunction(istream& In);
void EcruptFunction(istream& In);
int main()
{
    printf("Ecrupt or Dcrupt?Input 1 or 2\n");
    int Oper;
    scanf("%d",&Oper);
    if(Oper==1)
    {
        printf("Please input the text which you want to Ecrupt:\n");
        EcruptFunction(cin);
    }
    else if(Oper==2)
    {
        printf("Please input the text which you want to Dcrupt:\n");
        DcruptFunction(cin);
    }
    return 0;
}
void EcruptFunction(istream& In)
{
    char c;
    while(In>>c)
    {
        c^=KEY;
        printf("%c",c);
    }

}
void DcruptFunction(istream& In)
{
    char c;
    while(In>>c)
    {
        c^=KEY;
        printf("%c",c);
    }
}
