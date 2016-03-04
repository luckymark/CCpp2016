//
//  Goldpach.cpp
//  Goldpach
//
//  Created by iam24 on 16/3/4.
//  Copyright © 2016年 iam24. All rights reserved.
//
#include <iostream>
#define maxn 100
using namespace std;
bool tag[maxn];
int prime[maxn];
int cnt;
void all_prime(int n)
{
    for (int i = 2 ;i <= n ;i++)
    {
        if (tag[i] == false)
        {
            prime[++cnt] = i;
            int p = i*2;
            while (p <= n)
            {
                tag[p] = true;
                p+=i;
            }
        }
    }
}
bool verification(int n )
{
    for (int i = 4 ;i <= n ;i += 2)
    {
        int flag = 0;
        for (int j = 1 ; j <= cnt ;j++)
            for (int k =1 ;k <= cnt ;k++)
                if (prime[j] + prime[k] == i)
                    flag = 1;
        if (!flag) return false;
    }
    return true;
}
int main()
{
    all_prime(maxn);//先处理出来100内的素数
    if (!verification(maxn)) cout<<"哥德巴赫猜想竟然有错！"<<endl;
        else
            cout<<"经验证，哥德巴赫猜想在"<<maxn<<"范围内正确!"<<endl;
    return 0;
}
