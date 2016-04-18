#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void input();
void output();
void print();
void menu();
void end();
int m,n;
int main()
{
    FILE *fpt;
    fpt = fopen("d:\\house.txt","r+");
    fscanf(fpt,"%d\n",&m);
    fscanf(fpt,"%d\n",&n);
    fclose(fpt);
    menu();
    return 0;
}
void print(){

    system("cls");
    printf("存货列表\n");
    printf("物品a %d \t 物品b %d\n",m,n);
    printf("按任意键返回");
    getch();

}
void input(){
    int a,b;
    system("cls");
    printf("输入商品数\n");
    printf("商品a: ");
    scanf("%d",&a);
    m=m+a;
    printf("商品b: ");
    scanf("%d",&b);
    n=n+b;
    printf("按任意键返回");
    getch();

}
void output(){
    int i,j;
    system("cls");
    printf("输出商品\n");
    printf("输出商品a: ");
    scanf("%d",&i);
    m=n-i;
    printf("输出窗口b: ");
    scanf("%d",&j);
    n=n-j;
    printf("按任意键返回");
    getch();
}
void menu(){
    int key;



        while(1){
            system("cls");
            printf("商品清单\n");
            printf("输入编号开始操作\n");
            printf("1.显示列表\n2.输入物品\n3.输出商品\n4.退出系统\n");
            scanf("%d",&key);
            switch(key){
                 case 1:
                        print();
                        break;
                 case 2:
                        input();
                        break;
                 case 3:
                        output();
                        break;
                 case 4:
                        end();
                 default: break;
    }

        }




}
void end(){
    FILE *fpt;
    fpt = fopen("d:\\house.txt","w+");//打开文档，写入
    fprintf(fpt,"%d\n",m);
    fprintf(fpt,"%d",n);
    fclose(fpt);
    exit(0);
}
