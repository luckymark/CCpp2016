//
//  encrypt_decrypt.cpp
//  encrypt_decrypt
//
//  Created by iam24 on 16/3/6.
//  Copyright © 2016年 iam24. All rights reserved.
//
#include <iostream>
#include <cstring>
const int luck_number = 4;
using namespace std;
void encrypt(string str);
void decrypt(string str);
void prepare();
int main()
{
    prepare();
    return 0 ;
}
void prepare()
{
    string str;
    cout<<"请输入要操作的字符串\n";
    cin>>str;
    cout<<"请选择你要使用的功能：\n";
    cout<<"输入1：加密\n";
    cout<<"输入2：解密\n";
    int option;
    cin>>option;
    if (option == 1)
    {
        encrypt(str);
    }
    else{
        decrypt(str);
    }
}
void encrypt(string str)
{
    cout<<"加密结果如下："<<endl;
    for (int i = 0; i < str.size(); i++)
        cout<<char(int(str[i])+luck_number);
    cout<<endl;
    
}
void decrypt(string str)
{
    cout<<"解密结果如下："<<endl;
    for (int i = 0; i < str.size(); i++)
        cout<<char(int(str[i])-luck_number);
    cout<<endl;
}
