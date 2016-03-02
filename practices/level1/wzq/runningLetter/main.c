#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i;
    char c='A';
    for(i=0;i<156;i++){
        printf("%*c",(int)fabs(78-(int)fabs(i-78)),c);
        system("cls");
    }
    return 0;
}
