#include <stdio.h>

extern long func(long a, long b, long c);

int main() {
    long a, b, c;
    printf("Podaj trzy liczby: ");
    scanf("%ld %ld %ld", &a, &b, &c);

    long result = func(a, b, c);
    printf("Wynik: %ld\n", result);
    return 0;
}
