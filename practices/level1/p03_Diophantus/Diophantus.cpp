//
//  main.cpp
//  Diophantus
//
//  Created by iam24 on 16/2/29.
//  Copyright © 2016年 iam24. All rights reserved.
//
#include <iostream>
bool can(int n);
using namespace std;
int main()
{
    for ( int i = 10 ;i <= 200 ;i++)
    {
        if (can(i))//验证可行性
        {
            cout<<"he was "<<i<<" years old when he died."<<endl;
            return 0;
        }
    }
    return 0;
}
bool can(int n)
{
    if (n & 1) return false;
    if (n % 6 || n % 12 || n % 7) return false;
    int son = n / 2;
    int tot = n/12 + n/7 + n/6;
    if (tot == (n-son-5-4)) return true;
    return false;
}
