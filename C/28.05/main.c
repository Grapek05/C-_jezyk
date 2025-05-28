#include <stdio.h>
#include <stdlib.h>

extern int asm_min(int *tab, int count);
extern int asm_max(int *tab, int count);

int main() {
    int n;

    printf("Ile liczb chcesz wrzucić? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Błędna liczba elementów\n");
        return 1;
    }

    int *tab = malloc(n * sizeof(int));
    if (!tab) {
        fprintf(stderr, "Brak pamięci\n");
        return 1;
    }

    printf("Wczytaj %d liczb:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &tab[i]) != 1) {
            fprintf(stderr, "Błąd podczas wczytywania elementu %d\n", i + 1);
            free(tab);
            return 1;
        }
    }

    int min = asm_min(tab, n);
    int max = asm_max(tab, n);

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    free(tab);
    return 0;
}
