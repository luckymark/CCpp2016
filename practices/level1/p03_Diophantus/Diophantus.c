#include<stdio.h>

int main()
{
    for(float fage=20;fage<130;fage++)
    {
        float sage=fage-fage/6-fage/12-fage/7-5-4;
        if( fage==2*sage)
        printf("Diophantus was %.0f when his son died.",fage-4);
    }
    return 0;
}
