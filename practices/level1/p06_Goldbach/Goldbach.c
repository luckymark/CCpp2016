#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a[101]={0,0,1};                         //a[i]=1��ʾiΪ����
    int n,i,k,j;
    for(i=3;i<=100;i++){
        k=0;
        n=(int)sqrt(i);
        for(j=2;j<=n;j++){
            if(i%j==0){
                k=1;                            //k=1��ʾ������������
                break;
            }
        }
        if(k==0){
            a[i]=1;                             // ��k==0��ʾͨ�����Լ��Ϊ����
        }
    }
    n=0;
    for(i=4;i<=100;i+=2){
        for(j=2;j<=100;j++){
            if(a[j]==0||a[i-j]==0){
                continue;
            }else{
                n+=1;
                break;
            }
        }
    }
    if(n==49){
        printf("yes!(form 1 to 100)");
    }
    return 0;
}
