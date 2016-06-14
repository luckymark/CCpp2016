#include <stdio.h>

int goldBach(int x);

int main(void) {
    for(int i=4;i<= 100 ; i += 2) {
        if(goldBach(i)) {
            printf("%d Correct\n",i);
        }
        else {
            printf("%d Wrong",i);
            return 0;
        }
    }
    return 0;
}

int goldBach(int x) {
    int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(int i=0;i<=24;i++) {
        for(int j=0;j<=24;j++) {
            if(x== prime[i]+prime[j]) {
                return 1;
            }
        }
    }
    return 0;
}