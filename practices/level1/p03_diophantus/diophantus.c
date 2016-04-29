#include<stdio.h>
int main()
{
    int dsold = 0,ssold;
    while (1)
    {
        dsold++;
        if ((dsold % 6 != 0) || (dsold % 12 != 0) || (dsold % 7 != 0))        continue;
        ssold = dsold / 2;
        if ((dsold - 4 - dsold / 6 - dsold / 12 - dsold / 7 - 5) == ssold)
        {
            printf("Diophantus's old when his son dead is : %d",dsold - 4);
            break;
        }
    }
    return 0;
}
