#include<iostream>
#include<cstring>
using namespace std;
int num[12];
int main()
{
    cout << "三位水仙花数有："<<endl;
    for (int i = 0; i <= 9;i++)
    {
        num[i] =1;
        for (int j = 1; j<= 3;j++)
            num[i] = num[i]*i;
    }
    for (int i= 100; i<= 999 ;i++)
    {
        int tot=0;
        int n=i;
        for (int j =1;j <=3 ;j++)
        {
            int a = n % 10;
            n = n/10;
            tot+=num[a];
        }
        if (tot == i) cout<<i<<endl;
    }
    return 0;
}