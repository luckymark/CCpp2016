#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define swap(a, b, type) {type ___tem_ = a; a = b; b = ___tem_;}
#define LENGTH 10000
#define DISPLAYLENGTH 10

int* bubble_sort(int a[], int start, int end) {
    if (start == end) {
        return a;
    } else {
        for (size_t i = start; i < end; i++) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1], int);
            }
        }
        bubble_sort(a, start, end - 1);
        return a;
    }
}


void time_test(int *a, int length) {
    printf("******************************\n******************************\n");
    printf("The array is:\n{");
    for (size_t i = 0; i < DISPLAYLENGTH; i++) {
        printf("%d%s", a[i], (i == DISPLAYLENGTH - 1) ? " ...}\n" : ", ");
    }
    printf("Length of array is %d\n", length);
    size_t start, end, during;
    start = clock();
    bubble_sort(a, 0, length - 1);
    end = clock();
    during = end - start;
    printf("It costed %lf sec.\n", (double) during / CLOCKS_PER_SEC);
}

void test_with_func_of_array(int (*func)(int), int length) {
    int a[length];
    for (size_t i = 0; i < length; i++) {
        a[i] = func(i);
    }
    time_test(a, length);
}

int natural_num_generator(int n) {
    return n;
}

int reverse_nartural_num_generator(int n) {
    return LENGTH - n - 1;
}

int random_num_generator(int n) {
    return rand() % LENGTH;
}

int main(int argc, char const *argv[]) {
    int (*array_generator[])(int) = {natural_num_generator,
                                     reverse_nartural_num_generator,
                                     random_num_generator};
    for (size_t i = 0;
        i < sizeof(array_generator) / sizeof(array_generator[0]);
        i++) {
        test_with_func_of_array(array_generator[i], LENGTH);
    }
    for (size_t i = 10; i < LENGTH; i *= 10) {
        test_with_func_of_array(natural_num_generator, i);
    }
    return 0;
}
