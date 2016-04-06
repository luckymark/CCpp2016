#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define lens 156
int main()
{
    int i;
    char c='A';
    for(i=0;i<lens;i++){
        printf("%*c",(int)fabs(lens/2-(int)fabs(i-lens/2)),c);
        system("cls");
    }
    return 0;
}
