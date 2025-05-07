#include <stdio.h>

extern long asmpow(long x, long n);
extern double asmpowd(double x, long n);

int main() {
    long x = 4;
    long n = 3;

    printf("%ld^%ld = %ld\n", x, n, asmpow(x, n));
    printf("%f\n", asmpowd(x, n));


    return 0;
}
