#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void cmdReset(bool scroll) {
    if (scroll) printf("\033c");
    else printf("\x1B[2J\x1B[H");
}

// Kolory :>
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"
#define ERROR_COLOR "\033[31m"
#define SUCCESS_COLOR "\033[32m"

struct Task {
    char *name;
    struct Task *next;
};

struct Task *head = NULL;
struct Task *tail = NULL;

struct Task* task_new(const char *name) {
    struct Task *new_task = malloc(sizeof(struct Task));
    if (!new_task) {
        fprintf(stderr, ERROR_COLOR "Błąd alokacji pamięci\n" RESET_COLOR);
        return NULL;
    }
    
    new_task->name = strdup(name);
    if (!new_task->name) {
        free(new_task);
        fprintf(stderr, ERROR_COLOR "Błąd alokacji pamięci dla nazwy zadania\n" RESET_COLOR);
        return NULL;
    }
    
    new_task->next = NULL;
    return new_task;
}

void task_free(struct Task *task) {
    if(task) {
        free(task->name);
        free(task);
    }
}

void add_task(const char *name) {
    struct Task *new_task = task_new(name);
    if (!new_task) {
        return;
    }

    if (!head) {
        head = tail = new_task;
    } else {
        tail->next = new_task;
        tail = new_task;
    }
    printf(SUCCESS_COLOR "Dodano zadanie: %s\n" RESET_COLOR, name);
}

void list_tasks(bool text) {
    struct Task *current = head;
    if (!head) {
        printf("Brak zadań\n\n");
        return;
    }
    if (text) printf("Zadania:\n");
    while (current) {
        printf("- %s\n", current->name);
        current = current->next;
    }
    printf("\n");
}

void remove_first_task() {
    if (!head) {
        printf(ERROR_COLOR "Brak zadań\n" RESET_COLOR);
        return;
    }

    struct Task *temp = head;
    printf(SUCCESS_COLOR "Usunięto zadanie: %s\n" RESET_COLOR, temp->name);

    head = head->next;
    if (!head) {
        tail = NULL;
    }

    task_free(temp);

    list_tasks(false);
}

int main() {
    char *line = NULL;
    size_t len = 0;
    size_t read;

    while (1) {
        printf(BLUE_COLOR "1." RESET_COLOR "Wyświetl wszystkie zadania.\n");
        printf(GREEN_COLOR "2." RESET_COLOR "Dodaj nowiutkie zadania\n");
        printf(YELLOW_COLOR "3." RESET_COLOR "Usuwanie zadania z początku kolejki\n");
        printf(RED_COLOR "4." RESET_COLOR "Zakończ program\n");
        printf("\n\nWybierz:");
        fflush(stdout);
        read = getline(&line, &len, stdin);
        if (read == -1) break;
        if (line[read - 1] == '\n') line[read - 1] = '\0';
        
        if (strcmp(line, "1") == 0) {
            cmdReset(true);
            list_tasks(true);
        } else if (strcmp(line, "2") == 0) {
            while (1) {
                printf("Nazwa zadania: ");
                read = getline(&line, &len, stdin);
                if (read == -1) break;
                if (line[read - 1] == '\n') line[read - 1] = '\0';
                if (*line) {
                    add_task(line);
                    cmdReset(true);
                    break;
                } else {
                    printf(ERROR_COLOR "Brak nazwy zadania\n" RESET_COLOR);
                }
            }
        } else if (strcmp(line, "3") == 0) {
            cmdReset(true);
            remove_first_task();
            printf("\n");
        } else if (strcmp(line, "4") == 0) {
            break;
        } else {
            cmdReset(true);
            printf(ERROR_COLOR "Nieznana komenda: %s\n" RESET_COLOR, line);
            printf("\n");
        }
    }

    free(line);

    struct Task *current = head;
    while (current) {
        struct Task *temp = current;
        current = current->next;
        task_free(temp);
    }
    head = tail = NULL;

    return 0;
}
