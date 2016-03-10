#include<iostream>
#include<cstring>
using namespace std;
void hano_tower(char a, char b, char c, int p)
{
    if (p == 1)
    {
        printf("%c->%c\n",a,c);
        return ;
    }
    hano_tower(a, c, b, p-1);
    printf("%c->%c\n",a,c);
    hano_tower(b, a, c, p-1);
}
int main()
{
    int n ;
    cout<<"请输入盘子数量："<<endl;
    cin>>n;
    hano_tower('A', 'B', 'C', n);
    return 0;
}