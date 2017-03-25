//
// Created by Administrator on 2016/4/16.
//

int isPrime(int num) {
    int i;

    for (i = 2; i < num; i++){
        if (num % i == 0)
            return 0;
    }