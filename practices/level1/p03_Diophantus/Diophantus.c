#include<stdio.h>
int main()
{
    float fage,sage;
    for(fage=20;fage<130;fage++)
    {
        sage=fage-fage/6-fage/12-fage/7-5-4;
        if(fage==2*sage)
        printf("Diophantus was %.0f when his son died.",fage-4);
    }
    return 0;
}
