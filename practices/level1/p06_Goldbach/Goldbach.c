#include <stdio.h>

#define max 100

int is_prime(int n);
int goldbach(int maxnum);

int main()
{
    if(goldbach(max)){
        printf("������ȷ");
    }
    else{
        printf("���벻��ȷ");
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

int goldbach(int maxnum){
    for(int i=4;i<=maxnum;i++){
        if(i%2==0){
            for(int j=2;j*j<i;j++){
                if(is_prime(j)&&is_prime(i-j)){  //��2����ѭ��������������������ж��������Ƿ�������
                    return 1;
                }
            }
        }
    }
    return 0;
}
