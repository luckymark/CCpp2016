#include <stdio.h>
#include <stdlib.h>

int main()
{
    float age;
    for(age=1;age<=500;age++)
    {
        if(age/2==age/6+age/12+age/7+9)
        {
            printf("%f\n",age);
        }
    }
    return 0;
}
