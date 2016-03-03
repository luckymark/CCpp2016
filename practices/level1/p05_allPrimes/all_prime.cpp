//
//  main.cpp
//  all_prime
//
//  Created by iam24 on 16/3/3.
//  Copyright © 2016年 iam24. All rights reserved.
//
#include <iostream>
#include <time.h>
#define maxn 1050
using namespace std;
bool tag[maxn];
void all_prime(int n)
{
    for (int i = 2 ;i <= n ;i++)
    {
        if (tag[i] == false)
        {
            int p = i*2;
            while (p <= n)
            {
                tag[p] = true;
                p+=i;
            }
        }
    }
    cout << "2-1000所有的素数是:"<<endl;
    for (int i = 2 ;i <= n ;i++)
        if (tag[i] == false)
            cout<<i<<" ";
    cout<<endl;
}
using namespace std;
int main()
{
    clock_t cstart,cends;
    cstart=clock();
    int n = 1000;
    all_prime(n);
    cends=clock();
    cout<<"使用时间:";
    cout << cends-cstart << endl;
    return 0;
}
