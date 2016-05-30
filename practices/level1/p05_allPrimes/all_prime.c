#include <stdio.h>
#include <stdlib.h>

int is_prime(int n);

int main()
{
    printf("2到1000的素数为:\n");
    for(int num = 2;num<=1000;num++){
        if(is_prime(num)){
            printf("%d\n",num);
        }
    }
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
