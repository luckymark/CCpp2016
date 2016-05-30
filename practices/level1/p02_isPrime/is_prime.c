#include <stdio.h>
#include <stdlib.h>

int is_prime(int n);

int main()
{
    int num = 0;
    printf("请输入一个正整数：");
    scanf("%d",&num);
    if(num<1){
        printf("输入错误，退出程序");
        return 0;
    }
    if(is_prime(num)){
        printf("n是素数");
    }
    else{
        printf("n是偶数");
    }
    return 0;
}

int is_prime(int n)
{
    for(int i = 2;i*i<=n;i++){
        if(n % i ==0){
            return 0;
        }
    }
    return 1;
}
