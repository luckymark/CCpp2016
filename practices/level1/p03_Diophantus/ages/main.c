//
//  main.c
//  ages
//
//  Created by 陈浩贤 on 16/2/29.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int totalAge;
    for (totalAge=0;totalAge<200; totalAge++) {
        if (totalAge%12==0&&totalAge%7==0) {
            if (totalAge==totalAge/6+totalAge/12+totalAge/7+totalAge/2+9) {
                printf("age when his son died:%d\n",totalAge-4);
            }
        }
        
    }
    return 0;
}
