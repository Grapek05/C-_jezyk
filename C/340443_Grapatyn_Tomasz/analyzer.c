#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// ANALIZATOR TEKSTU ASCII


typedef enum {
    LENGTH = 'a',
    SQRT_LENGTH = 'b',
    LOG_OF_LENGTH = 'c',
    AVG_VALUE_ASCII = 'd',
    EXIT = 'e',
} Operation;


//enum Operation {
//    DLUGOSC TEKSTU,
//    PIERWIASTEK KWADRATOWY DLUGOSCI TEKSTU,
//    LOGARYTM DZIESIETNY TEKSTU,
//    SREDNIA WARTOSCI KODOW ASCII,
//    WYJSCIE Z PROGRAMU,
//}


typedef struct {
    char* text;
    Operation oper;
} Calculation;


//struct Calculation {
//      char *text;
//      enum Operation oper;
//}


double calc(Calculation* c) {
    int len = strlen(c->text);
    switch (c->oper) {
        case LENGTH:
        return (double)len;
        case SQRT_LENGTH:
        return sqrt((double)len);
        case LOG_OF_LENGTH:
        if (len <= 0) return -1;
        return log10((double)len);
        case AVG_VALUE_ASCII: {
            int sumow = 0;
            for (int i = 0; i < len; i++)
            sumow += (int)c->text[i];
            return (double)sumow / len;
        }
        default:
        return 0.0;
    }
}

int main (int argc, char* argv[]) {
    if (argc <2) {
        printf("Użycie ./analyzer [wpisać ciag kodów ASCII]\n");
        return 1;
    }
    int N = argc - 1;
    char* text = malloc(N +1 );
    if (text == NULL) {
        perror("Bład alokacji pamięci");
    }
    for (int i = 0; i < N; i++)
        text[i] = (char)atoi(argv[i + 1]);
        text[N] = '\0';

        printf("Wczytano tekst: %s\n", text);

        while(1) {
            char oper;
            printf("Podaj operację: ");
            scanf(" %c", &oper);

            if (oper == EXIT) break;

            Calculation c = { text, oper};
            double result = calc(&c);

            if (oper == LOG_OF_LENGTH && result == -1)
                printf("Nie można obliczyć logarytmu z długości 0.\n");
            else
                printf("Wynik: %.4f\n", result);
        }
        
        free(text);
        printf("Koniec programu\n");
        return 0;
}