// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define FILENAME "content.txt"

int main() {
    file_hello(FILENAME);

    int choice;
    char data[256];

    while (1) {
        printf("\nWybierz opcję:\n");
        printf("1. Odczytaj plik\n");
        printf("2. Dopisz do pliku\n");
        printf("3. Wyjdź\n");
        printf("Twoja opcja: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\nZawartość pliku:\n");
                file_print(FILENAME);
                break;
            case 2:
                printf("Wpisz tekst do dopisania: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0';
                file_append(FILENAME, data);
                break;
            case 3:
                file_remove(FILENAME);
                printf("Plik usunięty. Zakończenie programu.\n");
                return 0;
            default:
                printf("Nieprawidłowa opcja. Spróbuj ponownie.\n");
                break;
        }
    }

    return 0;
}
