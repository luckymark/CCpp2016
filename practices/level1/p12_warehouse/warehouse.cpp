#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
enum operNum
{
    dispStock=1,
    inStorage=2,
    outStorage=3,
    exitProduct=4
};
struct Product
{
    string model;
    int total;
};
void dispoperList();
void dispStorageList(vector<Product>cargo);
void inCargo(vector<Product>&cargo);
void outCargo(vector<Product>&cargo);
void saveInfo(vector<Product>cargo);
void initCargo(vector<Product>&cargo,ifstream&In);
int main()
{
    ifstream File("stocklist.txt");
    vector<Product>cargo;
    initCargo(cargo,File);
    File.close();
    while(1)
    {
        dispoperList();
        int oper;
        scanf("%d",&oper);
        switch(oper)
        {
            case dispStock:
                dispStorageList(cargo);
                system("pause");
                break;
            case inStorage:
                inCargo(cargo);
                break;
            case outStorage:
                outCargo(cargo);
                break;
            case exitProduct:
                saveInfo(cargo);
                return 0;
        }
    }
}
void dispoperList()
{
    system("cls");
    printf("1:Display stock list.\n");
    printf("2:Put in storage.\n");
    printf("3:Remove storge.\n");
    printf("4:Exit.\n");
}
void initCargo(vector<Product>&cargo,ifstream&In)
{
    string temp;
    int num;
    while(In>>temp>>num)
    {
        cargo.push_back({temp,num});
    }
}
void dispStorageList(vector<Product>cargo)
{
    for(auto c:cargo)
    {
        printf("%s %d\n",c.model.c_str(),c.total);
    }

}
void inCargo(vector<Product>&cargo)
{
    string temp;
    int num;
    while(cin>>temp>>num)
    {
        cargo.push_back({temp,num});
    }
}
void outCargo(vector<Product>&cargo)
{
    string temp;
    int num;
    dispStorageList(cargo);
    printf("Input cargo's model and removal number like XXX 10");
    while(cin>>temp>>num)
    {
        for(auto iter=cargo.begin();iter!=cargo.end();iter++)
        {
            if(iter->model==temp)
            {
                if(iter->total<num)
                {
                    printf("The number is too large.Please input correctly!\n");
                    continue;
                }
                else
                {
                    iter->total-=num;
                }
                break;
            }
        }
    }
}
void saveInfo(vector<Product>cargo)
{
    freopen("stocklist.txt","w",stdout);
    for(auto c:cargo)
    {
        printf("%s %d\n",c.model.c_str(),c.total);
    }
    fclose(stdout);
}
