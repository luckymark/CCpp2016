#include <stdio.h>
#include <stdlib.h>

#define max_age 200

main()
{
float year;
    for(year=0;year<max_age;year++){
        if((year/12+year/6+year/7+5+year/2+4)==year){
        printf("¶ª·¬Í¼µÄÄêÁäÊÇ%.0fËê\n",year);
        break;
        }
    }
}
