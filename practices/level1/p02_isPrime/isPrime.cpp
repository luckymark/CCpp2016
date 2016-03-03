//
//  main.cpp
//  is_prime
//
//  Created by iam24 on 16/2/29.
//  Copyright © 2016年 iam24. All rights reserved.
//
#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int n)
{
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    int sqrt_n = int (sqrt(n));
    for (int i = 2; i <= sqrt_n ;i++)
        if (n % i == 0) return false;
    return true;
}int main()
{
    int n;
    cout<<"请输入要判断的正整数:";
    cin>>n;
    if (is_prime(n))
        cout<<"YES,It's a prime!";
    else
        cout<<"NO,it is not a prime!";
}
