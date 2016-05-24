#include<stdio.h>
#define targ1 6 - from - target
int move(int n,int from,int target);
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",move(n,1,3));
    return 0;
}
int move(int n,int from,int target)
{
    int ans = 0;
    if (n == 1)
    {
        printf("1  %d -> %d \n",from,target);
        return 1;
    }
    ans += move(n - 1,from,targ1);
    printf("%d  %d -> %d \n",n,from,target);
    ans += move(n - 1,targ1,target) + 1;
    return ans;
}
