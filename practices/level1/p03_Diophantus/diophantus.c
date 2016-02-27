#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int lcm_array(int a[], int length) {
    if (length == 2) {
        return lcm(a[0], a[1]);
    } else {
        return lcm(lcm_array(a + 1, length - 1), a[0]);
    }
}

int main(int argc, char const *argv[]) {
    int array[] = {6, 12, 7};
    int year = lcm_array(array, 3);
    printf("Diophantus is %d years old.\n", year);
    return 0;
}
