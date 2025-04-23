// file.c
#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void file_hello(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Błąd otwierania pliku do nadpisania");
        return;
    }
    fprintf(file, "Hello world\n");
    fclose(file);
}

void file_print(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Błąd otwierania pliku do czytania");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void file_append(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Błąd otwierania pliku do dołączenia");
        return;
    }
    fprintf(file, "%s\n", data);
    fclose(file);
}

void file_remove(const char *filename) {
    if (remove(filename) != 0) {
        perror("Błąd usuwania pliku");
    }
}
