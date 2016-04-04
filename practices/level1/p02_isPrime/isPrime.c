#include <stdio.h>

int main(void)
{
    int n;
    scanf("%u", &n);
    if (n==1)
        printf("No");
    else
    {
        for (int i=2;i<=n/2;i++)
		{
            if(n%i==0)
            {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    }
    return 0;
}
