//
//  main.cpp
//  warehouse
//
//  Created by iam24 on 16/3/24.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
const int MAXN = 200;
void show();
bool work();
void show_all_items();
void show_item();
bool is_num()
void into_items();
void out_items();
void prepare();
void finish();
using namespace std;
struct product{
    string name;
    int num;
    int sale;
    int p; //编号
};
int tot;
product data[MAXN];
int main() {
    prepare();
    show();
    while (true)
    {
        if (work() == false)
        {
            finish();
            break;
        }
    }
    return 0;
}
void show()
{
    cout<<"********************"<<endl;
    cout<<"请选择您需要的功能："<<endl;
    cout<<"1 : 显示存货列表"<<endl;
    cout<<"2 : 入库"<<endl;
    cout<<"3 : 出库"<<endl;
    cout<<"4 : 退出程序"<<endl;
    cout<<"5 : 显示菜单"<<endl;
    cout<<"********************"<<endl;
}
bool work()
{
    int option;
    cin>>option;
    switch (option) {
        case 1:
            show_all_items();
            break;
        case 2:
            into_items();
            break;
        case 3:
            out_items();
            break;
        case 4:
            cout<<"再贱_(:з」∠)_"<<endl;
            return false;
        case 5:
            show();
            break;
        default:
            cout<<"好像并没有此项操作_(:з」∠)_"<<endl;
            show();
            break;
    }
    return true;
}
//打印商品
void show_item(int i)
{
    cout<<"商品编号 :"<<i<<endl;
    cout<<"商品名称 :"<<data[i].name.c_str()<<endl;
    cout<<"商品数量 :"<<data[i].num<<endl;
    cout<<"商品价格 :"<<data[i].sale<<endl;
    cout<<endl;
}
//输出所有商品
void show_all_items()
{
    if (tot == 0)
    {
        cout<<"库存商品为空！";
        return ;
    }
    printf("一共有%d件商品！\n",tot);
    for (int i = 1 ;i <= tot ;i++)
    {
        show_item(i);
    }
}
//判断是否是编号
bool is_num(char name[200])
{
    for (int i = 0 ;i <strlen(name) ; i++)
    {
        if (!isdigit(name[i])) return false;
    }
    return true;
}
//入库
void into_items()
{
    cout<<"请输入要加入商品的名称或者编号： "<<endl;
    char name[200];
    int p = tot+1;
    cin>>name;
    if (is_num(name))//如果输入的是编号
    {
        int num = atoi(name);
        if (num > tot) cout<<"没有此编号的商品！_(:з」∠)_"<<endl;
        else
        {
            p = num;
            printf("请确认要改变的商品信息(^o^)/~\n");
            show_item(p);
        }
    }
    else //如果输入的名称
        for (int i = 1 ;i <= tot ;i++)
            {
                if (data[i].name == name)
                {
                    p = i;
                    break;
                }
            }
    if (p == tot+1)
    {
        tot++;
        data[tot].name = name;
        cout<<"此商品为新加入的商品，请完成下列信息："<<endl;
        cout<<"请输入商品的数量 : "<<endl;
        int num;
        cin>>num;
        data[p].num = num;
        cout<<"请输入商品的价格 :"<<endl;
        int sale;
        cin>>sale;
        data[p].sale =sale;
        cout<<"新商品入库完成！ (^o^)/~"<<endl;
    }
    else
    {
        cout<<"请输入商品入库数量 ： "<<endl;
        int num;
        cin>>num;
        data[p].num+=num;
        cout<<"修改完成！(^o^)/~现有商品数量为 : "<<data[p].num<<endl;
        cout<<endl;
    }
    
}
//出库
void out_items()
{
    cout<<"请输入要出库商品的名称或者编号："<<endl;
    char name[200];
    cin>>name;
    int p = tot+1;
    if (is_num(name))//如果输入的是编号
    {
        int num = atoi(name);
        if (num > tot) cout<<"没有此编号的商品！_(:з」∠)_"<<endl;
        else
        {
            p = num;
            printf("请确认要改变的商品信息(^o^)/~\n");
            show_item(p);
        }
    }
    else
        for (int i = 1 ; i<= tot ;i++)
        {
            if (data[i].name  == name)
            {
                p = i ;
                break;
            }
        }
    if (p == tot+1)
    {
        cout<<"没有找到这个商品!_(:з」∠)_"<<endl;
    }
    else
    {
        cout<<"请输入要出库商品的数量："<<endl;
        int num;
        cin>>num;
        if (num > data[p].num)
        {
            cout<<"好像商品数量不足_(:з」∠)_！"<<endl;
        }else
        {
            data[p].num-=num;
            cout<<"商品数量剩余"<<data[p].num<<endl;
        }
    }
}
//读入数据
void prepare()
{
    FILE *fpin;
    fpin = fopen("/Users/iam24/Documents/hello/hello/warehouse/warehouse/data.txt","r");
    fscanf(fpin,"%d",&tot);
    for (int  i  = 1 ; i <= tot ; i++)
    {
        char name[200];
        fscanf(fpin,"%s\n",name);
        for (int j = 0 ; j < strlen(name) ; j++)
        {
            data[i].name[j] = name[j];
        }
        fscanf(fpin,"%d%d%d\n",&data[i].num, &data[i].sale, &data[i].p);
    }
    fclose(fpin);
    //cout<<data[1].name.c_str() ;
}
//退出时保存数据
void finish()
{
    FILE *fout;
    fout = fopen("/Users/iam24/Documents/hello/hello/warehouse/warehouse/data.txt","w");
    fprintf(fout,"%d\n",tot);
    for (int i = 1 ;i <= tot ;i++)
    {
        char name[200] = "";
        for (int j = 0 ; j < data[i].name.length() ; j++)
        {
            name[j] = data[i].name[j] ;
        }
        fprintf(fout, "%s\n",name);
        fprintf(fout,"%d %d %d\n",data[i].num,data[i].sale,data[i].p);

    }
    fclose(fout);
}
