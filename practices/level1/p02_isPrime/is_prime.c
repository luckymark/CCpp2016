#include <stdio.h>
#include <stdlib.h>

int is_prime(int n);

int main()
{
    int num = 0;
    printf("������һ����������");
    scanf("%d",&num);
    if(num<1){
        printf("��������˳�����");
        return 0;
    }
    if(is_prime(num)){
        printf("n������");
    }
    else{
        printf("n��ż��");
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
