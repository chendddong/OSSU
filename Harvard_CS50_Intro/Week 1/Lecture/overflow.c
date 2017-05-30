#include <stdio.h>

int main(void) {
    long long n = 1;
    for (int i = 0; i < 61; i++) {
        // printf("n is %i\n", n); //over flow
        printf("n is %lld\n", n);
        n = n * 2;
    }
}